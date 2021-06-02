import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import plugins.meter 0.1

Window{
	visible: true
	title: qsTr("Qt Quick")
	id: root

	width: Screen.width >= Screen.height ? Screen.width*0.5 : (Screen.height*0.5)*(1/1.618);
	height: Screen.width >= Screen.height ? (Screen.width*0.5)*(1/1.618) : Screen.height*0.5;
	minimumWidth: width * (1/3)
	minimumHeight: height * (1/3)

    Column{
        anchors.fill: parent

        Meter{
            id: meter
            width: parent.width
            height: parent.height * 0.8
            value: slider.value * 100.
        }

        Row{
            width: parent.width
            height: parent.height * 0.2

            Slider{
                id: slider
                width: parent.width * 0.8
                height: parent.height
            }

            Label{
                id: la
                text: qsTr("安全")
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                fontSizeMode: Text.Fit
                minimumPointSize: 1
                font.pointSize: 1000
                width: parent.width * 0.2
                height: parent.height

                Connections{
                    target: meter

                    function onAboveDangerZone(){
                        la.text = qsTr("危険");
                    }

                    function onBelowDangerZone(){
                        la.text = qsTr("安全");
                    }
                }
            }
        }
    }
}
