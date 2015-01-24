import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    title: qsTr("Folder Watcher")

//    Button{
//        anchors.centerIn: parent
//    }

    ListView {

        width: 100; height: 100

        model: folderListModel
        delegate: Rectangle {
            height: 25
            width: 100
            //color: model.modelData.name
            Text { text: name }
        }
    }

    width: 640
    height: 480


////    menuBar: MenuBar {
////        Menu {
////            title: qsTr("File")
////            MenuItem {
////                text: qsTr("&Open")
////                onTriggered: console.log("Open action triggered");
////            }
////            MenuItem {
////                text: qsTr("Exit")
////                onTriggered: Qt.quit();
////            }
////        }
////    }

//    Label {
//        text: qsTr("Hello World")
//        anchors.centerIn: parent
//    }
}
