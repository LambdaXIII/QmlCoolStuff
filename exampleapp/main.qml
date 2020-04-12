import QtQuick 2.12
import Cool.Controls 1.0

CoolWindow {
  visible: true
  width: 640
  height: 480
  title: qsTr("QmlCoolStuff 测试窗口")

  //  closeButtonEnabled: false


  /*
  CutCornerBox {
    anchors.fill: parent
    anchors.margins: 20
    strokeColor: "green"
    strokeWidth: 20
    backColor: "black"
    cutSize: 80
  }
  */
  CoolTextButton {
    width: 200
    height: 50
    anchors.centerIn: parent
    text: qsTr("普通文本按钮")
    checkable: true
  }
}
