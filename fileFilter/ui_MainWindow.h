/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxSource;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSourcePath;
    QPushButton *pushButtonBrowseSource;
    QGroupBox *groupBoxTarget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditTargetPath;
    QPushButton *pushButtonBrowseTarget;
    QGroupBox *groupBoxRules;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxFileNameRule;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelFileNameHelp;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelFileNameEnabled;
    QCheckBox *checkBoxFileNameRule;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelFileNameExample;
    QGroupBox *groupBoxProgress;
    QVBoxLayout *verticalLayout_3;
    QProgressBar *progressBar;
    QLabel *labelStatus;
    QTextEdit *textEditLog;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClearLog;
    QPushButton *pushButtonExit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 700);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBoxSource = new QGroupBox(centralwidget);
        groupBoxSource->setObjectName(QString::fromUtf8("groupBoxSource"));
        horizontalLayout = new QHBoxLayout(groupBoxSource);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditSourcePath = new QLineEdit(groupBoxSource);
        lineEditSourcePath->setObjectName(QString::fromUtf8("lineEditSourcePath"));

        horizontalLayout->addWidget(lineEditSourcePath);

        pushButtonBrowseSource = new QPushButton(groupBoxSource);
        pushButtonBrowseSource->setObjectName(QString::fromUtf8("pushButtonBrowseSource"));

        horizontalLayout->addWidget(pushButtonBrowseSource);


        verticalLayout->addWidget(groupBoxSource);

        groupBoxTarget = new QGroupBox(centralwidget);
        groupBoxTarget->setObjectName(QString::fromUtf8("groupBoxTarget"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxTarget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEditTargetPath = new QLineEdit(groupBoxTarget);
        lineEditTargetPath->setObjectName(QString::fromUtf8("lineEditTargetPath"));

        horizontalLayout_2->addWidget(lineEditTargetPath);

        pushButtonBrowseTarget = new QPushButton(groupBoxTarget);
        pushButtonBrowseTarget->setObjectName(QString::fromUtf8("pushButtonBrowseTarget"));

        horizontalLayout_2->addWidget(pushButtonBrowseTarget);


        verticalLayout->addWidget(groupBoxTarget);

        groupBoxRules = new QGroupBox(centralwidget);
        groupBoxRules->setObjectName(QString::fromUtf8("groupBoxRules"));
        verticalLayout_2 = new QVBoxLayout(groupBoxRules);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxFileNameRule = new QGroupBox(groupBoxRules);
        groupBoxFileNameRule->setObjectName(QString::fromUtf8("groupBoxFileNameRule"));
        verticalLayout_6 = new QVBoxLayout(groupBoxFileNameRule);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelFileNameHelp = new QLabel(groupBoxFileNameRule);
        labelFileNameHelp->setObjectName(QString::fromUtf8("labelFileNameHelp"));

        verticalLayout_6->addWidget(labelFileNameHelp);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelFileNameEnabled = new QLabel(groupBoxFileNameRule);
        labelFileNameEnabled->setObjectName(QString::fromUtf8("labelFileNameEnabled"));

        horizontalLayout_6->addWidget(labelFileNameEnabled);

        checkBoxFileNameRule = new QCheckBox(groupBoxFileNameRule);
        checkBoxFileNameRule->setObjectName(QString::fromUtf8("checkBoxFileNameRule"));
        checkBoxFileNameRule->setChecked(false);

        horizontalLayout_6->addWidget(checkBoxFileNameRule);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_6);

        labelFileNameExample = new QLabel(groupBoxFileNameRule);
        labelFileNameExample->setObjectName(QString::fromUtf8("labelFileNameExample"));

        verticalLayout_6->addWidget(labelFileNameExample);


        verticalLayout_2->addWidget(groupBoxFileNameRule);


        verticalLayout->addWidget(groupBoxRules);

        groupBoxProgress = new QGroupBox(centralwidget);
        groupBoxProgress->setObjectName(QString::fromUtf8("groupBoxProgress"));
        verticalLayout_3 = new QVBoxLayout(groupBoxProgress);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        progressBar = new QProgressBar(groupBoxProgress);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout_3->addWidget(progressBar);

        labelStatus = new QLabel(groupBoxProgress);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));

        verticalLayout_3->addWidget(labelStatus);

        textEditLog = new QTextEdit(groupBoxProgress);
        textEditLog->setObjectName(QString::fromUtf8("textEditLog"));
        textEditLog->setReadOnly(true);
        textEditLog->setMaximumHeight(150);

        verticalLayout_3->addWidget(textEditLog);


        verticalLayout->addWidget(groupBoxProgress);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setEnabled(false);

        horizontalLayout_3->addWidget(pushButtonStop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonClearLog = new QPushButton(centralwidget);
        pushButtonClearLog->setObjectName(QString::fromUtf8("pushButtonClearLog"));

        horizontalLayout_3->addWidget(pushButtonClearLog);

        pushButtonExit = new QPushButton(centralwidget);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));

        horizontalLayout_3->addWidget(pushButtonExit);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionExit);
        menu_2->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\277\207\346\273\244\345\210\206\347\261\273\345\267\245\345\205\267", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        groupBoxSource->setTitle(QApplication::translate("MainWindow", "\346\272\220\346\226\207\344\273\266\345\244\271\350\256\276\347\275\256", nullptr));
        lineEditSourcePath->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\272\220\346\226\207\344\273\266\345\244\271", nullptr));
        pushButtonBrowseSource->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        groupBoxTarget->setTitle(QApplication::translate("MainWindow", "\347\233\256\346\240\207\346\226\207\344\273\266\345\244\271\350\256\276\347\275\256", nullptr));
        lineEditTargetPath->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\347\233\256\346\240\207\346\226\207\344\273\266\345\244\271", nullptr));
        pushButtonBrowseTarget->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        groupBoxRules->setTitle(QApplication::translate("MainWindow", "\345\210\206\347\261\273\350\247\204\345\210\231\350\256\276\347\275\256", nullptr));
        groupBoxFileNameRule->setTitle(QApplication::translate("MainWindow", "\346\214\211\346\226\207\344\273\266\345\220\215\345\210\206\347\261\273", nullptr));
        labelFileNameHelp->setText(QApplication::translate("MainWindow", "\346\214\211\346\226\207\344\273\266\345\220\215\357\274\210\344\270\215\345\270\246\346\211\251\345\261\225\345\220\215\357\274\211\350\277\233\350\241\214\345\210\206\347\261\273\357\274\214\347\233\270\345\220\214\346\226\207\344\273\266\345\220\215\347\232\204\346\226\207\344\273\266\346\224\276\345\234\250\345\220\214\344\270\200\346\226\207\344\273\266\345\244\271\357\274\214\345\270\246\345\211\257\346\234\254\346\240\207\350\257\206\347\232\204\346\226\207\344\273\266\344\274\232\345\275\222\345\261\236\345\210\260\345\216\237\345\247\213\346\226\207\344\273\266\345\220\215\345\257\271\345\272\224\347\232\204\346\226\207\344\273\266\345\244\271", nullptr));
        labelFileNameEnabled->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\346\214\211\346\226\207\344\273\266\345\220\215\345\210\206\347\261\273\357\274\232", nullptr));
        labelFileNameExample->setText(QApplication::translate("MainWindow", "\347\244\272\344\276\213\357\274\232\346\226\207\344\273\266\"\346\212\245\345\221\212.docx\"\343\200\201\"\346\212\245\345\221\212 - \345\211\257\346\234\254.pdf\"\343\200\201\"\346\212\245\345\221\212 - \345\211\257\346\234\254(2).txt\"\351\203\275\345\260\206\345\244\215\345\210\266\345\210\260\"\346\212\245\345\221\212\"\346\226\207\344\273\266\345\244\271", nullptr));
        groupBoxProgress->setTitle(QApplication::translate("MainWindow", "\350\277\233\345\272\246\345\222\214\346\227\245\345\277\227", nullptr));
        labelStatus->setText(QApplication::translate("MainWindow", "\345\260\261\347\273\252", nullptr));
        textEditLog->setPlaceholderText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\227\245\345\277\227\345\260\206\346\230\276\347\244\272\345\234\250\350\277\231\351\207\214...", nullptr));
        pushButtonStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\210\206\347\261\273\346\213\267\350\264\235", nullptr));
        pushButtonStart->setStyleSheet(QApplication::translate("MainWindow", "font-weight: bold; font-size: 14px;", nullptr));
        pushButtonStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        pushButtonClearLog->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        pushButtonExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
