#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include "opencv2/opencv.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;

}

// 选择图片按钮点击
void MainWindow::on_browseInputBtn_pressed()
{
       // 选择系统文件/文件夹
       QString fileName = QFileDialog::getOpenFileName(this,"Open input Image",QDir::currentPath(),"Images (*.jpg *.png *.bmp)");
       if(QFile::exists(fileName)){
           ui->inputImageTextInput->setText(fileName);
       }
}

// 图片输出
void MainWindow::on_browseOutputBtn_pressed()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Select Output Image",QDir::currentPath(),"*.jpg;;*.png;;*.bmp");
    if(!fileName.isEmpty()){
        ui->outImageInput->setText(fileName);
        using namespace cv;
        Mat inputImg,outputImg;
        inputImg = imread(ui->inputImageTextInput->text().toStdString());

        // 高斯模糊
        if(ui->GaussianBlurBtn->isCheckable()){
            GaussianBlur(inputImg,outputImg,Size(5,5),1.25);
        }else if(ui->medianBlurBtn->isChecked()){ //
            medianBlur(inputImg,outputImg,5);
        }
        imwrite(ui->outImageInput->text().toStdString(),outputImg);
        if(ui->displayImg->isChecked()){
            imshow("Output Image",outputImg);
        }
    }
}

// 重写关闭窗口方法
void MainWindow::closeEvent(QCloseEvent *event){
    // 弹窗询问结果
    int result = QMessageBox::warning(this,"Exit","Are you sure you want to close the param?",QMessageBox::Yes,QMessageBox::No);

    if(result == QMessageBox::Yes){
        saveSettings();
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::saveSettings(){
    QSettings settings("Packt","Hello_Opencv_Qt",this);
    settings.setValue("inputLineEdit",ui->inputImageTextInput->text());
    settings.setValue("outputLineEdit",ui->outImageInput->text());

    settings.setValue("medianBlurRadioButton",ui->medianBlurBtn->isChecked());
    settings.setValue("gaussianBlurRadioButton",ui->GaussianBlurBtn->isChecked());

    settings.setValue("displayImageCheckBox",ui->displayImg->isChecked());
}

void MainWindow::loadSettings(){
    QSettings settings("Packt","Hello_Opencv_Qt",this);

    ui->inputImageTextInput->setText(settings.value("inputLineEdit","").toString());
    ui->outImageInput->setText(settings.value("outputLineEdit","").toString());

    ui->medianBlurBtn->setChecked(settings.value("medianBlurRadioButton",true).toBool());
    ui->GaussianBlurBtn->setChecked(settings.value("gaussianBlurRadioButton",false).toBool());
    ui->displayImg->setChecked(settings.value("displayImageCheckBox",false).toBool());
}
