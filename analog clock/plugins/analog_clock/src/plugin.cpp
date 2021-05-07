#include <plugin.hpp>
#include <clock_backend.hpp>
#include <qqml.h>
#include <QUrl>

void Plugin::registerTypes(const char *uri)
{
    qmlRegisterType<clock_component::ClockBackend>(uri, 1, 0, "ClockBackend");
    qmlRegisterType(QUrl("qrc:/qml/Clock.qml"), uri, 1, 0, "AnalogClock");
}

