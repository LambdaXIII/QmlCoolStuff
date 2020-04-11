import QtQuick 2.12
import QtQuick.Window 2.12
import Cool.Components 1.0

Window {
  id: root
  flags: Qt.CustomizeWindowHint | Qt.FramelessWindowHint | Qt.Window
  color: "transparent"

  property bool closeButtonEnabled: true
  property bool resizable: true

  Text {
    id: titleText
    text: root.title
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.margins: 5 + backgroundBox.strokeWidth
    horizontalAlignment: Text.AlignRight
    verticalAlignment: Text.AlignTop
    color: "white"
  }

  CutCornerBox {
    id: backgroundBox
    anchors.fill: parent
    z: -99
    strokeWidth: 2
    cutSize: 40
    DragMoveArea {
      anchors.fill: parent
      property bool canMove: true
      onWantToMove: {
        if (canMove) {
          canMove = false
          root.x = root.x + offsetX
          root.y = root.y + offsetY
          canMove = true
        }
      }
      containmentMask: backgroundBox
    }
  }

  WindowCloseButton {
    id: closeButton
    visible: root.closeButtonEnabled
    onClicked: root.close()
    width: backgroundBox.cutSize - 5
  }

  Canvas {
    id: resizeIndicator
    visible: root.resizable
    width: 20
    height: 20
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    onPaint: {
      var c = getContext("2d")
      c.moveTo(width, 0)
      c.lineTo(width, height)
      c.lineTo(0, height)
      c.closePath()
      c.fillStyle = backgroundBox.strokeColor
      c.fill()
    }
    DragMoveArea {
      anchors.fill: parent
      property bool isFreeToResize: true
      onWantToMove: {
        if (isFreeToResize) {
          isFreeToResize = false
          root.width += offsetX
          root.height += offsetY
          isFreeToResize = true
        }
      }
    }
  }
}
