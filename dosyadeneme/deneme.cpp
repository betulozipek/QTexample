#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QDebug>
#include<QApplication>
#include<QObject>
#include<QTranslator>
#include<QLocale>

int main(int argc, char *argv[]) {
    int countLine;

    QTranslator translator;
    if (!translator.load("D:/Desktop/dosyadeneme/dosyadeneme.qm")) {
        qDebug() << QObject::tr("Translation file couldn't be loaded.");
        return 1;
    }

    QApplication app(argc, argv);
    app.installTranslator(&translator);

    QFileDialog fileDialog;
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setNameFilter(QObject::tr("C++ Files (*.cpp)"));

    QString filePath = fileDialog.getOpenFileName(nullptr, QObject::tr("Open Files"), QDir::homePath());

    if (filePath.isEmpty()) {
        qDebug() << QObject::tr("No file selected or an error occurred.");
        return 1;
    }

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << QObject::tr("File could not be opened.");
        return 1;
    }

    QTextStream data(&file);
    countLine = 0;
    while (!data.atEnd()) {
        QString line = data.readLine();
        QString str = line.trimmed();
        if (!(str.startsWith("//")) && !(str.isEmpty()) && !(str == "{") && !(str == "}")
            && !(str.endsWith("*/")) && !(str.startsWith("/*"))) {
            countLine++;
        }
    }

    file.close();

    qDebug() << QObject::tr("Number of Lines") << countLine;

    return app.exec();
}
