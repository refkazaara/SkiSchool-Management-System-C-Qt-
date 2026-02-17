#include "skischool.h"

// Hilfsfunktion für die Umwandlung von Level zu Text
std::string levelToText(Level l) {
    switch(l) {
        case Level::BEGINNER:     return "BEGINNER";
        case Level::INTERMEDIATE: return "INTERMEDIATE";
        case Level::ADVANCED:     return "ADVANCED";
        case Level::EXPERT:       return "EXPERT";
        default:                  return "UNKNOWN";
    }
}

// Hilfsfunktion für die Umwandlung von Skill zu Text
std::string typeToText(Skill s) {
    switch(s) {
        case Skill::SKI:   return "SKI";
        case Skill::SNOWBOARD: return "SNOWBOARD";
        case Skill::BOTH:  return "BOTH";
        default:           return "UNKNOWN";
    }
}


SkiSchool::SkiSchool()
{
    if(!teachers.empty()) {
        courses[1] = new Course(Level::BEGINNER, Skill::SKI, teachers[0]);
            courses[2] = new Course(Level::BEGINNER, Skill::SKI, teachers[1]);
            courses[3] = new Course(Level::INTERMEDIATE, Skill::SKI, teachers[2]);
            courses[4] = new Course(Level::ADVANCED, Skill::SKI, teachers[3]);
}
}
//void SkiSchool::userDialog()
//{
//    while(true){
//        int selection;
//        std::cout << "1: Daten lesen" << std::endl;
//        std::cout << "2: Kurs anlegen" << std::endl;
//        std::cout<<"3:Schueler auf Kurse verteilen"<<endl;
//        std::cout<<"4: Kursuebersicht ausgeben"<<endl;
//        std::cout << "0: Programm beenden" << std::endl;
//        std::cin >> selection;

//        switch(selection){
//        case 1:
//            readStudentFile("Students.txt");

//            break;
//        case 2:
//            createCourse();
//            break;
//        case 3:
//            distributeStudents();
//            break;
//        case 4:
//            showAllcourses();
//            break;

//        case 0:
//            cout<<"beendet"<<endl;
//            exit(0);
//            return;

//        default:
//            cout<<"ungueltige Eingabe !"<<endl;
//            break;
//        }
//    }
//}

std::vector<Student *> SkiSchool::getStudents() const
{
    return students;
}

