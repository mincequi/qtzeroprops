#include <QtZeroProps/QZeroPropsServer.h>
#include <QtZeroProps/QZeroPropsService.h>
#include <QtZeroProps/QZeroPropsTypes.h>

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

using namespace QtZeroProps;

int main(int argc, char **argv)
{
    QCoreApplication a(argc, argv);
    QZeroPropsServer server;
    QZeroPropsService* service = server.startService({"_cornrow._tcp"});
    QObject::connect(service, &QZeroPropsService::propertyChanged, [](const QVariant& uuid, const QByteArray& value) {
        qDebug() << "uuid:" << uuid << ", value.size:" << value.size();
    });

    QTimer timer;
    timer.setSingleShot(false);
    timer.callOnTimeout([&]() {
        static qint8 i = 0;
        service->setProperty(++i, "1234");
        if (i == std::numeric_limits<qint8>::max()) {
            i = 0;
        }
        //qDebug() << "Set key:" << i;
    });
    timer.start(1000);

    a.exec();
}
