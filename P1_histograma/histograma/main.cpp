#include <stdlib.h>
#include <time.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
  QT_CHARTS_USE_NAMESPACE
int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);
    QLineSeries *h = new QLineSeries();

    //Generación de números aleatorios y asignación en la serie
    int i,n;
    for(i=0;i<10;i++){
        n=0+rand();
        h->append(i+1,n);
    }
    QChart *chart = new QChart();
    chart->legend()->hide();
    h->color();
    chart->addSeries(h);
    //Qchart::ChartThemeBrownSand;
    chart->backgroundBrush().color();
    chart->setTitle("Histograma");
    QValueAxis *axisX =new QValueAxis;
    axisX->setTickCount(10);
    axisX->setLabelFormat("%i");
    chart->addAxis(axisX,Qt::AlignBottom);
    h->attachAxis(axisX);
    QValueAxis *axisY =new QValueAxis;
    axisY->setTickCount(h->count());
    chart->addAxis(axisY,Qt::AlignLeading);
    h->attachAxis(axisY);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(500, 400);
    window.show();
    return a.exec();
  }

