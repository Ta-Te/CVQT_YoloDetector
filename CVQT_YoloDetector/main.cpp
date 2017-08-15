//
// A demonstration program to use YOLO2 package for fast object detection
// based on
//
// Ta-Te Lin
// Department of Bio-Industrial Mechatronics Engineering
// National Taiwan University
// 2017/08/15
//
// Reference websites:
// https://pjreddie.com/darknet/yolo/
// https://arxiv.org/pdf/1612.08242.pdf   (Original paper by Redmon and Farhadi)
// https://github.com/AlexeyAB/yolo-windows
// https://github.com/mrzl/ofxDarknet/blob/master/README.md
//

#include "yolodetector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YoloDetector w;
    w.show();

    return a.exec();
}
