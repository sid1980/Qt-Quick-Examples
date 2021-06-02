/*-------------------------------------------------------------------------------
                           Copyright (c) 2021 DIODE.
    
    This file is part of meter.
    
    meter is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    meter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with meter.  If not, see <https://www.gnu.org/licenses/>.
*///-----------------------------------------------------------------------------
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
