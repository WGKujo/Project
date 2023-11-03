#include "form.h"
#include "ui_form.h"
#include<QDebug>
#include<QChartView>
QT_CHARTS_USE_NAMESPACE
Form::Form(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Form)
{
  ui->setupUi(this);
  singalslot();
  ui->Lora->hide();
  ui->move->hide();
  //  ui->check->hide();
  //ui->analysis->hide();
  //ui->move->hide();
  ui->TDSthreshold->append("99");
  ui->TEMthreshold->append("99");
  ui->PHthreshold->append("99");
  ui->TUthreshold->append("99");
  //  ui->TDSthreshold->hide();
  //  ui->TDS_threshold->hide();
  //  ui->TEMthreshold->hide();
  //  ui->TEM_threshold->hide();
  //  ui->TUthreshold->hide();
  //  ui->TU_threshold->hide();
  //  ui->PHthreshold->hide();
  //  ui->PH_threshold->hide();
  //  ui->thresholdsetup->hide();
  //  ui->threshold->hide();
  setWindowFlags(Qt::FramelessWindowHint | windowFlags());
  QString filename("E:/Qt/Sony_water/res/3-1.png");
  QImage* img=new QImage;
  if(! ( img->load(filename) ) ) //加载登录图片
    {
      qDebug()<<"打开图片错误";
      delete img;
      return;
    }
  ui->icon2->setPixmap(QPixmap::fromImage(*img));

  QString filename1("E:/Qt/Sony_water/res/load_1.png");//加载视频图片
  QImage* img1=new QImage;
  if(! ( img1->load(filename1) ) ) //加载图像
    {
      qDebug()<<"打开图片错误";
      delete img1;
      return;
    }
  ui->gif->setPixmap(QPixmap::fromImage(*img1));

  linechartbuild();//折线图初始化
  ui->stackedWidget->setCurrentIndex(0);//状态界面
  ui->power->hide();

  QString filename2("E:/Qt/Sony_water/res/warn.png");//加载警报图片
  QImage* img2=new QImage;
  if(! ( img2->load(filename2) ) ) //加载图像
    {
      qDebug()<<"打开图片错误";
      delete img2;
      return;
    }
  ui->warning_icon->setPixmap(QPixmap::fromImage(*img2));
  ui->warning_icon->hide();

  for (int i=10;i>0;i--) {
      queue.push_back(i);
      queue2.push_back(i);
      queue3.push_back(i);
      queue4.push_back(i);
    }
  ui->comboBox->addItem("WIFI模式");
  ui->comboBox->addItem("Lora模式");
  ui->comboBox->addItem("4G模式");

  ui->env_set->addItem("默认场景");
  ui->env_set->addItem("淡水养殖");
  ui->env_set->addItem("游泳池");
  ui->env_set->addItem("海水养殖");
}

Form::~Form()
{
  delete ui;
}

void Form::on_GPS_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
  ui->axWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));
  ui->axWidget->setFocusPolicy(Qt::StrongFocus);
  ui->axWidget->setProperty("DisplayAlerts",false);
  ui->axWidget->setProperty("DisplayScrollBars",true);
  ui->axWidget->dynamicCall("Navigate(const QString&)","https://map.baidu.com/@11533298.829125442,3596827.1544263777,17.7z");
}

void Form::on_linechart_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
  m_timerId=startTimer(3000);//更新时间
}

void Form::on_mainexit_btn_clicked()
{
  this->close();
}

void Form::on_Lora_clicked()
{
  ui->stackedWidget->setCurrentIndex(4);
}

void Form::mousePressEvent(QMouseEvent *event)
{
  this->windowPos = this->pos();       // 获得部件当前位置
  this->mousePos = event->globalPos(); // 获得鼠标位置
  this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
  this->move(event->globalPos() - this->dPos);
}

void Form::linechartbuild()
{
  chart_TDS->setTitle("浊度变化图");
  chart_TEM->setTitle("温度变化图");
  chart_PH->setTitle("PH变化图");
  chart_TU->setTitle("TU变化图");
  //绑定标识名
  seriesTDS->setName("TDS");
  seriesTEM->setName("TEM");
  seriesPH->setName("PH");
  seriesTU->setName("TU");
  //绑定折线
  chart_TDS->addSeries(seriesTDS);
  chart_TEM->addSeries(seriesTEM);
  chart_PH->addSeries(seriesPH);
  chart_TU->addSeries(seriesTU);
  //设置xy
  //value_TDSx->setTitleText("每小时");
  value_TDSy->setTitleText("mg/L");//y标题
  value_TDSx->setRange(0, 10);//x的范围
  value_TDSx->setTickCount(11);//x的主刻度个数
  value_TDSx->setMinorTickCount(1);
  //value_TDSx->setLineVisible(true); //设置轴线和刻度线可见性
  //value_TDSx->setGridLineVisible(false); //设置网格线可见性
  value_TDSy->setRange(0.0f, 500.0f);//y的范围
  value_TDSy->setTickCount(11);//y的主刻度个数
  value_TDSy->setMinorTickCount(1);


  value_TEMy->setTitleText("温度");
  value_TEMx->setRange(0, 10);
  value_TEMx->setTickCount(11);
  value_TEMx->setMinorTickCount(1);
  value_TEMy->setRange(5.0f, 45.0f);
  value_TEMy->setTickCount(9);
  value_TEMy->setMinorTickCount(1);


  value_PHy->setTitleText("PH值");
  value_PHx->setRange(0, 10);
  value_PHx->setTickCount(11);
  value_PHx->setMinorTickCount(1);
  value_PHy->setRange(0, 14);
  value_PHy->setTickCount(8);
  value_PHy->setMinorTickCount(2);


  value_TUy->setTitleText("浊度");
  value_TUx->setRange(0, 10);
  value_TUx->setTickCount(11);
  value_TUx->setMinorTickCount(1);
  value_TUy->setRange(0, 30);
  value_TUy->setTickCount(11);
  value_TUy->setMinorTickCount(1);

  //设置显示
  ui->graphicsView->setChart(chart_TDS);//将chart对象设置到控件上
  ui->graphicsView_2->setChart(chart_TEM);
  ui->graphicsView_3->setChart(chart_PH);
  ui->graphicsView_4->setChart(chart_TU);

  ui->graphicsView->setRenderHint(QPainter::Antialiasing);//抗锯齿
  ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView_3->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView_4->setRenderHint(QPainter::Antialiasing);

  chart_TDS->addSeries(seriesTDS);
  chart_TEM->addSeries(seriesTEM);
  chart_PH->addSeries(seriesPH);
  chart_TU->addSeries(seriesTU);

  chart_TDS->setAxisX(value_TDSx,seriesTDS);
  chart_TDS->setAxisY(value_TDSy,seriesTDS);
  chart_TEM->setAxisX(value_TEMx,seriesTEM);
  chart_TEM->setAxisY(value_TEMy,seriesTEM);
  chart_PH->setAxisX(value_PHx,seriesPH);
  chart_PH->setAxisY(value_PHy,seriesPH);
  chart_TU->setAxisX(value_TUx,seriesTU);
  chart_TU->setAxisY(value_TUy,seriesTU);

  srand((unsigned)time(NULL));
}
void Form::timerEvent(QTimerEvent *event)
{
  if(event->timerId()==m_timerId){
      //      int num_TDS=(rand() % (50-30+ 1) + 30);
      //      int num_TEM=(rand() % (30-25+ 1) + 25);
      //      int num_TU=(rand() % (8-4+ 1) + 4);
      //      int num_PH=(rand() % (6-3+ 1) + 3);

      //      qDebug()<<"m_x:"<<m_x<<"  "<<"m_lowPos:"<<m_lowPos;
      //     seriesTDS->append(m_x,num_TDS);
      //     seriesTEM->append(m_x,num_TEM);
      //     seriesTU->append(m_x,num_TU);
      //     seriesPH->append(m_x,num_PH);
      //      while(queue.size()>5)
      //        {

      //        }
      seriesTDS->append(m_x,queue.head());
      seriesPH->append(m_x,queue2.head());
      seriesTEM->append(m_x,queue3.head());
      seriesTU->append(m_x,queue4.head());
      m_x++;
      //     qDebug()<<"num_TDS:"<<num_TDS;
      //     qDebug()<<"num_TEM:"<<num_TEM;
      //     qDebug()<<"num_TU:"<<num_TU;
      //     qDebug()<<"num_PH:"<<num_PH;

      value_TDSx->setRange(0,m_x);
      value_TEMx->setRange(0,m_x);
      value_TUx->setRange(0,m_x);
      value_PHx->setRange(0,m_x);
      if(m_x-10>0){
          //m_x=m_x-20;
          value_TDSx->setRange(m_x-10,m_x);
          value_TEMx->setRange(m_x-10,m_x);
          value_PHx->setRange(m_x-10,m_x);
          value_TUx->setRange(m_x-10,m_x);
        }

      QTableWidgetItem *item;
      QDateTime current_date_time =QDateTime::currentDateTime();
      QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");

      item = new QTableWidgetItem(current_date);
      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      ui->historytable->setItem(i,0,item);

      float x=queue.head();
      QString TDS=QString::number(x);
      item = new QTableWidgetItem(TDS);
      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      ui->historytable->setItem(i,1,item);

      float x2=queue2.head();
      QString PH=QString::number(x2);
      item = new QTableWidgetItem(PH);
      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      ui->historytable->setItem(i,2,item);

      float x3=queue3.head();
      QString TEM=QString::number(x3);
      item = new QTableWidgetItem(TEM);
      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      ui->historytable->setItem(i,3,item);
      if(x>TDSv)
        {
          warn=1;
          qDebug()<<"TDS已报警"<<TDSv;
        }
//      if(x3>TEMv)
//        {
//          warn=1;
//          qDebug()<<"TEM已报警"<<TEMv;
//        }
      else
        {
          warn=0;
          qDebug()<<"未报警"<<TEMv;
        }
      if(warn==1)
        {
          QDateTime current_date_time =QDateTime::currentDateTime();
          QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
          ui->warn_label2->setText("已报警");
          ui->warning_icon->show();
          QSound::play("E:/Qt/Sony_water/res/warn.wav");
          QString tmp1=current_date+strTEM;
          ui->warntext->append(tmp1);
          item = new QTableWidgetItem("已报警");
          item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
          ui->historytable->setItem(i,5,item);
          ui->historytable->item(i,3)->setBackground(Qt::red);
          qDebug()<<"warn";
        }
      float x4=queue4.head();
      QString TU=QString::number(x4);
      item = new QTableWidgetItem(TU);
      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
      ui->historytable->setItem(i,4,item);
      i++;
      if(i==20){
          i=0;
        }
    }
}
void Form::on_move_clicked()
{
  ui->stackedWidget->setCurrentIndex(5);
}

void Form::on_mainmin_btn_clicked()
{
  this->setWindowState(Qt::WindowMinimized);
}

void Form::on_test_clicked()
{
  ui->state->append("设备连接成功");
}

void Form::on_go_clicked()
{
  ui->state->append("设备正在前进");
}

void Form::on_back_clicked()
{
  ui->state->append("设备正在后退");
}

void Form::on_left_clicked()
{
  ui->state->append("设备正在左转");
}

void Form::on_right_clicked()
{
  ui->state->append("设备正在右转");
}

void Form::on_clear_clicked()
{
  ui->state->clear();
}

void Form::on_warning_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
  QBarSet *set0 = new QBarSet("浊度");
  QBarSet *set1 = new QBarSet("温度");
  QBarSet *set2 = new QBarSet("PH");
  QBarSet *set3 = new QBarSet("TU");
  QBarSet *set4 = new QBarSet("手动");

  *set0 << 1 << 2 << 3 << 1 << 3 << 2;
  *set1 << 0 << 0<< 1 << 2 << 2 << 0;
  *set2 << 0 << 2 << 3 << 1 << 2 << 0;
  *set3 << 1 << 1 << 2 << 3 << 2 << 0;
  *set4 << 2 << 1 << 1 << 0 << 1 << 0;

  QBarSeries *series = new QBarSeries();
  series->append(set0);
  series->append(set1);
  series->append(set2);
  series->append(set3);
  series->append(set4);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("近半年报警记录");
  chart->setAnimationOptions(QChart::SeriesAnimations);

  QStringList categories;
  categories << "一月" << "二月" << "三月" << "四月" << "五月" << "六月";
  QBarCategoryAxis *axisX = new QBarCategoryAxis();
  axisX->append(categories);
  chart->addAxis(axisX, Qt::AlignBottom);
  series->attachAxis(axisX);

  QValueAxis *axisY = new QValueAxis();
  axisY->setRange(0,5);//纵坐标范围
  axisY->setTickCount(6);//0-5分六格
  chart->addAxis(axisY, Qt::AlignLeft);//对齐
  series->attachAxis(axisY);

  chart->legend()->setVisible(true);//可见
  chart->legend()->setAlignment(Qt::AlignBottom);

  ui->warnchart->setChart(chart);
}

void Form::on_warnopen_btn_clicked()
{
  warn=1;
  if(warn==1)
    {
      QDateTime current_date_time =QDateTime::currentDateTime();
      QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
      ui->warn_label2->setText("已报警");
      ui->warning_icon->show();
      QSound::play("E:/Qt/Sony_water/res/warn.wav");
      QString tmp1=current_date+str1;
      ui->warntext->append(tmp1);
    }
}

void Form::on_warnclose_btn_clicked()
{
  warn=-1;
  if(warn<0)
    {
      QDateTime current_date_time =QDateTime::currentDateTime();
      QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");//年 月 日 小时 分 秒
      ui->warn_label2->setText("未报警");
      ui->warning_icon->hide();
      QString tmp1=current_date+str2;
      ui->warntext->append(tmp1);
    }
}

void Form::on_check_clicked()
{
  ui->stackedWidget->setCurrentIndex(7);
}

void Form::on_analysis_clicked()
{
  ui->stackedWidget->setCurrentIndex(6);
}

void Form::singalslot()
{
  connect(ui->connect,&QPushButton::clicked,this,[&](){
      server *s=new server;
      connect(s,&server::new_connect,this,&Form::new_connect);
      connect(s,&server::readmessage,this,&Form::readmessage);
      connect(s,&server::switchmode,this,&Form::switchmode);
      connect(s,&server::switch4G,this,&Form::switch4G);
      connect(s,&server::updateline1,this,&Form::updateline1);
      connect(s,&server::updateline2,this,&Form::updateline2);
      connect(s,&server::updateline3,this,&Form::updateline3);
      connect(s,&server::updateline4,this,&Form::updateline4);
      connect(ui->tTDS,&QPushButton::clicked,s,&server::testTDS);
      connect(ui->tTEM,&QPushButton::clicked,s,&server::testTEM);
      connect(ui->tTU,&QPushButton::clicked,s,&server::testTU);
      connect(ui->tPH,&QPushButton::clicked,s,&server::testPH);
      connect(ui->linechart,&QPushButton::clicked,s,&server::start);
    });

}

void Form::new_connect(QString IP,quint16 port)
{
  ui->equipmentedit->append(IP);
  ui->power->show();
  ui->equipmenttext->setText("已连接");
}

void Form::readmessage(QString msg)
{
  ui->equipmentedit->append(msg);
}

void Form::on_clear_1_clicked()
{
  ui->equipmentedit->clear();
}

void Form::updateline1(QString msg)
{
  if(queue.size()>10)
    {
      queue.clear();
    }
  float i = msg.toFloat();
  qDebug()<<i;
  //if(i<100&&i>0)
  queue.enqueue(i);
  qDebug()<<queue;
}

void Form::updateline2(QString msg)
{
  if(queue2.size()>10)
    {
      queue2.clear();
    }
  float i = msg.toFloat();
  qDebug()<<i;
  if(i<100&&i>0)
    {
      queue2.enqueue(i);
    }
  qDebug()<<queue2;
}

void Form::updateline3(QString msg)
{
  if(queue3.size()>10)
    {
      queue3.clear();
    }
  float i = msg.toFloat();
  qDebug()<<i;
  if(i<100&&i>0)
    {
      queue3.enqueue(i);
    }
  qDebug()<<queue3;
}