void SkiSchool::readStudentFile(std::string filename) {

    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
    students.clear();

    ifstream datei(filename);
    if (!datei.is_open()) {
        cout << "Fehler: Datei nicht gefunden!" << endl;
        return;
    }

    string zeile;
    int zeilenNummer = 0;


    try {
        while (getline(datei, zeile)) {
            zeilenNummer++;

            stringstream ss(zeile);
            string nachname, vorname, lvlStr, sprachenStr, skillStr;

            getline(ss, nachname, '|');
            getline(ss, vorname, '|');
            getline(ss, lvlStr, '|');
            getline(ss, sprachenStr, '|');
            getline(ss, skillStr, '|');


            if(nachname.empty() || vorname.empty() || lvlStr.empty() || sprachenStr.empty() || skillStr.empty())
                throw zeilenNummer;



            Level lvl = static_cast<Level>(stoi(lvlStr));
            Skill sk = static_cast<Skill>(stoi(skillStr));



            std::set<Language> sprachen;
            for (int i = 0; i < (int)sprachenStr.length(); i++) {
                int sprachenZahl = sprachenStr[i] - '0';
                sprachen.insert(static_cast<Language>(sprachenZahl));
            }


            Student *student=new Student (nachname,vorname,lvl,sk,sprachen);
            students.push_back(student);
        }
        cout << students.size() << " Studenten geladen!" << endl;

    }

    catch (int fehlerZeile) {
        cout << "Fehler in Zeile " << fehlerZeile << "! Einlesen abgebrochen." << endl;
        for (int i = 0; i < students.size(); i++) {
            delete students[i];
        }
        students.clear();
        // Info für den User:
        cout << "Bitte korrigieren Sie die Datei und waehlen Sie erneut Punkt 1." << endl;
    }
    catch (const exception& e) {
        // WICHTIG: Auch hier aufräumen, falls vor dem Fehler schon Studenten geladen wurden  um sicherzustellen, dass keine inkonsistenten oder doppelten Datensätze verbleiben
        cout << "Datenfehler: " << e.what() << " in Zeile " << zeilenNummer << endl;
                for (int i = 0; i < students.size(); i++) {
                    delete students[i];
                }
                students.clear();
                cout << "Bitte korrigieren Sie die Datei und waehlen Sie erneut Punkt 1." << endl;
    }

    datei.close();
}
void SkiSchool::createCourse() {
    int art, lvl, lNr,kId;
    cout << "ID des neuen Kurses? ";
    cin >> kId;
    while (true) {
            cout << "Art des Kurses? (0: SKI, 1: SNOWBOARD)" << endl;
            cin >> art;               //art = type
            if (cin.fail()) { // Falls der User einen Buchstaben eingibt
                cout << "Fehler: Bitte eine Zahl eingeben!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (art == 0 || art == 1) {
                break; // Korrekte Eingabe, raus aus der Schleife
            } else {
                cout << "Ungueltige Art! Bitte nur 0 oder 1." << endl;
            }
        }
    while (true) {
        cout << "Level des Kurses? (0: BEGINNER, 1: INTERMEDIATE, 2: ADVANCED, 3: EXPERT)" << endl;
        cin >> lvl;

        // 1. Schritt: Prüfen, ob die Eingabe überhaupt eine Zahl war
        if (cin.fail()) {
            cout << "Fehler: Das war keine Zahl! Bitte versuchen Sie es erneut." << endl;
            cin.clear();            // Fehler-Status löschen
            cin.ignore(1000, '\n'); // Den "Müll" (z.B. Buchstaben) aus dem Speicher werfen
            continue;               // Springe zurück zum Anfang der Schleife
        }

        // 2. Schritt: Prüfen, ob die Zahl im richtigen Bereich (0-3) liegt
        if (lvl >= 0 && lvl <= 3) {
            break; // Alles okay, wir können die Schleife verlassen
        } else {
            cout << "Ungueltiges Level! Bitte nur 0 bis 3 eingeben." << endl;
            // Hier kein continue nötig, da wir am Ende der Schleife sind
        }
    }

    Teacher* t = nullptr;
    cout<<"Geben Sie die Nummer der Lehrerin ein"<<endl;

    while (true) {

        cin >> lNr;

        // 1. SCHRITT: Lehrerin suchen (Vektor -> [i] ist okay!)
        t = nullptr; // Reset, falls die Schleife öfter läuft
        for (int i = 0; i < teachers.size(); i++) {
            if (teachers[i]->getId() == lNr) {
                t = teachers[i];
                break;
            }
        }

        if (t == nullptr) {
            cout << "Es existiert keine Lehrerin mit dieser Nummer. Waehlen Sie eine andere Lehrerin:" << endl;
            continue;
        }


        // 1. Check: Ist sie erfahren genug für Level 2 und 3?
        if (lvl >= 2 && t->getSeniority() != Seniority::SENIOR) {
            cout << "Zu wenig Erfahrung fuer dieses Level!" << endl;
            continue;
        }

        // 2. Check: Kann sie die Sportart?
        if (art == 0 && t->getMySkill() == Skill::SNOWBOARD) { // Will Ski, sie kann nur Board
            cout << "Falsche Sportart!" << endl;
            continue;
        }
        if (art == 1 && t->getMySkill() == Skill::SKI) { // Will Board, sie kann nur Ski
            cout << "Falsche Sportart!" << endl;
            continue;
        }


        bool schonBelegt = false;

        //Qmap//Gehe alle Kurse durch und schau, ob eine Lehrerin diese ID hat
        for (auto it = courses.begin(); it != courses.end(); ++it) {
            if (it->second->getTeacher()->getId() == lNr) {   // it->first  ist die Kurs-ID (long)  it->second ist der Course*
                schonBelegt = true;
                break;
            }
        }

        if (schonBelegt) {
            cout << "Diese Lehrerin ist bereits ausgebucht. Waehlen Sie eine andere Lehrerin:" << endl;
            continue;
        }
        break;
    }

    /// Erst umwandeln (Casting)
    Level kursLevel = static_cast<Level>(lvl);
    Skill kursSkill = static_cast<Skill>(art);

    // Dann ganz entspannt speichern
    courses[kId] = new Course(kursLevel, kursSkill, t);

    cout << "Kurs mit der ID " << kId << " wurde fuer Lehrer*in " << t->getLastName() << " angelegt" << endl;
}
//-------------------------------AUFGABE 2------------------------------------//
void SkiSchool::distributeStudents()
{
//ein Schüler nicht mehrfach zugeteilt werden, wenn die Methode distributeStudents mehrfach aufgerufen wird
//mit .clear() nur die Kopie löschen  aber im echten Kurs ändert sich nichts
//lösung: in Klasse Course eine extra Methode clearStudents().

    for (auto it = courses.begin(); it != courses.end(); ++it)
    {
       it->second->clearStudents();   //--------AUFGABE 2 B-------//
    }

    waitingList.clear();

    int zugeordnetCount = 0;


    for (Student* s : students)   // ÄUSSERE SCHLEIFE: alle Schüler
    {
        bool zugeordnet = false;

        for (auto it = courses.begin(); it != courses.end(); ++it)   // INNERE SCHLEIFE: alle Kurse
        {
            Course* c =it->second ;

            if (c->getLevel() == s->getOwnLevel() &&
                            c->getType() == s->getRequestedSkill() &&
                            c->getStudents().size() < c->getGroupSize())
                        {
                            c->addStudent(s);
                            zugeordnetCount++;
                            zugeordnet = true;
                            break; // Nächster Schüler               // wichtig: nicht weiter suchen
        }
        }

        if (!zugeordnet)
                {
                    waitingList.push_back(s); // Ab auf die Warteliste
                }
    }

    cout << "Verteilung abgeschlossen. Zugeordnet: " << zugeordnetCount
             << " | Warteliste: " << waitingList.size() << endl;

}
////-------------------------------AUFGABE 3 ohne qt------------------------------------//
//void SkiSchool::showAllcourses()
//{
//    // 1) Kurse (ID + Pointer) in einen Standard-Vektor kopieren
//        std::vector<std::pair<long, Course*>> list;           // Container erstellen der eine Liste von Pärchen speichert
//        list.reserve(courses.size());                         // genau so viele Elemente in courses reservieren

