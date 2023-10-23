#include "mainwindow.hpp"
#include <QApplication>
#include <QFile>

#ifndef STYLE_PATH          // Should be defined in CMakeLists.txt
    #define STYLE_PATH ""
#endif

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    QApplication a(argc, argv);
    QFile styleFile(STYLE_PATH);
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    a.setStyleSheet(style);
    MainWindow w;
    w.show();
    a.exec();
    rclcpp::shutdown();
    return 0;
}
