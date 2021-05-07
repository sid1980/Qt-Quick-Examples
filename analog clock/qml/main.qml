import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import plugins.analog_clock 1.0

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
