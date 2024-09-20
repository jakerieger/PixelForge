// Author: Jake Rieger
// Created: 9/20/2024.
//

#include <QApplication>
#include <QFile>

#include "Views/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile file(":/Resources/ThemeDark.qss");
    if (file.open(QFile::ReadOnly)) {
        const QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
    } else {
        qDebug() << "Error opening file";
    }

    MainWindow mainWindow;
    mainWindow.setMinimumSize(QSize(1280, 720));
    mainWindow.showMaximized();

    return QApplication::exec();
}
