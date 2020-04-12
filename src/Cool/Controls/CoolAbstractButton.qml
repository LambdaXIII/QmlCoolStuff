import QtQuick 2.14
import QtQuick.Controls 2.14
import Cool.Components 1.0
import Cool.Styles 1.0

Control {
  id: control

  property string text: qsTr("空白按钮")

  property alias backBox: backBox
  readonly property bool down: mouseArea.down
  readonly property bool mouseOvered: mouseArea.mouseOvered
  property bool checkable: false
  property bool checked: false

  signal clicked

  background: CutCornerBox {
    id: backBox
    cutSize: CoolStyle.controlCutSize
    strokeWidth: 2
    strokeColor: enabled ? (mouseOvered | checked ? CoolStyle.highlightColor : CoolStyle.backgroundStrokeColor) : CoolStyle.disabledColor
    backColor: CoolStyle.controlBackgroundColor
    Rectangle {
      width: 6
      height: width
      radius: width / 2
      border.width: 0
      color: checked ? CoolStyle.highlightColor : CoolStyle.textColor
      visible: checkable
      anchors.left: parent.left
      anchors.bottom: parent.bottom
      anchors.margins: 5
      z: 1
    }
    Rectangle {
      width: 6
      height: width
      radius: width / 2
      border.width: 0
      color: CoolStyle.warningColor
      visible: !enabled
      anchors.left: parent.left
      anchors.bottom: parent.bottom
      anchors.margins: 5
      z: 2
    }

    Rectangle {
      id: hoverCover
      anchors.fill: parent
      anchors.topMargin: backBox.cutSize
      anchors.leftMargin: backBox.strokeWidth
      anchors.rightMargin: backBox.strokeWidth
      anchors.bottomMargin: backBox.strokeWidth
      gradient: Gradient {
        GradientStop {
          position: 1
          color: CoolStyle.highlightColor
        }

        GradientStop {
          position: 0
          color: "#00000000"
        }
      }
      opacity: 0.2
      visible: mouseOvered
    }
  }

  leftPadding: backBox.strokeWidth
  rightPadding: backBox.strokeWidth
  bottomPadding: backBox.strokeWidth
  topPadding: backBox.strokeWidth

  MouseArea {
    id: mouseArea
    containmentMask: backBox
    anchors.fill: backBox
    hoverEnabled: true
    property bool down: false
    onPressed: down = true
    onReleased: {
      down = false
      if (backBox.contains(Qt.point(mouseX, mouseY)))
        control.clicked()
    }
    property bool mouseOvered: false
    onEntered: mouseOvered = true
    onExited: mouseOvered = false
    z: 90
  }

  CutCornerBox {
    anchors.fill: backBox
    z: 30
    cutSize: backBox.cutSize
    backColor: CoolStyle.highlightColor
    hasStroke: false
    strokeWidth: backBox.strokeWidth
    visible: control.down
    Text {
      text: qsTr("啪")
      font.pixelSize: 40
      anchors.centerIn: parent
    }
    clip: true
  }

  onClicked: {
    if (checkable) {
      checked = !checked
    }
  }
}
