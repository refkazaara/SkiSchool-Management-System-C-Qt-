#include "skischool.h"

std::string levelToText(Level l) {
    switch(l) {
    case Level::BEGINNER:     return "BEGINNER";
    case Level::INTERMEDIATE: return "INTERMEDIATE";
    case Level::ADVANCED:     return "ADVANCED";
    case Level::EXPERT:       return "EXPERT";
    default:                  return "UNKNOWN";
    }
}

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

        cout << "Bitte korrigieren Sie die Datei und waehlen Sie erneut Punkt 1." << endl;
    }
    catch (const exception& e) {

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
        cin >> art;
        if (cin.fail()) {
            cout << "Fehler: Bitte eine Zahl eingeben!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (art == 0 || art == 1) {
            break;
        } else {
            cout << "Ungueltige Art! Bitte nur 0 oder 1." << endl;
        }
    }
    while (true) {
        cout << "Level des Kurses? (0: BEGINNER, 1: INTERMEDIATE, 2: ADVANCED, 3: EXPERT)" << endl;
        cin >> lvl;


        cout << "Fehler: Das war keine Zahl! Bitte versuchen Sie es erneut." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;



        if (lvl >= 0 && lvl <= 3) {
            break;}
        else {
            cout << "Ungueltiges Level! Bitte nur 0 bis 3 eingeben." << endl;

        }


        Teacher* t = nullptr;
        cout<<"Geben Sie die Nummer der Lehrerin ein"<<endl;

        while (true) {

            cin >> lNr;

            t = nullptr;
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


            if (lvl >= 2 && t->getSeniority() != Seniority::SENIOR) {
                cout << "Zu wenig Erfahrung fuer dieses Level!" << endl;
                continue;
            }

            if (art == 0 && t->getMySkill() == Skill::SNOWBOARD) {
                cout << "Falsche Sportart!" << endl;
                continue;
            }
            if (art == 1 && t->getMySkill() == Skill::SKI) {
                cout << "Falsche Sportart!" << endl;
                continue;
            }


            bool schonBelegt = false;

            for (auto it = courses.begin(); it != courses.end(); ++it) {
                if (it->second->getTeacher()->getId() == lNr) {
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

        courses[kId] = new Course(kursLevel, kursSkill, t);

        cout << "Kurs mit der ID " << kId << " wurde fuer Lehrer*in " << t->getLastName() << " angelegt" << endl;
    }
}
void SkiSchool::distributeStudents()
{


    for (auto it = courses.begin(); it != courses.end(); ++it)
    {
        it->second->clearStudents();
    }

    waitingList.clear();

    int zugeordnetCount = 0;


    for (Student* s : students)
    {
        bool zugeordnet = false;

        for (auto it = courses.begin(); it != courses.end(); ++it)
        {
            Course* c =it->second ;

            if (c->getLevel() == s->getOwnLevel() &&
                    c->getType() == s->getRequestedSkill() &&
                    c->getStudents().size() < c->getGroupSize())
            {
                c->addStudent(s);
                zugeordnetCount++;
                zugeordnet = true;
                break;
            }
        }

        if (!zugeordnet)
        {
            waitingList.push_back(s);
        }
    }

    cout << "Verteilung abgeschlossen. Zugeordnet: " << zugeordnetCount
         << " | Warteliste: " << waitingList.size() << endl;

}

QString SkiSchool::showAllCourses()
{
    QString str = "<div style='font-size: 13pt; font-family: Arial, sans-serif;'>";


    std::vector<std::pair<long, Course*>> list;
    for (auto const& [id, c] : courses) {
        if (c != nullptr) list.push_back({id, c});
    }


    std::sort(list.begin(), list.end(), [](const std::pair<long, Course*>& a, const std::pair<long, Course*>& b) {
        return a.first < b.first;
    });


    for (const auto& entry : list)
    {
        Course* c = entry.second;
        Teacher* t = c->getTeacher();
        if (!c || !t) continue;

        str += "<h2 style='color: #2E86C1; margin-bottom: 5px;'>Kurs " + QString::number(entry.first) + "</h2>";
        str += "<b>Lehrer:</b> " + QString::fromStdString(t->getFirstName()) + " " + QString::fromStdString(t->getLastName()) + "<br>";
        str += "<i>" + QString::fromStdString(levelToText(c->getLevel())) + " " + QString::fromStdString(typeToText(c->getType())) + "</i><br>";

        str += "<p style='margin-bottom: 2px;'><b>Eingeschriebene Schüler:</b></p>";

        str += "<ol style='margin-top: 0px;'>";

        std::vector<Student*> st = c->getStudents();

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
