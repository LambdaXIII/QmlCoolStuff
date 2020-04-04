import QtQuick 2.12
import QtQuick.Window 2.12
import Cool.Basic 1.0

Window {
  visible: true
  width: 640
  height: 480
  title: qsTr("Hello World")

  BasicCutCornerBox {
    anchors.fill: parent
    anchors.margins: 20
    strokeColor: "green"
    strokeWidth: 20
    backColor: "black"
    cutSize: 80
  }
}
