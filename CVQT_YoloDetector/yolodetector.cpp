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
#include "ui_yolodetector.h"

#include "yolo_v2_class.hpp"	// imported functions from DLL

// Global Variables
cv::Mat image1;
cv::Mat image2;
cv::Mat image3;
cv::Mat image_detect;

QString message;
QString ImageFileName;


/////////////////////////////////////////////////////////////////////////////////////////
// Three functions used by the object detection function : YoloDetector::on_actionDetect_Object_triggered()
//   void draw_boxes
//   void show_result
//   void objects_names_from_file
/////////////////////////////////////////////////////////////////////////////////////////
void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names, unsigned int wait_msec = 0) {
    for (auto &i : result_vec) {
        cv::Scalar color(60, 160, 260);
        cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 5);
        if (obj_names.size() > i.obj_id) {
            std::string obj_name = obj_names[i.obj_id];
            if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
            cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
            int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
            cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 3, 0), std::max((int)i.y - 30, 0)),
                cv::Point2f(std::min((int)i.x + max_width, mat_img.cols-1), std::min((int)i.y, mat_img.rows-1)),
                color, CV_FILLED, 8, 0);
            putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
        }
    }
    // Show image with OpenCV
    // cv::imshow("window name", mat_img);
    // cv::waitKey(wait_msec);
}

void show_result(std::vector<bbox_t> const result_vec, std::vector<std::string> const obj_names) {
    for (auto &i : result_vec) {
        if (obj_names.size() > i.obj_id) std::cout << obj_names[i.obj_id] << " - ";
        std::cout << "obj_id = " << i.obj_id << ",  x = " << i.x << ", y = " << i.y
            << ", w = " << i.w << ", h = " << i.h
            << std::setprecision(3) << ", prob = " << i.prob << std::endl;
    }
}

std::vector<std::string> objects_names_from_file(std::string const filename) {
    std::ifstream file(filename);
    std::vector<std::string> file_lines;
    if (!file.is_open()) return file_lines;
    for(std::string line; file >> line;) file_lines.push_back(line);
    std::cout << "object names loaded \n";
    return file_lines;
}


/////////////////////////////////////////////////////////////////////////////////////////
//  YoloDetector constructor function (Program initialization)
/////////////////////////////////////////////////////////////////////////////////////////
YoloDetector::YoloDetector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::YoloDetector)
{
    ui->setupUi(this);
    ui->actionSave->setDisabled(true);
    ui->actionDetect_Object->setDisabled(true);
}

/////////////////////////////////////////////////////////////////////////////////////////
//  YoloDetector destructor function
/////////////////////////////////////////////////////////////////////////////////////////
YoloDetector::~YoloDetector()
{
    delete ui;
}

/////////////////////////////////////////////////////////////////////////////////////////
// Object detection
/////////////////////////////////////////////////////////////////////////////////////////
void YoloDetector::on_actionDetect_Object_triggered()
{

    // CNN files for Yolo9000 model
        std::string cfgfile = "yolo.cfg";
        std::string weightfile = "yolo.weights";
        std::string namefile = "data/yolo.names";

// CNN config file, weight file, and label name file
//    std::string cfgfile = "yolo-voc.cfg";
//    std::string weightfile = "yolo-voc.weights";
//    std::string namefile = "data/voc.names";

// CNN files for Yolo9000 model
//    std::string cfgfile = "yolo9000.cfg";
//    std::string weightfile = "yolo9000.weights";
//    std::string namefile = "data/9k.names";

    // load the network structure and weights
    Detector detector(cfgfile, weightfile);
    auto obj_names = objects_names_from_file(namefile);

    message = "<< Configuration file: " + QString::fromUtf8(cfgfile.c_str()) + " successfully loaded >>";
    ui->textEdit->append(message);
    message = "<< Weight file: " + QString::fromUtf8(weightfile.c_str()) + " successfully loaded >>";
    ui->textEdit->append(message);
    message = "<< Label file: " + QString::fromUtf8(namefile.c_str()) + " successfully loaded >>";
    ui->textEdit->append(message);

    // Read the image file
    cv::Mat mat_img = cv::imread(ImageFileName.toStdString().data());

    // Perform object detection and draw boxes on detected objects
    std::vector<bbox_t> result_vec = detector.detect(mat_img);
    result_vec = detector.tracking(result_vec);	// comment it - if track_id is not required
    draw_boxes(mat_img, result_vec, obj_names);

    image_detect = mat_img.clone();  // save detected image for later usage

    // Show image on Qt interface
    cvtColor(mat_img, mat_img, 4 );  // 4 for original CV_BGR2RGB
    cv::resize(mat_img, mat_img, Size(ui->label->width(), ui->label->height())); // Resize the image to fit the display screen
    QImage img = QImage((const unsigned char*) (mat_img.data),
                        mat_img.cols, mat_img.rows, QImage::Format_RGB888);
    YoloDetector::ui->label->setPixmap(QPixmap::fromImage(img));

    // Show results to the console
    show_result(result_vec, obj_names);
    message = " ";
    ui->textEdit->append(message);
    message = "<< Object Detectio Results >>";
    ui->textEdit->append(message);

    int object_num = 0;
    for (auto &i : result_vec)
    {
        if (obj_names.size() > i.obj_id)
            message = QString::fromUtf8(obj_names[i.obj_id].c_str()) + " - ";

        message = message + "obj_id = " + QString::number(i.obj_id,'f',0)
                  + ", probablity = " + QString::number(i.prob,'f',2);
        ui->textEdit->append(message);
        object_num++;
    }
    message = "Total number of detected objects = " + QString::number(object_num,'f',0);
    ui->textEdit->append(message);

    ui->actionSave->setEnabled(true);  // Enable the menu item (save file)

}

/////////////////////////////////////////////////////////////////////////////////////////
// Open image file
/////////////////////////////////////////////////////////////////////////////////////////
void YoloDetector::on_actionOpen_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        ImageFileName = fileName;      // Save file name for detector function call
        image1 = cv::imread(fileName.toStdString().data());
        image2 = image1.clone();
        cvtColor(image2, image3, 4 );  // 4 for original CV_BGR2RGB

        // Resize the image to fit the display screen
        cv::resize(image3, image3, Size(ui->label->width(), ui->label->height()));

        // Qt image
        QImage img = QImage((const unsigned char*) (image3.data),
                            image3.cols, image3.rows, QImage::Format_RGB888);

        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(img));

        message = "<< Image file " + QString::fromUtf8(fileName.toStdString().data()) + " successfully loaded >>";
        ui->textEdit->append(message);

        ui->actionDetect_Object->setEnabled(true);  // Enable the menu item (detect object)
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
// Save image file
/////////////////////////////////////////////////////////////////////////////////////////
void YoloDetector::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), ".", tr("*.jpg") );
    if(fileName != NULL)
    {
        imwrite(fileName.toStdString().data(), image_detect);

        message = "<< Image file " + QString::fromUtf8(fileName.toStdString().data()) + " successfully saved >>";
        ui->textEdit->append(message);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
// Exit the program
/////////////////////////////////////////////////////////////////////////////////////////
void YoloDetector::on_actionExit_triggered()
{
    close();
}

