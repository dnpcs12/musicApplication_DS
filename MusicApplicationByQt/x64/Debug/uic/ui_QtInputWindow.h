/********************************************************************************
** Form generated from reading UI file 'QtInputWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTINPUTWINDOW_H
#define UI_QTINPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtInputWindow
{
public:
    QLabel *label;
    QPushButton *AddButton;
    QPushButton *cancleButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *input_id;
    QLabel *label_3;
    QLineEdit *input_title;
    QLabel *label_4;
    QLineEdit *input_singer;
    QLabel *label_5;
    QLineEdit *input_composer;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_7;
    QTextEdit *textEdit;
    QPushButton *ChangeButton;
    QPushButton *lyricfileButton;

    void setupUi(QWidget *QtInputWindow)
    {
        if (QtInputWindow->objectName().isEmpty())
            QtInputWindow->setObjectName(QString::fromUtf8("QtInputWindow"));
        QtInputWindow->resize(419, 421);
        QtInputWindow->setMaximumSize(QSize(529, 541));
        label = new QLabel(QtInputWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 201, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\353\202\230\353\254\264M"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        AddButton = new QPushButton(QtInputWindow);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(20, 360, 131, 41));
        cancleButton = new QPushButton(QtInputWindow);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        cancleButton->setGeometry(QRect(230, 360, 131, 41));
        formLayoutWidget = new QWidget(QtInputWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 341, 290));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 7, 0, 9);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        input_id = new QLineEdit(formLayoutWidget);
        input_id->setObjectName(QString::fromUtf8("input_id"));
        input_id->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, input_id);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        input_title = new QLineEdit(formLayoutWidget);
        input_title->setObjectName(QString::fromUtf8("input_title"));

        formLayout->setWidget(1, QFormLayout::FieldRole, input_title);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        input_singer = new QLineEdit(formLayoutWidget);
        input_singer->setObjectName(QString::fromUtf8("input_singer"));

        formLayout->setWidget(2, QFormLayout::FieldRole, input_singer);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        input_composer = new QLineEdit(formLayoutWidget);
        input_composer->setObjectName(QString::fromUtf8("input_composer"));

        formLayout->setWidget(3, QFormLayout::FieldRole, input_composer);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        textEdit = new QTextEdit(formLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit);

        ChangeButton = new QPushButton(QtInputWindow);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));
        ChangeButton->setGeometry(QRect(20, 360, 131, 41));
        lyricfileButton = new QPushButton(QtInputWindow);
        lyricfileButton->setObjectName(QString::fromUtf8("lyricfileButton"));
        lyricfileButton->setGeometry(QRect(360, 210, 41, 31));
        ChangeButton->raise();
        label->raise();
        AddButton->raise();
        cancleButton->raise();
        formLayoutWidget->raise();
        lyricfileButton->raise();

        retranslateUi(QtInputWindow);
        QObject::connect(AddButton, SIGNAL(clicked()), QtInputWindow, SLOT(newMusicCreate()));
        QObject::connect(cancleButton, SIGNAL(clicked()), QtInputWindow, SLOT(close()));
        QObject::connect(ChangeButton, SIGNAL(clicked()), QtInputWindow, SLOT(ChangeMusicInfo()));
        QObject::connect(lyricfileButton, SIGNAL(clicked()), QtInputWindow, SLOT(lyricfileOpen()));

        QMetaObject::connectSlotsByName(QtInputWindow);
    } // setupUi

    void retranslateUi(QWidget *QtInputWindow)
    {
        QtInputWindow->setWindowTitle(QCoreApplication::translate("QtInputWindow", "QtInputWindow", nullptr));
        label->setText(QCoreApplication::translate("QtInputWindow", "\354\203\210 \353\205\270\353\236\230 \354\266\224\352\260\200", nullptr));
        AddButton->setText(QCoreApplication::translate("QtInputWindow", "\354\266\224\352\260\200", nullptr));
        cancleButton->setText(QCoreApplication::translate("QtInputWindow", "\354\267\250\354\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("QtInputWindow", "\352\263\240\354\234\240\353\262\210\355\230\270", nullptr));
        input_id->setInputMask(QString());
        input_id->setText(QString());
        label_3->setText(QCoreApplication::translate("QtInputWindow", "\354\240\234\353\252\251", nullptr));
        input_title->setInputMask(QString());
        input_title->setText(QString());
        label_4->setText(QCoreApplication::translate("QtInputWindow", "\352\260\200\354\210\230", nullptr));
        input_singer->setInputMask(QString());
        label_5->setText(QCoreApplication::translate("QtInputWindow", "\354\236\221\352\263\241\352\260\200", nullptr));
        input_composer->setInputMask(QString());
        label_6->setText(QCoreApplication::translate("QtInputWindow", "\354\236\245\353\245\264", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("QtInputWindow", "Unknown", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("QtInputWindow", "Dance", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("QtInputWindow", "Ballad", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("QtInputWindow", "Idol", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("QtInputWindow", "Pop", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("QtInputWindow", "Indie", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("QtInputWindow", "Rap/Hiphop", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("QtInputWindow", "Rock", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("QtInputWindow", "R&B", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("QtInputWindow", "Classic", nullptr));

        label_7->setText(QCoreApplication::translate("QtInputWindow", "\352\260\200\354\202\254", nullptr));
        textEdit->setHtml(QCoreApplication::translate("QtInputWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim';\"><br /></p></body></html>", nullptr));
        ChangeButton->setText(QCoreApplication::translate("QtInputWindow", "\353\263\200\352\262\275", nullptr));
        lyricfileButton->setText(QCoreApplication::translate("QtInputWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtInputWindow: public Ui_QtInputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTINPUTWINDOW_H
