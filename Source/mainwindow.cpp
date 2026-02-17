#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SkiSchool Management System");
    this->resize(800, 600);
    statusBar()->showMessage("Bereit.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDaten_einlesen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Studentendatei öffnen", "", "Textdateien (*.txt)");

    if (!fileName.isEmpty()) {
        try {
            school.readStudentFile(fileName.toStdString());
            QString studentList = school.getRawStudentList();
            QString info = "<h1>✅ Datei geladen</h1>";
            int anzahl = school.getStudents().size();
            info += "<p>Es wurden <b>" + QString::number(anzahl) + "</b> Schüler erfolgreich aus der Datei eingelesen.</p>";
            ui->displayArea->setHtml(info);
            ui->displayArea->setText(studentList);

            statusBar()->showMessage("Daten erfolgreich geladen.");
            QMessageBox::information(this, "Erfolg", "Studenten wurden eingelesen.");
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Fehler", e.what());
        }
    }
}

void MainWindow::on_actionSch_ler_verteilen_triggered()
{
    school.distributeStudents();
    statusBar()->showMessage("Verteilung abgeschlossen.");
    QMessageBox::information(this, "Info", "Verteilung der Schüler durchgeführt.");
}

void MainWindow::on_actionKursuebersicht_anzeigen_triggered()
{
    QString report = school.showAllCourses();
    ui->displayArea->setText(report);
    statusBar()->showMessage("Kursübersicht aktualisiert.");
}
