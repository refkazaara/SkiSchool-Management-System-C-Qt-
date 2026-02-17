/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDaten_einlesen;
    QAction *actionSch_ler_verteilen;
    QAction *actionKursuebersicht_anzeigen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *displayArea;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuDatei;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionDaten_einlesen = new QAction(MainWindow);
        actionDaten_einlesen->setObjectName(QString::fromUtf8("actionDaten_einlesen"));
        actionSch_ler_verteilen = new QAction(MainWindow);
        actionSch_ler_verteilen->setObjectName(QString::fromUtf8("actionSch_ler_verteilen"));
        actionKursuebersicht_anzeigen = new QAction(MainWindow);
        actionKursuebersicht_anzeigen->setObjectName(QString::fromUtf8("actionKursuebersicht_anzeigen"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        displayArea = new QTextEdit(centralwidget);
        displayArea->setObjectName(QString::fromUtf8("displayArea"));
        QFont font;
        font.setFamily(QString::fromUtf8("Book Antiqua"));
        font.setPointSize(12);
        font.setItalic(true);
        displayArea->setFont(font);
        displayArea->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    color: #333333;            /* Dunkelgraue Schrift */\n"
"    border-radius: 5px;\n"
"}"));
        displayArea->setUndoRedoEnabled(false);
        displayArea->setReadOnly(true);

        horizontalLayout->addWidget(displayArea);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuDatei->addSeparator();
        menuDatei->addSeparator();
        menuDatei->addSeparator();
        menuDatei->addAction(actionDaten_einlesen);
        menuDatei->addAction(actionSch_ler_verteilen);
        menuDatei->addAction(actionKursuebersicht_anzeigen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDaten_einlesen->setText(QCoreApplication::translate("MainWindow", "Daten einlesen", nullptr));
        actionSch_ler_verteilen->setText(QCoreApplication::translate("MainWindow", "Sch\303\274ler verteilen", nullptr));
        actionKursuebersicht_anzeigen->setText(QCoreApplication::translate("MainWindow", "Kursuebersicht anzeigen", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Skischule", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
