/********************************************************************************
** Form generated from reading UI file 'QtWindowSelectPlayList.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWINDOWSELECTPLAYLIST_H
#define UI_QTWINDOWSELECTPLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWindowSelectPlayList
{
public:
    QFrame *frame;
    QLabel *lable;
    QComboBox *comboBox;
    QPushButton *okbutton;
    QPushButton *canclebutton;
    QPushButton *pushButton;

    void setupUi(QWidget *QtWindowSelectPlayList)
    {
        if (QtWindowSelectPlayList->objectName().isEmpty())
            QtWindowSelectPlayList->setObjectName(QString::fromUtf8("QtWindowSelectPlayList"));
        QtWindowSelectPlayList->resize(382, 209);
        frame = new QFrame(QtWindowSelectPlayList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 20, 371, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lable = new QLabel(frame);
        lable->setObjectName(QString::fromUtf8("lable"));
        lable->setGeometry(QRect(20, 10, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\353\202\230\353\254\264L"));
        font.setPointSize(12);
        lable->setFont(font);
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 271, 41));
        okbutton = new QPushButton(frame);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(20, 100, 101, 41));
        canclebutton = new QPushButton(frame);
        canclebutton->setObjectName(QString::fromUtf8("canclebutton"));
        canclebutton->setGeometry(QRect(190, 100, 101, 41));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 50, 61, 41));

        retranslateUi(QtWindowSelectPlayList);
        QObject::connect(canclebutton, SIGNAL(clicked()), QtWindowSelectPlayList, SLOT(close()));
        QObject::connect(okbutton, SIGNAL(clicked()), QtWindowSelectPlayList, SLOT(ReturnPLName()));
        QObject::connect(pushButton, SIGNAL(clicked()), QtWindowSelectPlayList, SLOT(MakeNewPL()));

        QMetaObject::connectSlotsByName(QtWindowSelectPlayList);
    } // setupUi

    void retranslateUi(QWidget *QtWindowSelectPlayList)
    {
        QtWindowSelectPlayList->setWindowTitle(QCoreApplication::translate("QtWindowSelectPlayList", "QtWindowSelectPlayList", nullptr));
        lable->setText(QCoreApplication::translate("QtWindowSelectPlayList", "\354\236\254\354\203\235\353\252\251\353\241\235 \354\204\240\355\203\235", nullptr));
        okbutton->setText(QCoreApplication::translate("QtWindowSelectPlayList", "\355\231\225\354\235\270", nullptr));
        canclebutton->setText(QCoreApplication::translate("QtWindowSelectPlayList", "\354\267\250\354\206\214", nullptr));
        pushButton->setText(QCoreApplication::translate("QtWindowSelectPlayList", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWindowSelectPlayList: public Ui_QtWindowSelectPlayList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWINDOWSELECTPLAYLIST_H
