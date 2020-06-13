#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , map_view(new QWebEngineView(this))
    , channel(new QWebChannel (this))
{
    //init a windows
    ui->setupUi(this);
    //layout config
    QStackedLayout* layout=new QStackedLayout(ui->map);
    ui->map->setLayout(layout);
    layout->addWidget(map_view);
    //load gaode api, the resources path is copy from the resources file
    QString strMapPath="qrc:/gaode_api/gaode_getcenter.html";
    QWebEnginePage *page=map_view->page();
    page->load(QUrl(strMapPath));

    //define a channel aim to communicate with the html file
 //   channel=new QWebChannel(this);
    channel->registerObject(QString("person"),this);
    page->setWebChannel(channel);
}


/*************************************************************/
/*              slots function definition seg                */
/*************************************************************/
void MainWindow::Latitude_longitude_function(QString lon,QString lat)
{
    QString templon="longitude:"+lon;
    QString templat="latitude:"+lat;

    //ui->lon->setText(templon);
    //ui->lat->setText(templat);
}


/*************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

