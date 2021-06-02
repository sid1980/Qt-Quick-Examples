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
import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import plugins.meter.internal_ 0.1

Item{
    id: meter
    width: parent.width
    height: parent.height
    x: parent.x
    y: parent.y
    z: parent.z

    /*--------------------------------------
        コンポーネントに共通なプロパティ
    *///------------------------------------
    property real max_value: 100.                                //最大値
    property real value: 0.                                      //針の位置
    property int decimal_place: 1                                //小数点第何位まで表示するか

    /*--------------------------------
        目盛りにまつわるプロパティ
    *///------------------------------
    property bool scale_visible: true                            //目盛りを描画するかどうか
    property int scale_num: 10                                   //大目盛りの数
    property real danger_zone: 80.                               //レッドゾーンの位置
    property color danger_zone_color: Qt.rgba(1., 0.2, 0.2, 0.7) //レッドゾーンの色
    property bool danger_zone_visible: true                      //レッドゾーンを描画するか
    property color scale_color: "black"                          //目盛りの色

    /*---------------------------
        針にまつわるプロパティ
    *///-------------------------
    property bool nidle_visible: true
    property color nidle_color: "red"                             //針の色

    /*------------------------------
        数字にまつわるプロパティ
    *///----------------------------
    property bool value_text_visible: true
    property color text_color: "black"                            //数字の色
    property string unit: qsTr("")                                //単位

    /*--------------
        シグナル
    *///------------
    signal aboveDangerZone()
    signal belowDangerZone()

    Label{
        id: text
        visible: parent.value_text_visible
        z: parent.z + 0.1
        text: parent.value.toFixed(parent.decimal_place) + parent.unit
        color: parent.text_color
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        fontSizeMode: Text.Fit
        minimumPointSize: 1
        font.pointSize: 1000
        x: parent.x
        y: parent.y  + parent.height/2
        width: parent.width
        height: parent.height * 0.5
    }

    Scale{
        id: scale
        visible: parent.scale_visible
        z: parent.z + 0.2
        anchors.fill: parent
        scale_num: parent.scale_num
        max_value: parent.max_value
        danger_zone: parent.danger_zone
        danger_zone_color: parent.danger_zone_color
        danger_zone_visible: parent.danger_zone_visible
        decimal_place: parent.decimal_place
        scale_color: parent.scale_color
    }

    Nidle{
        id: nidle
        visible: parent.nidle_visible
        z: parent.z + 0.3
        anchors.fill: parent
        scale_num: parent.scale_num
        max_value: parent.max_value
        value: parent.value
        nidle_color: parent.nidle_color
        danger_zone: parent.danger_zone

        onAboveDangerZone: {
            parent.aboveDangerZone();
        }

        onBelowDangerZone: {
            parent.belowDangerZone();
        }
    }
}
