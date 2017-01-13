#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QApplication>

#ifdef Q_OS_WIN
#include <QDir>
#include <QFileInfo>
#include <QSettings>

// Helper function to register supported file types
// This is needed to enable the application jump list to show the desired recent files
static void associateFileTypes(const QStringList &fileTypes)
{
    QString displayName = QGuiApplication::applicationDisplayName();
    QString filePath = QCoreApplication::applicationFilePath();
    QString fileName = QFileInfo(filePath).fileName();

    QSettings settings("HKEY_CURRENT_USER\\Software\\Classes\\Applications\\" + fileName, QSettings::NativeFormat);
    settings.setValue("FriendlyAppName", displayName);

    settings.beginGroup("SupportedTypes");
    foreach (const QString& fileType, fileTypes)
        settings.setValue(fileType, QString());
    settings.endGroup();

    settings.beginGroup("shell");
    settings.beginGroup("open");
    settings.setValue("FriendlyAppName", displayName);
    settings.beginGroup("Command");
    settings.setValue(".", QChar('"') + QDir::toNativeSeparators(filePath) + QString("\" \"%1\""));
}
#endif

#endif // FUNCTIONS_H
