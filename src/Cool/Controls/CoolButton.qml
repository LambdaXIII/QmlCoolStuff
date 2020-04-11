import QtQuick 2.12
import QtQuick.Controls 2.12
import Cool.Components 1.0

AbstractButton {
  id: control

  property alias backBox: backBox

  background: CutCornerBox {
    id: backBox
    cutSize: 25
    strokeColor: hovered ? "red" : "orange"
    backColor: down ? "grey" : "black"
    strokeWidth: hovered ? 10 : 5
  }

//  containmentMask: backBox

  topPadding: backBox.strokeWidth
  bottomPadding: backBox.strokeWidth
  leftPadding: backBox.strokeWidth
  rightPadding: backBox.strokeWidth

  contentItem: Text {
    id: mainText
    text: control.text
    color: "white"
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
  }
}
