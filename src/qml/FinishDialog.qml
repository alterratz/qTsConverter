import QtQuick 2.12
import QtQuick.Controls 2.7
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.12

Dialog {
    id: messageDialog
    visible: false
    title: converter.convSuccessfull ? qsTr("Conversion completed") : qsTr(
                                           "Conversion failed")
    contentItem: Rectangle {
        implicitWidth: 400
        implicitHeight: 150
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 40

            Text {
                text: converter.convMsg
                Layout.alignment: Qt.AlignHCenter
                color: Material.color(Material.Grey)
                font.pointSize: 16
            }

            Text {
                text: converter.detailedConvMsg
                Layout.alignment: Qt.AlignHCenter
                color: Material.color(Material.BlueGrey)
            }

            Button {
                text: qsTr("Ok!")
                onClicked: messageDialog.close()
                highlighted: true
                Material.background: Material.Orange
                Layout.fillWidth: true
            }
        }
    }
}
