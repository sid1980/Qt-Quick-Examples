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
import QtQuick 2.15
import plugins.analog_clock.internal_ 1.0

Rectangle{
	id: root
    x: parent.x
    y: parent.y
    z: parent.z
    width: parent.width
    height: parent.height
	color: "transparent"
	property int hours
    property int minutes
    property int seconds

    ClockBackend_{
        id: clock_backend
	}

    Timer{
        interval: 100// 100ミリ秒に一回関数呼び出し
        running: true// タイマーon
        repeat: true// 繰り返し
		onTriggered:{
            root.hours = clock_backend.get_hour();
            root.minutes = clock_backend.get_minute();
            root.seconds = clock_backend.get_second();
		}
	}

	Image{
		x: parent.x
		y: parent.y
        z: parent.z + 0
		width: parent.width
		height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/analog_clock/internal_/img/base.svg"
	}

	Image{
		id: hour_nidle
		x: parent.x
		y: parent.y
        z: parent.z + 1
		width: parent.width
		height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/analog_clock/internal_/img/hour.svg"

		transform: Rotation{
            origin.x: root.x + root.width / 2
            origin.y: root.y + root.height / 2
			angle: (root.hours * 30) + (root.minutes * 0.5)
			
			Behavior on angle{
                SpringAnimation{spring: 2; damping: 0.2; modulus: 360}
            }
        }
	}

	Image{
		x: parent.x
		y: parent.y
        z: parent.z + 2
		width: parent.width
		height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/analog_clock/internal_/img/minute.svg"

		transform: Rotation{
            origin.x: root.x + root.width / 2
            origin.y: root.y + root.height / 2
			angle: root.minutes * 6

            Behavior on angle{
            	SpringAnimation{spring: 2; damping: 0.2; modulus: 360}
            }
        }
	}

	Image{
		x: parent.x
		y: parent.y
        z: parent.z + 3
		width: parent.width
		height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/analog_clock/internal_/img/second.svg"

		transform: Rotation{
            origin.x: root.x + root.width / 2
            origin.y: root.y + root.height / 2
            angle: root.seconds * 6

            Behavior on angle{
                SpringAnimation{spring: 2; damping: 0.2; modulus: 360}
            }
        }
	}
	
	Image{
		x: parent.x
		y: parent.y
        z: parent.z + 4
		width: parent.width
		height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/analog_clock/internal_/img/centor.svg"
	}
}
