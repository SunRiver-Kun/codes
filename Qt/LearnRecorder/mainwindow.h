#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QtCharts/QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ReadLastData();

public Q_SLOTS:
    void SaveData();
    void LoadLastData();
    void LoadData();
    void SetLabelTop(QString str);
    void SetLabelTop();

    void OpenExplorer();
    void OpenLabelsExplorer();

    void SetPieChart();
    void SetLineChart();
    void SetBarChart();

    void UpdateTimeLabel();

    void Generator();

private Q_SLOTS:
    void TrayActivated(QSystemTrayIcon::ActivationReason reason);


private:
    void Init();
    void TrayInit();
    void ChartInit();
    void TimerInit();
    void UIConnectInit();
    QString GetDayNameFromNum(int index) const;

    Ui::MainWindow *ui;
    QSystemTrayIcon* tray;
    QChart* chart;
    QString charttype;
    QTimer* timer;

    qreal studytimes[7] = {};      //从星期一开始, h
    int todayindex = 0;

    QDateTime starttime;
    const QString savepath = "session/";
    const QString labelpath = "labels.txt";
    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
