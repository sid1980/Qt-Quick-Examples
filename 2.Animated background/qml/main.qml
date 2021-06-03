import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

Window{
	visible: true
	title: qsTr("Qt Quick")
	id: root

	width: Screen.width >= Screen.height ? Screen.width*0.5 : (Screen.height*0.5)*(1/1.618);
	height: Screen.width >= Screen.height ? (Screen.width*0.5)*(1/1.618) : Screen.height*0.5;
	minimumWidth: width * (1/3)
	minimumHeight: height * (1/3)

    SinWave{
		anchors.fill: parent
		color1: "black"
		color2: "green"
    }
}