void Form::updateline4(QString msg)
{
  qDebug()<<msg<<"TU数据";
  if(queue4.size()>10)
    {
      queue4.clear();
    }
  float i = msg.toFloat();
  qDebug()<<i<<"TU数据float";
  queue4.enqueue(i);
  qDebug()<<queue4<<"TU容器";
}



void Form::on_history_clicked()
{
  QStringList headerText;
  headerText<<"时间"<<"TDS"<<"PH"<<"TEM"<<"TU"<<"报警状态";
  //  QTableWidget TableWidget(4,6,this);
  ui->historytable->setColumnCount(headerText.count());
  ui->historytable->setRowCount(20);
  ui->historytable->setHorizontalHeaderLabels(  QStringList()<<"时间"<<"TDS"<<"PH"<<"TEM"<<"TU"<<"报警状态");
  ui->historytable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自动填满
  ui->historytable->setFont(QFont("楷体",17));
  ui->historytable->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
  ui->historytable->horizontalHeader()->setHighlightSections(false);         //点击表头时不对表头光亮
  ui->historytable->horizontalHeader()->setFixedHeight(100);
  ui->historytable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:lightblue;font-size: 30pt;}");
  ui->historytable->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:lightblue;}");
  //ui->historytable->setItem(0,0,new QTableWidgetItem("1"));
  //  QTableWidgetItem *item;
  //  QDateTime current_date_time =QDateTime::currentDateTime();
  //  QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
  //  for (int i=0;i<20;i++)
  //    {
  //      item = new QTableWidgetItem(current_date);
  //      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  //      ui->historytable->setItem(i,0,item);
  //    }
  //  for (int i=0;i<20;i++) {
  //      float x=queue.head();
  //      QString TDS=QString::number(x);
  //      item = new QTableWidgetItem(TDS);
  //      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  //      ui->historytable->setItem(i,1,item);
  //    }
  //  for (int i=0;i<20;i++) {
  //      float x2=queue2.head();
  //      QString TEM=QString::number(x2);
  //      item = new QTableWidgetItem(TEM);
  //      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  //      ui->historytable->setItem(i,2,item);
  //    }
  //  for (int i=0;i<20;i++) {
  //      float x3=queue3.head();
  //      QString PH=QString::number(x3);
  //      item = new QTableWidgetItem(PH);
  //      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  //      ui->historytable->setItem(i,3,item);
  //    }
  //  for (int i=0;i<20;i++) {
  //      float x4=queue4.head();
  //      QString TU=QString::number(x4);
  //      item = new QTableWidgetItem(TU);
  //      item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  //      ui->historytable->setItem(i,4,item);
  //    }
  ui->stackedWidget->setCurrentIndex(8);

}

void Form::on_thresholdsetup_clicked()
{
  TDSthreshold=ui->TDSthreshold->document()->toPlainText();
  PHthreshold=ui->PHthreshold->document()->toPlainText();
  TEMthreshold=ui->TEMthreshold->document()->toPlainText();
  TUthreshold=ui->TUthreshold->document()->toPlainText();
  TDSv=TDSthreshold.toFloat();
  PHv=PHthreshold.toFloat();
  TEMv=TEMthreshold.toFloat();
  qDebug()<<"设置报警温度为:"<<TEMv;
  TUv=TUthreshold.toFloat();
}


void Form::on_tpower_clicked()
{
  ui->power->setValue(80);
}

void Form::switchmode()
{
  QString lora="     切换为Lora模式成功       ";
  QMessageBox::information(NULL,"提示",lora,QMessageBox::Yes);
  ui->comboBox->setCurrentIndex(1);
}

void Form::switch4G()
{
  QString lora="     切换为4G模式成功       ";
  QMessageBox::information(NULL,"提示",lora,QMessageBox::Yes);
  ui->comboBox->setCurrentIndex(2);
}


void Form::on_tcharge_clicked()
{
  QString test="     太阳能充电功能正常       ";
  QMessageBox::information(NULL,"提示",test,QMessageBox::Yes);
}

