  #ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QAxWidget>
#include <QtCharts>
#include <QMouseEvent>
#include <time.h>
#include "server.h"
#include<QQueue>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSound>
#include <QTableWidget>
#include <QStringList>

QT_CHARTS_USE_NAMESPACE
namespace Ui {
  class Form;
}

class Form : public QWidget
{
  Q_OBJECT

public:
  Ui::Form *ui;
  explicit Form(QWidget *parent = nullptr);
  QString str1="手动报警 未处理";
  QString strTEM="TDS异常报警 未处理";
  QString str2="异常报警 已处理";
  void singalslot();
  void timerEvent(QTimerEvent *event);
  void RefreshSerialPort(int index);
  QQueue<float> queue;
  QQueue<float> queue2;
  QQueue<float> queue3;
  QQueue<float> queue4;
  QSerialPort *serial;
  int k=0;
  int i=0;
  int warn=0;
  QString TDSthreshold;
  QString PHthreshold;
  QString TEMthreshold;
  QString TUthreshold;
   float TDSv=99;
   float PHv=14;
   float TEMv=30;
   float TUv=40;
   QString TDSset;
   QString TEMset;
   QString TUset;
   QString PHset;
  ~Form();

signals:

public slots:
  void on_GPS_clicked();

  void on_linechart_clicked();

  void on_mainexit_btn_clicked();

  void on_Lora_clicked();

  void on_move_clicked();

  void on_mainmin_btn_clicked();

  void on_test_clicked();

  void on_go_clicked();

  void on_back_clicked();

  void on_left_clicked();

  void on_right_clicked();

  void on_clear_clicked();

  void on_warning_clicked();

  void on_warnopen_btn_clicked();

  void on_warnclose_btn_clicked();

  void on_check_clicked();

  void on_analysis_clicked();

  void new_connect(QString Ip,quint16 port);

  void readmessage(QString);

  void updateline1(QString);

  void updateline2(QString);

  void updateline3(QString);

  void updateline4(QString);

private slots:
  void on_clear_1_clicked();

  void on_history_clicked();

  void on_thresholdsetup_clicked();

  void on_tpower_clicked();

  void switchmode();

  void switch4G();

  void on_tcharge_clicked();

  void on_set_clicked();

  void on_select_clicked();

  void on_set_diy_clicked();

private:
  //图的对象
  QChart *chart_TDS = new QChart();
  QChart *chart_TEM = new QChart();
  QChart *chart_PH = new QChart();
  QChart *chart_TU = new QChart();
  //标识的对象
  QLineSeries *seriesTDS = new QLineSeries();
  QLineSeries *seriesTEM = new QLineSeries();
  QLineSeries *seriesPH = new QLineSeries();
  QLineSeries *seriesTU = new QLineSeries();
  //数据的对象
  QValueAxis *value_TDSx = new QValueAxis();
  QValueAxis *value_TDSy = new QValueAxis();

  QValueAxis *value_TEMx = new QValueAxis();
  QValueAxis *value_TEMy = new QValueAxis();

  QValueAxis *value_PHx = new QValueAxis();
  QValueAxis *value_PHy = new QValueAxis();

  QValueAxis *value_TUx = new QValueAxis();
  QValueAxis *value_TUy = new QValueAxis();

  //序列对象
  QLineSeries *series_TDS = new QLineSeries;
  QLineSeries *series_TEM = new QLineSeries;
  QLineSeries *series_PH = new QLineSeries;
  QLineSeries *series_TU = new QLineSeries;

  int xAxisData[10];
  int yAxisData[10];
  int oldxData[10];
  int oldyData[10];
  int m_x=10;
  int m_timerId;
  int m_lowPos;

  //窗口移动
  QPoint windowPos;
  QPoint mousePos;
  QPoint dPos;
  void mouseMoveEvent(QMouseEvent *event);//鼠标移动
  void mousePressEvent(QMouseEvent *event);//鼠标按下移动
  void linechartbuild();//折线图初始化

};

#endif // FORM_H
