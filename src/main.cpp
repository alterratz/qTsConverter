#include "ConverterGuiProxy.hpp"
#include "ConversionModel.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include <QFontDatabase>

int main(int argc, char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

#ifdef Q_OS_WIN
    QQuickWindow::setTextRenderType(QQuickWindow::TextRenderType::NativeTextRendering);
#endif

    QGuiApplication app(argc, argv);
    app.setOrganizationName(QStringLiteral("Federico Guerinoni"));
    app.setOrganizationDomain(QStringLiteral("Federico Guerinoni"));
    app.setApplicationName(QStringLiteral("qTsConverter"));
    app.setWindowIcon(QIcon(QStringLiteral("qrc:/assets/logos/profile.png")));


    QFontDatabase::addApplicationFont(QStringLiteral(":/assets/fonts/Roboto-Light.ttf"));
    QFontDatabase::addApplicationFont(QStringLiteral(":/assets/fonts/Roboto-Regular.ttf"));

    QQmlApplicationEngine engine;

    ConversionModel cm;
    engine.rootContext()->setContextProperty(QStringLiteral("conversionModel"), &cm);

    ConverterGuiProxy cgp;
    qmlRegisterUncreatableType<ConverterGuiProxy>("app", 1, 0, "ConverterGuiProxy", {});
    engine.rootContext()->setContextProperty(QStringLiteral("converter"), &cgp);
    engine.rootContext()->setContextProperty(QStringLiteral("version"),
                                             VERSION);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return QGuiApplication::exec();
}
