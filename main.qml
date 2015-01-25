import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import CppImport 1.0

ApplicationWindow {
    visible: true
    title: qsTr("Folder Watcher")

    ColumnLayout{
        anchors.fill: parent
        RowLayout {
            TextField {
                id: textField
                placeholderText: qsTr("enter folder path")
                Layout.fillWidth: true
                Layout.minimumWidth: 100
            }

            Button{
                text: "enter"
                onClicked: {
                    fileListProvider.folderPath = textField.text
                }
            }
        }
        ScrollView {
            id: listViewContainer
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: 100

            ListView {
                visible: fileListProvider.folderPathExists == true &&
                         fileListProvider.fileList.length != 0
                spacing: 3
                model: fileListProvider.fileList
                delegate: Rectangle {
                    border.color: "black"
                    height: 25
                    width: listViewContainer.width
                    Text {
                        text: isFolder? "[DIR] " + name : "[FILE] " + name
                        anchors.verticalCenter: parent.verticalCenter
                        x: 3
                    }
                }
            }
        }
        Text {
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            visible: fileListProvider.folderPathExists == false || fileListProvider.fileList.length == 0
            text: fileListProvider.folderPathExists == false? "Folder " + fileListProvider.folderPath + " not exists":
                                                              "Folder " + fileListProvider.folderPath + " is empty"
            anchors.fill: parent
        }
    }
    width: 640
    height: 480
}
