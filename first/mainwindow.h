#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseInputBtn_pressed();// 选择图片按钮点击

    void on_browseOutputBtn_pressed(); // 图片路径输入弹窗点击

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    void loadSettings(); // 加载配置文件
    void saveSettings(); // 保存配置文件
};
#endif // MAINWINDOW_H
