#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QStatusBar>
#include "skischool.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionDaten_einlesen_triggered();

    void on_actionSch_ler_verteilen_triggered();

    void on_actionKursuebersicht_anzeigen_triggered();

private:
    SkiSchool school;
    QTextEdit *displayArea;
    void setupMenu();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
