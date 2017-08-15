#ifndef YOLODETECTOR_H
#define YOLODETECTOR_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextEdit>
#include <QMessageBox>
#include <QLibrary>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cvdef.h>

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <functional>
#include <ctime>
#include <thread>
#include <atomic>

#include "network.h"
#include "region_layer.h"
#include "cost_layer.h"
#include "utils.h"
#include "parser.h"
#include "box.h"
#include "demo.h"
#include "option_list.h"

#define OPENCV

//using namespace std;
using namespace cv;

namespace Ui {
class YoloDetector;
}

class YoloDetector : public QMainWindow
{
    Q_OBJECT

public:
    explicit YoloDetector(QWidget *parent = 0);
    ~YoloDetector();

private slots:
    void on_actionExit_triggered();

    void on_actionDetect_Object_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::YoloDetector *ui;
};

#endif // YOLODETECTOR_H
