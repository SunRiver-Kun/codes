#include "MusicPlayer.h"
#include <QtWidgets/QtWidgets>

#pragma execution_character_set("utf-8")
MusicPlayer::MusicPlayer(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("夏湾的播放器");
	resize(400, 100);
	
	db =  QSqlDatabase::addDatabase("QSQLITE");	//运行Qt自带数据库
	OpenDateBase("","Song.db","sa","123456");
	
	player = new QMediaPlayer(this);
	plist = new QMediaPlaylist;
	text = new QLineEdit(this);


	QHBoxLayout* layout = new QHBoxLayout();
	QVBoxLayout* vlayout = new QVBoxLayout();
	vlayout->addLayout(layout);

	//打开文件夹、上一曲、播放/暂停、下一曲
	open_button = new QPushButton(QIcon("./open.png"), "", this);
	last_button = new QPushButton(QIcon("./last.png"), "", this);
	play_button = new QPushButton(QIcon("./play.png"), "", this);
	next_button = new QPushButton(QIcon("./next.png"), "", this);

	last_button->setEnabled(false);
	play_button->setEnabled(false);
	next_button->setEnabled(false);

	connect(open_button, &QPushButton::clicked, this, &MusicPlayer::OpenDir);
	connect(last_button, SIGNAL(clicked()), this, SLOT(LastMusice()));
	connect(play_button, SIGNAL(clicked()), this, SLOT(BeginOrStop()));
	connect(next_button, SIGNAL(clicked()), this, SLOT(NextMusic()));
	connect(player, &QMediaPlayer::currentMediaChanged, [this] {
		this->text->setText(plist->currentMedia().canonicalUrl().fileName());
		});
	layout->addWidget(open_button);
	layout->addWidget(last_button);
	layout->addWidget(play_button);
	layout->addWidget(next_button);
	layout->addWidget(text);

	//搜索栏，索引播放
	layout = new QHBoxLayout();
	vlayout->addLayout(layout);
	layout->addWidget(new QLabel("搜索",this));
	QLineEdit* le_search = new QLineEdit("输入歌曲名进行搜索", this);
	layout->addWidget(le_search);
	connect(le_search, &QLineEdit::returnPressed, [this, le_search]() {
		QSqlQuery query(db);		
		QString str = "SELECT * FROM Song WHERE Name LIKE '%" + le_search->text() + "%'";
		if (query.exec(str))
		{
			str = "";
			while (query.next())
			{
				str += query.record().value("Name").toString() + ' '+
					query.record().value("SIndex").toString()+'\n';
			}
			QMessageBox::information(this, "查询结果", str);
		}
		else
		{
			QMessageBox::information(this, "查询结果", "未找到相关歌曲");
			qDebug() << query.lastError();
		}
		le_search->setText("");
	});
	
	layout->addWidget(new QLabel("索引播放", this));
	le_search = new QLineEdit("0", this);
	layout->addWidget(le_search);
	connect(player, &QMediaPlayer::currentMediaChanged, [this, le_search] {
		QString index = QString::number(plist->currentIndex());
		le_search->setText(index);
	});
	connect(le_search, &QLineEdit::returnPressed, [this, le_search]() {
		bool ok = false;
		int index = le_search->text().toInt(&ok);
		if (ok && index >= 0 && index < plist->mediaCount())
			plist->setCurrentIndex(index);
		else
		{
			QMessageBox::warning(this,"索引播放错误","无法定位到歌曲");
		}
	});

	//布局
	setLayout(vlayout);
	vlayout->setGeometry(rect());
}

void MusicPlayer::OpenDir()
{
	basepath = QFileDialog::getExistingDirectory(this);  //获取文件夹
	QDir dir(basepath);
	const auto& entryList = dir.entryList();
	player->stop();
	plist->clear();
	QSqlQuery query(db);
	if (!query.exec("DELETE FROM Song")) { qDebug() << query.lastError(); }
	int index = 0;
	for (auto& v : entryList)
	{
		if (v.endsWith(".mp3") || v.endsWith(".wav"))
		{
			plist->addMedia(QUrl::fromLocalFile(basepath + '/' + v));
			QString str = "INSERT INTO Song(Name,SIndex) VALUES('" + v +"',"+QString::number(index++)+")";
			if (!query.exec(str)) { qDebug() << query.lastError(); }
		}
			
	}
	if (plist->isEmpty())
	{
		QMessageBox::warning(this, "警告", "该目录无音乐文件");
		last_button->setEnabled(false);
		play_button->setEnabled(false);
		next_button->setEnabled(false);
		text->setText("");
		return;
	}

	plist->setCurrentIndex(0);
	player->setVolume(100);
	player->setPlaylist(plist);
	player->playlist();
	player->play();

	last_button->setEnabled(true);
	play_button->setEnabled(true);
	next_button->setEnabled(true);
	text->setText(plist->currentMedia().canonicalUrl().fileName());
}

void MusicPlayer::NextMusic()
{
	int index = (plist->currentIndex() + 1) % plist->mediaCount();
	plist->setCurrentIndex(index);
	player->play();
	text->setText(plist->currentMedia().canonicalUrl().fileName());
}

void MusicPlayer::LastMusice()
{
	int count = plist->mediaCount();
	int index = count - (count - plist->currentIndex() + 1) % count;
	plist->setCurrentIndex(index);
	player->play();
	text->setText(plist->currentMedia().canonicalUrl().fileName());
}

void MusicPlayer::BeginOrStop()
{
	if (player->state() == QMediaPlayer::State::PlayingState)
	{
		player->pause();
	}
	else
	{
		player->play();
	}
}

void MusicPlayer::OpenDateBase(QString host, QString database, QString user, QString password)
{
	//db.setHostName(host);			//服务器名	
	db.setDatabaseName(database);		//数据库名	
	db.setUserName(user);			//用户名	
	db.setPassword(password);			//密码		
	bool ok = db.open();
	if (!ok)	//没有数据库会自己建个
	{
		qDebug() << "error info :" << db.lastError();
	}
	else
	{
		QSqlQuery query(db);
		if (query.exec("SELECT * FROM SONG")) 
		{
			query.exec("DROP TABLE SONG");
		} 
		QString creatTableStr = "CREATE TABLE Song( \
			Name char(255) NOT NULL,\
			SIndex char(255) NOT NULL\
			)";
			
		query.prepare(creatTableStr);
		if (!query.exec()) {
			qDebug() << "query error :" << query.lastError();
		}
	}
}

