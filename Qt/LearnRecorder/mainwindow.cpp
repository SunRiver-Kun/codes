#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    starttime = QDateTime::currentDateTime();
    todayindex = starttime.date().dayOfWeek() - 1;

    ui->setupUi(this);
    Init();

    //Debug
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenExplorer()
{
    QDesktopServices::openUrl( QUrl::fromLocalFile( QDir::currentPath() ) );
}

void MainWindow::OpenLabelsExplorer()
{
    QProcess* process = new QProcess(this);
    process->start("notepad.exe "+labelpath);

}

void MainWindow::SaveData()
{
    QDir path(savepath);
    QString savefile = savepath+ "data_" + QDate::currentDate().toString("yyMMdd");
    if(!path.exists())
    {
        QDir::current().mkdir(savepath);
    }

    QFile file(savefile);
    file.open(QFile::WriteOnly);
    QDataStream fout(&file);
    UpdateTimeLabel();
    for (int i = 0; i < 7; ++i)
    {
        fout << studytimes[i];
    }
    fout << ui->tx_target->toPlainText() << ui->tx_progress->toPlainText();

    file.close();
}

void MainWindow::LoadLastData()
{
    QDir path(savepath);
    if(!path.exists()) {return;}
    QString savefile = savepath;
    auto&& names = path.entryList(QDir::Filter::Files,QDir::SortFlag::Name);
    bool ok = false;
    for(auto&& it = names.rbegin(); it!=names.rend(); ++it)
    {
        if(it->startsWith("data_"))
        {
            ok = true;
            savefile += *it;
            break;
        }
    }
    if(!ok) {return;}
    QFile file(savefile);
    if( !file.open(QFile::ReadOnly) ) {return;}
    QDataStream fin(&file);
    for (int i = 0; i < 7; ++i)
    {
        fin >> studytimes[i];
    }
    QString str;
    fin >> str;
    ui->tx_target->setText(str);
    fin >> str;
    ui->tx_progress->setText(str);

    file.close();
    UpdateTimeLabel();
}

void MainWindow::LoadData()
{

    QString savefile = QFileDialog::getOpenFileName(this,"加载数据",savepath);
    if(!QFileInfo(savefile).fileName().startsWith("data_"))
    {
        QMessageBox::warning(this,"警告","文件选择错误，请选择"+savepath+"下的文件");
        return;
    }

    QFile file(savefile);
    if( !file.open(QFile::ReadOnly) ) {return;}
    QDataStream fin(&file);
    for (int i = 0; i < 7; ++i)
    {
        fin >> studytimes[i];
    }
    QString str;
    fin >> str;
    ui->tx_target->setText(str);
    fin >> str;
    ui->tx_progress->setText(str);

    file.close();
    UpdateTimeLabel();
}


void MainWindow::SetLabelTop(QString str)
{
    ui->lb_top->setText(str);
}

void MainWindow::SetLabelTop()
{
    const QString defultstr = "好好学习,天天向上";

    QFile file(labelpath);
    if(!file.open(QFile::ReadOnly))
    {
        SetLabelTop(defultstr);
        if(! file.exists() &&  file.open(QFile::WriteOnly))
        {
            QTextStream fout(&file);
            fout << defultstr+'\n';
            file.close();
            return;
        }
    }
    QTextStream fout(&file);
    QVector<QString> labels;
    while(!fout.atEnd())
    {
        labels.push_back(fout.readLine());
    }
    SetLabelTop( labels.size() ? labels[rand()%labels.size()] : defultstr );
    file.close();
}

void MainWindow::TrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::ActivationReason::DoubleClick:
        this->show();
        if(charttype=="pie") { SetPieChart(); }
        else if(charttype=="line") { SetLineChart(); }
        else { SetBarChart(); }

        break;
    default:
        break;
    }
}

//Slots for drawing chart
void MainWindow::SetPieChart()
{
    QPieSeries* series = new QPieSeries(chart);
    for (int i = 0; i < 7; ++i)
    {
        QPieSlice* slice = new QPieSlice("",studytimes[i],series);
        series->append(slice);
    }
    qreal sum = series->sum();
    auto slices = series->slices();
    for (int i = 0; i < 7; ++i)
    {
        float scale = int( slices[i]->value()/sum * 1000) / 10.0f;
        slices[i]->setLabel(GetDayNameFromNum(i+1)+" "+QString::number(scale) + "%");
    }

    charttype = "pie";
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->createDefaultAxes();
    series->setLabelsVisible();

}

void MainWindow::SetLineChart()
{
    QLineSeries* series = new QLineSeries(chart);
    for (int i = 0; i < 7; ++i)
    {
        series->append(static_cast<qreal>(i+1),studytimes[i]);
    }
    series->setPointsVisible();
    series->setPointLabelsVisible();

    charttype = "line";
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->createDefaultAxes();
    auto&& axes = chart->axes(Qt::Horizontal | Qt::Vertical,series);
    axes.first()->setRange(1,7);
    axes.back()->setMin(0);
}

void MainWindow::SetBarChart()
{
    QBarSeries* series = new QBarSeries(chart);
    QBarSet* set = new QBarSet("",series);
    for (int i = 0; i < 7; ++i)
    {
        set->append(studytimes[i]);
        series->append(set);
    }
    series->setLabelsVisible();
    charttype = "bar";
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->createDefaultAxes();
}