void Form::on_set_clicked()
{
  if(ui->env_set->currentText()=="默认场景")
    {
      ui->envTDS->setText("25.00 - 100.00");
      ui->envPH->setText("6.50 - 8.50");
      ui->envTEM->setText("35.00 - 38.00");
      ui->envTU->setText("2.00 - 5.00");
      TDSv=99.00;
      TEMv=99.50;
      PHv=99.00;
      TUv=99.00;
      QString filename1("E:/Qt/Sony_water/res/water1.png");//加载图片
      QImage* img3=new QImage;
      if(! ( img3->load(filename1) ) ) //加载图像
        {
          qDebug()<<"打开图片错误";
          delete img3;
          return;
        }
      ui->pitcure->setPixmap(QPixmap::fromImage(*img3));
    }
  if(ui->env_set->currentText()=="淡水养殖")
    {
      ui->envTDS->setText("200.00 - 300.00");
      ui->envPH->setText("6.50 - 7.5");
      ui->envTEM->setText("20.00 - 28.00");
      ui->envTU->setText("15.00 - 20.00");
//      TDSv=15.00;
//      TEMv=8.00;
//      PHv=11.00;
//      TUv=13.00;
      QString filename2("E:/Qt/Sony_water/res/water2.png");//加载图片
      QImage* img4=new QImage;
      if(! ( img4->load(filename2) ) ) //加载图像
        {
          qDebug()<<"打开图片错误";
          delete img4;
          return;
        }
      ui->pitcure->setPixmap(QPixmap::fromImage(*img4));
    }
  if(ui->env_set->currentText()=="游泳池")
    {
      ui->envTDS->setText("150.00 - 300.00");
      ui->envPH->setText("6.50 - 8.50");
      ui->envTEM->setText("26.00 - 28.00");
      ui->envTU->setText("7.40 - 7.60");
      TDSv=0.00;
//      TEMv=0.00;
//      PHv=13.00;
//      TUv=12.00;
      QString filename3("E:/Qt/Sony_water/res/water3.png");//加载图片
      QImage* img5=new QImage;
      if(! ( img5->load(filename3) ) ) //加载图像
        {
          qDebug()<<"打开图片错误";
          delete img5;
          return;
        }
      ui->pitcure->setPixmap(QPixmap::fromImage(*img5));
    }
  if(ui->env_set->currentText()=="海水养殖")
    {
      ui->envTDS->setText("200.00 - 300.00");
      ui->envPH->setText("7.50 - 8.50");
      ui->envTEM->setText("25.00 - 35.00");
      ui->envTU->setText("18.00 - 25.00");
//      TDSv=12.00;
//      TEMv=7.00;
//      PHv=13.00;
//      TUv=12.00;
      QString filename3("E:/Qt/Sony_water/res/water4.jpeg");//加载图片
      QImage* img6=new QImage;
      if(! ( img6->load(filename3) ) ) //加载图像
        {
          qDebug()<<"打开图片错误";
          delete img6;
          return;
        }
      ui->pitcure->setPixmap(QPixmap::fromImage(*img6));
    }
  if(ui->env_set->currentText()=="新场景")
    {
      ui->envTDS->setText(TDSset);
      ui->envPH->setText(TEMset);
      ui->envTEM->setText(PHset);
      ui->envTU->setText(TUset);
    }
}

void Form::on_select_clicked()
{
      if(ui->comboBox->currentText()=="Lora模式")
        {
          QString lora="     切换为Lora模式成功       ";
          QMessageBox::information(NULL,"提示",lora,QMessageBox::Yes);
          ui->comboBox->setCurrentIndex(1);
        }
      if(ui->comboBox->currentText()=="4G模式")
        {
          QString lora="     切换为4G模式成功       ";
          QMessageBox::information(NULL,"提示",lora,QMessageBox::Yes);
          ui->comboBox->setCurrentIndex(2);
        }

}

void Form::on_set_diy_clicked()
{
  TDSset=ui->TDSset->document()->toPlainText();
  TEMset=ui->TEMset->document()->toPlainText();
  PHset=ui->PHset->document()->toPlainText();
  TUset=ui->TUset->document()->toPlainText();
  ui->env_set->addItem("新场景");
}
