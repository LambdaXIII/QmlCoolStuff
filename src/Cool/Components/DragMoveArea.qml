import QtQuick 2.12

MouseArea {
  id: root

  acceptedButtons: Qt.LeftButton
  signal wantToMove(real offsetX, real offsetY)

  QtObject {
    id: intProps
    property bool isMoving: false
    property point startingPoint: Qt.point(0, 0)
  }

  onPressed: {
    //当按下鼠标时
    intProps.startingPoint = Qt.point(mouseX, mouseY)
    intProps.isMoving = true
  }

  onPositionChanged: {
    //移动鼠标时
    if (intProps.isMoving) {
      root.wantToMove(mouseX - intProps.startingPoint.x,
                      mouseY - intProps.startingPoint.y)
    }
  }

  onReleased: {
    intProps.isMoving = false
  }
}
