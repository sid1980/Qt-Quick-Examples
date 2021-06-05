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
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

import plugins.analog_clock 0.1

Window{
	visible: true
	title: qsTr("Qt Quick")
	id: root

	// 初期の画面サイズを黄金比に設定し画面の中心に配置する
	width: Screen.width >= Screen.height ? Screen.width*0.5 : (Screen.height*0.5)*(1/1.618);
	height: Screen.width >= Screen.height ? (Screen.width*0.5)*(1/1.618) : Screen.height*0.5;
	minimumWidth: width * (1/3)
	minimumHeight: height * (1/3)

    AnalogClock{}
}
