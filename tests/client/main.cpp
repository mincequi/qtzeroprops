#include <QtZeroProps/QZeroPropsClient.h>
#include <QtZeroProps/QZeroPropsService.h>
#include <QtZeroProps/QZeroPropsTypes.h>

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

using namespace QtZeroProps;

int main(int argc, char **argv)
{
    QCoreApplication a(argc, argv);
    QZeroPropsService* service = nullptr;

    QTimer timer;
    timer.setSingleShot(false);
    timer.callOnTimeout([&]() {
        static quint32 i = 0;
        service->setProperty(++i, "1234");
        //qDebug() << "Set key:" << i;
    });

    QZeroPropsClient client;
    QObject::connect(&client, &QZeroPropsClient::servicesChanged, [&]() {
        if (!client.discoveredServices().empty() && !service) {
            service = static_cast<QZeroPropsService*>(client.discoveredServices().first());
            //timer.start(1000);
            //QObject::connect(service, &QZeroPropsService::propertyChanged, [](const QVariant& uuid, const QByteArray& value) {
            //    qDebug() << "uuid:" << uuid << ", value.size:" << value.size();
            //});
            client.connectToService(service);
        }
    });
    client.startDiscovery("_cornrow._tcp");

    a.exec();
}
