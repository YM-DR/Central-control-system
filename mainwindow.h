#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>
#include <QtWebView/QtWebView>
#include <QStackedLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebEngineView *map_view;
    QWebChannel *channel;
public slots:
    //this slot funciton used to communicate with html
    void Latitude_longitude_function(QString lon,QString lat);

};
#endif // MAINWINDOW_H
