/********************************************************************************
** Form generated from reading UI file 'MusicApplicationByQt.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICAPPLICATIONBYQT_H
#define UI_MUSICAPPLICATIONBYQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicApplicationByQtClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *song;
    QGroupBox *groupBox;
    QPushButton *AddMusic;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *MusicList;
    QPushButton *pushButton_4;
    QWidget *playlist_tab;
    QListWidget *QMasterPlayList;
    QTableWidget *inPlayList;
    QPushButton *PL_DeleteButton;
    QPushButton *PL_AddButton;
    QWidget *Search;
    QLineEdit *searchBox;
    QComboBox *searchRange;
    QPushButton *pushButton_3;
    QTableWidget *searchResult;
    QLabel *debuglable;
    QGroupBox *groupBox_2;
    QLabel *pic_music;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *curMusicTitle;
    QLabel *curMusicArtist;
    QTextBrowser *curMusiclyric;
    QPushButton *NextButton;
    QPushButton *PreButton;
    QCheckBox *isRandomCheck;
    QRadioButton *curLoop;
    QRadioButton *totalLoop;
    QRadioButton *NoLoop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MusicApplicationByQtClass)
    {
        if (MusicApplicationByQtClass->objectName().isEmpty())
            MusicApplicationByQtClass->setObjectName(QString::fromUtf8("MusicApplicationByQtClass"));
        MusicApplicationByQtClass->resize(1229, 742);
        centralWidget = new QWidget(MusicApplicationByQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 781, 621));
        tabWidget->setInputMethodHints(Qt::ImhNoEditMenu);
        tabWidget->setIconSize(QSize(20, 20));
        song = new QWidget();
        song->setObjectName(QString::fromUtf8("song"));
        groupBox = new QGroupBox(song);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 761, 571));
        groupBox->setCheckable(false);
        AddMusic = new QPushButton(groupBox);
        AddMusic->setObjectName(QString::fromUtf8("AddMusic"));
        AddMusic->setGeometry(QRect(10, 520, 101, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 520, 101, 31));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 520, 91, 31));
        MusicList = new QTableWidget(groupBox);
        if (MusicList->columnCount() < 6)
            MusicList->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        MusicList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        MusicList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        MusicList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        MusicList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        MusicList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        MusicList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        MusicList->setObjectName(QString::fromUtf8("MusicList"));
        MusicList->setGeometry(QRect(10, 20, 741, 481));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(640, 520, 111, 31));
        tabWidget->addTab(song, QString());
        playlist_tab = new QWidget();
        playlist_tab->setObjectName(QString::fromUtf8("playlist_tab"));
        QMasterPlayList = new QListWidget(playlist_tab);
        QMasterPlayList->setObjectName(QString::fromUtf8("QMasterPlayList"));
        QMasterPlayList->setGeometry(QRect(20, 10, 221, 531));
        inPlayList = new QTableWidget(playlist_tab);
        if (inPlayList->columnCount() < 4)
            inPlayList->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        inPlayList->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        inPlayList->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        inPlayList->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        inPlayList->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        inPlayList->setObjectName(QString::fromUtf8("inPlayList"));
        inPlayList->setGeometry(QRect(250, 10, 511, 531));
        PL_DeleteButton = new QPushButton(playlist_tab);
        PL_DeleteButton->setObjectName(QString::fromUtf8("PL_DeleteButton"));
        PL_DeleteButton->setGeometry(QRect(150, 550, 111, 31));
        PL_AddButton = new QPushButton(playlist_tab);
        PL_AddButton->setObjectName(QString::fromUtf8("PL_AddButton"));
        PL_AddButton->setGeometry(QRect(10, 550, 131, 31));
        tabWidget->addTab(playlist_tab, QString());
        Search = new QWidget();
        Search->setObjectName(QString::fromUtf8("Search"));
        searchBox = new QLineEdit(Search);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setGeometry(QRect(20, 30, 371, 31));
        searchRange = new QComboBox(Search);
        searchRange->addItem(QString());
        searchRange->addItem(QString());
        searchRange->addItem(QString());
        searchRange->addItem(QString());
        searchRange->addItem(QString());
        searchRange->setObjectName(QString::fromUtf8("searchRange"));
        searchRange->setGeometry(QRect(390, 30, 101, 31));
        pushButton_3 = new QPushButton(Search);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(490, 30, 61, 31));
        searchResult = new QTableWidget(Search);
        if (searchResult->columnCount() < 5)
            searchResult->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        searchResult->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        searchResult->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        searchResult->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        searchResult->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        searchResult->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        searchResult->setObjectName(QString::fromUtf8("searchResult"));
        searchResult->setGeometry(QRect(20, 80, 731, 471));
        tabWidget->addTab(Search, QString());
        debuglable = new QLabel(centralWidget);
        debuglable->setObjectName(QString::fromUtf8("debuglable"));
        debuglable->setGeometry(QRect(370, 630, 331, 41));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(790, 10, 421, 661));
        QFont font;
        font.setFamily(QString::fromUtf8("HY\353\202\230\353\254\264M"));
        font.setPointSize(9);
        groupBox_2->setFont(font);
        pic_music = new QLabel(groupBox_2);
        pic_music->setObjectName(QString::fromUtf8("pic_music"));
        pic_music->setGeometry(QRect(50, 30, 311, 261));
        pic_music->setPixmap(QPixmap(QString::fromUtf8(":/image/music.png")));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 310, 401, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 0, 5, 0);
        curMusicTitle = new QLabel(verticalLayoutWidget);
        curMusicTitle->setObjectName(QString::fromUtf8("curMusicTitle"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HY\353\202\230\353\254\264M"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        curMusicTitle->setFont(font1);

        verticalLayout->addWidget(curMusicTitle);

        curMusicArtist = new QLabel(verticalLayoutWidget);
        curMusicArtist->setObjectName(QString::fromUtf8("curMusicArtist"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HY\353\202\230\353\254\264M"));
        font2.setPointSize(8);
        curMusicArtist->setFont(font2);

        verticalLayout->addWidget(curMusicArtist);

        curMusiclyric = new QTextBrowser(verticalLayoutWidget);
        curMusiclyric->setObjectName(QString::fromUtf8("curMusiclyric"));
        QFont font3;
        font3.setPointSize(9);
        curMusiclyric->setFont(font3);

        verticalLayout->addWidget(curMusiclyric);

        NextButton = new QPushButton(groupBox_2);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        NextButton->setGeometry(QRect(320, 580, 93, 28));
        PreButton = new QPushButton(groupBox_2);
        PreButton->setObjectName(QString::fromUtf8("PreButton"));
        PreButton->setGeometry(QRect(10, 580, 93, 28));
        isRandomCheck = new QCheckBox(groupBox_2);
        isRandomCheck->setObjectName(QString::fromUtf8("isRandomCheck"));
        isRandomCheck->setGeometry(QRect(10, 640, 96, 19));
        curLoop = new QRadioButton(groupBox_2);
        curLoop->setObjectName(QString::fromUtf8("curLoop"));
        curLoop->setGeometry(QRect(290, 640, 131, 19));
        totalLoop = new QRadioButton(groupBox_2);
        totalLoop->setObjectName(QString::fromUtf8("totalLoop"));
        totalLoop->setGeometry(QRect(290, 620, 121, 19));
        NoLoop = new QRadioButton(groupBox_2);
        NoLoop->setObjectName(QString::fromUtf8("NoLoop"));
        NoLoop->setGeometry(QRect(160, 640, 108, 19));
        MusicApplicationByQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MusicApplicationByQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1229, 26));
        MusicApplicationByQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MusicApplicationByQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MusicApplicationByQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MusicApplicationByQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MusicApplicationByQtClass->setStatusBar(statusBar);

        retranslateUi(MusicApplicationByQtClass);
        QObject::connect(AddMusic, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(getMusicInfo()));
        QObject::connect(pushButton, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(OpenTextFile()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(WriteTextFile()));
        QObject::connect(MusicList, SIGNAL(cellClicked(int,int)), MusicList, SLOT(selectRow(int)));
        QObject::connect(PL_AddButton, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(openPlaylistAddWindow()));
        QObject::connect(PL_DeleteButton, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(DeletePlayList()));
        QObject::connect(QMasterPlayList, SIGNAL(doubleClicked(QModelIndex)), MusicApplicationByQtClass, SLOT(ShowInPlayList()));
        QObject::connect(MusicList, SIGNAL(cellDoubleClicked(int,int)), MusicApplicationByQtClass, SLOT(MusicPlay()));
        QObject::connect(inPlayList, SIGNAL(cellClicked(int,int)), inPlayList, SLOT(selectRow(int)));
        QObject::connect(inPlayList, SIGNAL(doubleClicked(QModelIndex)), MusicApplicationByQtClass, SLOT(MusicPlayInPL()));
        QObject::connect(NextButton, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(NextPlay()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(SearchMusic()));
        QObject::connect(isRandomCheck, SIGNAL(stateChanged(int)), MusicApplicationByQtClass, SLOT(SetIsRandom()));
        QObject::connect(NoLoop, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(SetLoop()));
        QObject::connect(totalLoop, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(SetLoop()));
        QObject::connect(curLoop, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(SetLoop()));
        QObject::connect(PreButton, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(PrePlay()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MusicApplicationByQtClass, SLOT(MakeEmpty()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MusicApplicationByQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *MusicApplicationByQtClass)
    {
        MusicApplicationByQtClass->setWindowTitle(QCoreApplication::translate("MusicApplicationByQtClass", "MusicApplicationByQt", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MusicApplicationByQtClass", "\353\252\250\353\223\240 \352\263\241", nullptr));
        AddMusic->setText(QCoreApplication::translate("MusicApplicationByQtClass", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("MusicApplicationByQtClass", "Open File", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MusicApplicationByQtClass", "Save", nullptr));
        QTableWidgetItem *___qtablewidgetitem = MusicList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\263\240\354\234\240\353\262\210\355\230\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = MusicList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\240\234\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = MusicList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\260\200\354\210\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = MusicList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\221\352\263\241\352\260\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = MusicList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\245\353\245\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = MusicList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\254\354\203\235\355\232\237\354\210\230", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\353\252\250\353\223\240 \352\263\241 \354\202\255\354\240\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(song), QCoreApplication::translate("MusicApplicationByQtClass", "\353\205\270\353\236\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = inPlayList->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\263\240\354\234\240\353\262\210\355\230\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = inPlayList->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\240\234\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = inPlayList->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\260\200\354\210\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = inPlayList->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\254\354\203\235\355\232\237\354\210\230", nullptr));
        PL_DeleteButton->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\254\354\203\235\353\252\251\353\241\235 \354\202\255\354\240\234", nullptr));
        PL_AddButton->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\203\210 \354\236\254\354\203\235\353\252\251\353\241\235 \354\203\235\354\204\261", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(playlist_tab), QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\254\354\203\235\353\252\251\353\241\235", nullptr));
        searchRange->setItemText(0, QCoreApplication::translate("MusicApplicationByQtClass", "\355\206\265\355\225\251\352\262\200\354\203\211", nullptr));
        searchRange->setItemText(1, QCoreApplication::translate("MusicApplicationByQtClass", "\352\263\240\354\234\240\353\262\210\355\230\270", nullptr));
        searchRange->setItemText(2, QCoreApplication::translate("MusicApplicationByQtClass", "\354\240\234\353\252\251", nullptr));
        searchRange->setItemText(3, QCoreApplication::translate("MusicApplicationByQtClass", "\352\260\200\354\210\230", nullptr));
        searchRange->setItemText(4, QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\245\353\245\264", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\262\200\354\203\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = searchResult->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\263\240\354\234\240\353\262\210\355\230\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = searchResult->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\240\234\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = searchResult->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\260\200\354\210\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = searchResult->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\221\352\263\241\352\260\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = searchResult->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\245\353\245\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Search), QCoreApplication::translate("MusicApplicationByQtClass", "\352\262\200\354\203\211", nullptr));
        debuglable->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MusicApplicationByQtClass", "\354\236\254\354\203\235 \354\244\221\354\235\270 \352\263\241\354\235\264 \354\227\206\354\212\265\353\213\210\353\213\244", nullptr));
        pic_music->setText(QString());
        curMusicTitle->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\354\240\234\353\252\251", nullptr));
        curMusicArtist->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\352\260\200\354\210\230", nullptr));
        curMusiclyric->setHtml(QCoreApplication::translate("MusicApplicationByQtClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'HY\353\202\230\353\254\264M'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim';\">\352\260\200\354\202\254</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim';\"><br /></p></body></html>", nullptr));
        NextButton->setText(QCoreApplication::translate("MusicApplicationByQtClass", ">", nullptr));
        PreButton->setText(QCoreApplication::translate("MusicApplicationByQtClass", "<", nullptr));
        isRandomCheck->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\353\236\234\353\215\244 \354\236\254\354\203\235", nullptr));
        curLoop->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\353\260\230\353\263\265\354\236\254\354\203\235(\355\230\204\354\236\254)", nullptr));
        totalLoop->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\353\260\230\353\263\265\354\236\254\354\203\235(\354\240\204\354\262\264)", nullptr));
        NoLoop->setText(QCoreApplication::translate("MusicApplicationByQtClass", "\353\260\230\353\263\265X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicApplicationByQtClass: public Ui_MusicApplicationByQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICAPPLICATIONBYQT_H
