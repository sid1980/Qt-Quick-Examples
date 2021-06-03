#include <plugin.hpp>
#include <qqml.h>
#include <QUrl>
#include <QString>

void MeterPlugin::registerTypes(const char* uri)
{
    qmlRegisterType(QUrl("qrc:/plugins/wave_background/qml/WaveBackground.qml"), uri, 0, 1, "WaveBackground");
}