void MainWindow::UpdateTimeLabel()
{
    auto&& current = QTime::currentTime();
    auto&& start = starttime.time();
    studytimes[todayindex] = current.hour()-start.hour() + (current.minute()-start.minute())/60.0;
    qreal hsum = 0.0;
    for (int i = 0; i <= todayindex; ++i)
    {
        hsum += studytimes[i];
    }

    ui->lb_down->setText("开始时间："+start.toString()+" 学习时长："+QString::number(studytimes[todayindex]*60)+"min 总时长："+QString::number(hsum)+"h");
}

void MainWindow::Generator()
{
    QString outpath = QFileDialog::getSaveFileName(this,"生成文件","","文本文件 (*.txt)");
    QFile file(outpath);
    SaveData();
    if(outpath.isEmpty() || !file.open(QFile::WriteOnly)) { return; }

    QTextStream fout(&file);
    fout.setCodec("UTF-8");

    auto&& data = QDir(savepath).entryList(QDir::Filter::Files,QDir::SortFlag::Name);
    QString endfile = "data_" + QDate::currentDate().addDays(-todayindex-1).toString("yyMMdd");

    qreal temp;
    QString str;

    for(auto&& it = data.rbegin(); it!=data.rend() && *it!=endfile; ++it)
    {
        str = *it;
        str.remove(0,5);
        int n = str.toInt();
        int index = todayindex - (QDate::currentDate().toString("yyMMdd").toInt() - n);
        QDate date(2000+n/10000,(n/100)%100,n%100);

        fout << date.toString("dddd yyyy.MM.dd") << tr("\t学习时间：")<< studytimes[index] << tr("h\n学习目标：\n");

        QFile tempfile(savepath + *it);
        if(!tempfile.open(QFile::ReadOnly)) { continue; }
        QDataStream f(&tempfile);
        for(int i=0;i<7;++i) { f >> temp; }
        f >> str;
        fout << str << tr("\n\n完成进度：\n");
        f >> str;
        fout << str << tr("\n\n");
        tempfile.close();
    }

    file.close();
}

//Init Widgets
void MainWindow::Init()
{
    LoadLastData();
    TrayInit();
    UIConnectInit();
    SetLabelTop();
    UpdateTimeLabel();
    TimerInit();
    ChartInit();
}

void MainWindow::TrayInit()
{
    //tray
    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(QPixmap("trayicon.png")));
    tray->setToolTip("学习使我快乐!");
    tray->show();
    //tray->showMessage("title","msg");

    //traymenu
    QMenu* traymenu = new QMenu(this);
    QAction* minimizeAction = new QAction("最小化",this);
    QAction* maximizeAction = new QAction("最大化",this);
    QAction* showAction = new QAction("显示界面",this);
    QAction* closeAction = new QAction("关闭程序",this);
    traymenu->addAction(minimizeAction);
    traymenu->addAction(maximizeAction);
    traymenu->addAction(showAction);
    traymenu->addSeparator();
    traymenu->addAction(closeAction);

    tray->setContextMenu(traymenu);

    connect(minimizeAction,SIGNAL(triggered()),this,SLOT(hide()));
    connect(maximizeAction,&QAction::triggered,[this](){
        this->show();
        this->showMaximized();
    });
    connect(showAction,SIGNAL(triggered()),this,SLOT(show()));
    connect(closeAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(TrayActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::ChartInit()
{
    chart = new QChart();
    QChartView* view = new QChartView(chart,this);
    view->setRenderHint(QPainter::RenderHint::Antialiasing);
    ui->hMidLayout->insertWidget(0,view);
    SetBarChart();
    chart->legend()->hide();
    chart->setTitle("本周学习时间");

}

void MainWindow::TimerInit()
{
    timer = new QTimer(this);
    timer->setInterval(60*1000);
    timer->setSingleShot(false);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpdateTimeLabel()));
    timer->start();
}

void MainWindow::UIConnectInit()
{
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(LoadData()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(SaveData()));

    connect(ui->actionBar_Chart,SIGNAL(triggered()),this,SLOT(SetBarChart()));
    connect(ui->actionPie_Chart,SIGNAL(triggered()),this,SLOT(SetPieChart()));
    connect(ui->actionLine_Chart,SIGNAL(triggered()),this,SLOT(SetLineChart()));

    connect(ui->actionOpenIn_Explorer,SIGNAL(triggered()),this,SLOT(OpenExplorer()));
    connect(ui->actionOpenLabelsFile,SIGNAL(triggered()),this,SLOT(OpenLabelsExplorer()));

    connect(ui->actiongenerator,SIGNAL(triggered()),this,SLOT(Generator()));
}

QString MainWindow::GetDayNameFromNum(int index) const
{
    switch (index)
    {
    case 0: return "星期日";
    case 1: return "星期一";
    case 2: return "星期二";
    case 3: return "星期三";
    case 4: return "星期四";
    case 5: return "星期五";
    case 6: return "星期六";
    default:
        return GetDayNameFromNum(qAbs(index)%7);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    SaveData();
    this->hide();
}

