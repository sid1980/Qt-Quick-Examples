#include <plugin.hpp>
#include <nidle.hpp>
#include <scale.hpp>
#include <qqml.h>
#include <QUrl>
#include <QString>

void MeterPlugin::registerTypes(const char* uri)
{
    auto internal_uri = (QString(uri) + ".internal_").toLocal8Bit();
    qmlRegisterType<meter_internal_::Nidle>(internal_uri.data(), 0, 1, "Nidle");
	qmlRegisterType<meter_internal_::Scale>(internal_uri.data(), 0, 1, "Scale");
    qmlRegisterType(QUrl("qrc:/plugins/meter/qml/Meter.qml"), uri, 0, 1, "Meter");
}
