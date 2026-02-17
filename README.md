🎿 SkiSchool-Management-System (C++ & Qt)
Dieses Projekt umfasst ein umfassendes Verwaltungssystem für eine Skischule, das im Rahmen des Moduls Programmieren 2 entwickelt wurde. Die Anwendung kombiniert eine robuste Business-Logik (C++) mit einer modernen grafischen Oberfläche (Qt).

🚀 Funktionen
Objektorientierte Modellierung: Vollständige Verwaltung von Studenten, Lehrern und Kursen mit Qualifikationsstufen von BEGINNER bis EXPERT.

Datenmanagement: Automatisches Einlesen von Schülerdaten aus Textdateien inklusive Validierung und Fehlerbehandlung über try-throw-catch.

Intelligente Kurs-Logik: Automatisierte Zuweisung von Schülern zu Kursen basierend auf Skill-Level, Sportart (Ski/Snowboard) und Kapazitätsgrenzen (max. 8 Schüler pro Kurs).

Wartelisten-System: Schüler, die aufgrund voller Kapazitäten oder fehlender Kursangebote nicht zugeordnet werden können, werden automatisch auf einer priorisierten Warteliste verwaltet.

Dynamische GUI: Benutzerfreundliche Oberfläche mit Echtzeit-Feedback, Datei-Dialogen und einer formatierten Kursübersicht.

🛠️ Technische Details
Sprache: C++ (Standard STL & Qt Framework).

Datenstrukturen: Effiziente Nutzung von std::vector für Listen und std::map für die schnelle Kursverwaltung.

Algorithmen: Komplexe Sortier-Algorithmen mittels std::sort und Lambda-Funktionen:

Primär: Sortierung der Kurse nach ihrer eindeutigen Kurs-ID.

Sekundär: Alphabetische Sortierung der Schüler innerhalb der Kurse nach Nachnamen.

UI-Design: Einsatz von HTML-Rendering innerhalb der Qt-Widgets, um eine klare optische Trennung (Farben, Nummerierungen, Icons) der Kurse und der Warteliste zu ermöglichen.

Robustheit: Sicherstellung der Stabilität durch Null-Pointer-Checks und Exception-Handling bei Dateizugriffen.

📋 Bedienung
1- Daten einlesen: Auswahl der students.txt – die Rohdaten werden sofort zur Kontrolle im Fenster aufgelistet.

2- Schüler verteilen: Die Logik prüft Kapazitäten und Kriterien.

3- Kursübersicht: Anzeige des fertigen Kursplans mit Lehrern, Schülern und der abschließenden Warteliste.
