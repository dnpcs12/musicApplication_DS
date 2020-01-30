/********************************************************************************
** Form generated from reading UI file 'QtWindow_playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWINDOW_PLAYLIST_H
#define UI_QTWINDOW_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWindow_playlist
{
public:
    QFrame *frame;
    QLineEdit *lineEdit;
    QPushButton *OkButton;
    QPushButton *CancleButton;
    QLabel *label;

    void setupUi(QWidget *QtWindow_playlist)
    {
        if (QtWindow_playlist->objectName().isEmpty())
            QtWindow_playlist->setObjectName(QString::fromUtf8("QtWindow_playlist"));
        QtWindow_playlist->resize(420, 174);
        frame = new QFrame(QtWindow_playlist);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 371, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 331, 31));
        OkButton = new QPushButton(frame);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(20, 90, 131, 31));
        CancleButton = new QPushButton(frame);
        CancleButton->setObjectName(QString::fromUtf8("CancleButton"));
        CancleButton->setGeometry(QRect(220, 90, 131, 31));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 0, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\353\202\230\353\254\264L"));
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(QtWindow_playlist);
        QObject::connect(CancleButton, SIGNAL(clicked()), QtWindow_playlist, SLOT(close()));
        QObject::connect(OkButton, SIGNAL(clicked()), QtWindow_playlist, SLOT(PlayListNameReturn()));

        QMetaObject::connectSlotsByName(QtWindow_playlist);
    } // setupUi

    void retranslateUi(QWidget *QtWindow_playlist)
    {
        QtWindow_playlist->setWindowTitle(QCoreApplication::translate("QtWindow_playlist", "QtWindow_playlist", nullptr));
        lineEdit->setText(QString());
        OkButton->setText(QCoreApplication::translate("QtWindow_playlist", "\355\231\225\354\235\270", nullptr));
        CancleButton->setText(QCoreApplication::translate("QtWindow_playlist", "\354\267\250\354\206\214", nullptr));
        label->setText(QCoreApplication::translate("QtWindow_playlist", "\354\203\210 \354\236\254\354\203\235\353\252\251\353\241\235 \354\203\235\354\204\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWindow_playlist: public Ui_QtWindow_playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWINDOW_PLAYLIST_H
