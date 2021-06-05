/*-------------------------------------------------------------------------------
                           Copyright (c) 2021 DIODE.
    
    This file is part of analog clock.
    
    analog clock is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    analog clock is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with analog clock.  If not, see <https://www.gnu.org/licenses/>.
*///-----------------------------------------------------------------------------
#include <plugin.hpp>
#include <clock_backend.hpp>
#include <qqml.h>
#include <QUrl>
#include <QString>

void Plugin::registerTypes(const char* uri)
{
    auto internal_uri = (QString(uri) + ".internal_").toLocal8Bit();
    qmlRegisterType<clock_component::ClockBackend>(internal_uri.data(), 0, 1, "ClockBackend_");
    qmlRegisterType(QUrl("qrc:/qml/AnalogClock.qml"), uri, 0, 1, "AnalogClock");
}
