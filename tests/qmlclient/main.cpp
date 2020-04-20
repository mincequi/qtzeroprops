#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtZeroProps/QZeroPropsClient.h>
#include <QtZeroProps/QZeroPropsService.h>
#include <QtZeroProps/QZeroPropsTypes.h>

using namespace QtZeroProps;

static QZeroPropsClient* s_zpClient = nullptr;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    s_zpClient = new QZeroPropsClient(&app);
    qmlRegisterSingletonType<QZeroPropsClient>("QtZeroProps", 1, 0, "QZeroPropsClient", [](QQmlEngine*, QJSEngine*) -> QObject* {
        return s_zpClient;
    });
    qRegisterMetaType<QZeroPropsService*>("QZeroPropsService*");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
