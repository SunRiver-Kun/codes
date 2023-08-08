#pragma once

#include <QtWidgets/QMainWindow>
#include <QtMultimedia/QtMultimedia>
#include <QtWidgets/QtWidgets>
#include <QtSql/QtSql>
#include "ui_MusicPlayer.h"

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = Q_NULLPTR);
public Q_SLOTS:
    void OpenDir();
    void NextMusic();
    void LastMusice();
    void BeginOrStop();
    
public:
    void OpenDateBase(QString host, QString database, QString user, QString password);

    Ui::MusicPlayerClass ui;
    QString basepath;
    QMediaPlayer* player;
    QMediaPlaylist* plist;
    QLineEdit* text;
    QPushButton* open_button;
    QPushButton* last_button;
    QPushButton* play_button;
    QPushButton* next_button;
    QSqlDatabase db;
};