//        for (auto it = courses.begin(); it != courses.end(); ++it)     //kopieren
//            list.push_back(std::make_pair(it->first, it->second));

//        // 2) Sortieren nach Lehrer-Nachname (aufsteigend)
//        std::sort(list.begin(), list.end(),
//                  [](const std::pair<long, Course*>& a, const std::pair<long, Course*>& b) {
//            //  Daten holen:
//                      const std::string & la = a.second->getTeacher()->getLastName();
//                      const std::string & lb = b.second->getTeacher()->getLastName();
//            // Der Vergleich:
//                      if (la == lb) return a.first < b.first;   //  zwei Lehrer denselben Nachnamen(tie-break)-> Kurs-ID vergleichen
//                      return la < lb;
//                  });

//        // 3) Ausgeben (pro Kurs: Schüler nach Nachname sortieren)
//        for (const auto& entry : list)
//        {
//            //Daten vorbereiten
//            long kursId = entry.first;
//            Course* c = entry.second;
//            Teacher* t = c->getTeacher();

//            //Die Ausgabe des Kurses
//            cout << "Kurs " << kursId << "\n";
//            cout << t->getFirstName()<< " " << t->getLastName()<< "\n";
//            cout << levelToText(c->getLevel()) << " "<< typeToText(c->getType()) << "\n";

//            //Die Schüler-Sortierung
//            cout << "Schueler:\n";
//            std::vector<Student*> st = c->getStudents(); // Schüler des aktuellen Kurses holen

//            // Sortieren nach SChüler-Nachname (aufsteigend)
//            std::sort(st.begin(), st.end(),
//                      [](Student* a, Student* b) {
//                          if (a->getLastName() == b->getLastName())   return a->getFirstName() < b->getFirstName();    //tie break

//                          return a->getLastName() < b->getLastName();
//                      });
//            //Ausgabe:
//            for (Student* s : st)
//                cout << s->getLastName()<< ", " << s->getFirstName()<< "\n";

//        }
//}

// 1. Kurs A (Lehrer mit A am Anfang)

//          Schüler von A-Z

// 2. Kurs B (Lehrer mit B am Anfang)

//          Schüler von A-Z
//...und so weiter.


//-------------------------------AUFGABE 4  mit qt------------------------------------//
QString SkiSchool::showAllCourses()
{
    QString str = "<div style='font-size: 13pt; font-family: Arial, sans-serif;'>";

    // 1) Kurse in Vektor kopieren
    std::vector<std::pair<long, Course*>> list;
    for (auto const& [id, c] : courses) {
        if (c != nullptr) list.push_back({id, c});
    }

    // 2) NEUE SORTIERUNG: Nach Kurs-ID (aufsteigend)
    std::sort(list.begin(), list.end(), [](const std::pair<long, Course*>& a, const std::pair<long, Course*>& b) {
        return a.first < b.first;
    });

    // 3) Die Ausgabe der Kurse
    for (const auto& entry : list)
    {
        Course* c = entry.second;
        Teacher* t = c->getTeacher();
        if (!c || !t) continue;

        str += "<h2 style='color: #2E86C1; margin-bottom: 5px;'>Kurs " + QString::number(entry.first) + "</h2>";
        str += "<b>Lehrer:</b> " + QString::fromStdString(t->getFirstName()) + " " + QString::fromStdString(t->getLastName()) + "<br>";
        str += "<i>" + QString::fromStdString(levelToText(c->getLevel())) + " " + QString::fromStdString(typeToText(c->getType())) + "</i><br>";

        str += "<p style='margin-bottom: 2px;'><b>Eingeschriebene Schüler:</b></p>";

        // WICHTIG: Liste starten
        str += "<ol style='margin-top: 0px;'>";

        std::vector<Student*> st = c->getStudents();
        // Schüler innerhalb des Kurses alphabetisch sortieren
        std::sort(st.begin(), st.end(), [](Student* a, Student* b) {
            if (a->getLastName() == b->getLastName()) return a->getFirstName() < b->getFirstName();
            return a->getLastName() < b->getLastName();
        });

        if(st.empty()) {
            str += "<li><i>Keine Schüler zugeordnet</i></li>";
        } else {
            for (Student* s : st) {
                // Jedes <li> erzeugt automatisch eine neue Zeile mit Nummer!
                str += "<li>" + QString::fromStdString(s->getLastName()) + ", " + QString::fromStdString(s->getFirstName()) + "</li>";
            }
        }
        str += "</ol>";
        str += "<hr style='border: 0; border-top: 1px solid #ccc;'>";
    }
    str += "<br><h2 style='color: #E74C3C;'>⏳ Warteliste</h2>";

        if (waitingList.empty()) {
            str += "<p><i>Aktuell befinden sich keine Schüler auf der Warteliste.</i></p>";
        } else {
            str += "<p>Diese Schüler konnten aufgrund fehlender Kapazitäten keinem Kurs zugewiesen werden:</p>";
str += "<ol style='margin-left: 50px; color: #555;'>";
            // Sortiere auch die Warteliste für eine schönere Ansicht
            std::sort(waitingList.begin(), waitingList.end(), [](Student* a, Student* b) {
                if (a->getLastName() == b->getLastName()) return a->getFirstName() < b->getFirstName();
                return a->getLastName() < b->getLastName();
            });

            for (Student* s : waitingList) {
                str += "<li>" + QString::fromStdString(s->getLastName()) + ", " + QString::fromStdString(s->getFirstName()) + "</li>";
            }
                    str += "</ol>";
        }

        str += "</div>";
        return str;
    }


QString SkiSchool::getRawStudentList()
{
    if (students.empty()) return "Keine Schueler geladen.";

    QString str = "Eingelesene Schueler (noch nicht verteilt):\n";
    str += "Anzahl: " + QString::number(students.size()) + "\n";
    str += "------------------------------------------\n";

    for (Student* s : students) {
        str += QString::fromStdString(s->getLastName()) + ", "
               + QString::fromStdString(s->getFirstName()) + " ("
               + QString::fromStdString(levelToText(s->getOwnLevel())) + ")\n";
    }

    return str;
}
