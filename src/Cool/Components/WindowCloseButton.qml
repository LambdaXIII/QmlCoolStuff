import QtQuick 2.12

import Cool.Basic 1.0
import Cool.Styles 1.0

BasicWindowCloseButton {
  id: control
  width: 20
  height: width

  strokeColor: CoolStyle.backgroundColor

  fillColor: down ? "white" : hovered ? CoolStyle.highlightColor : CoolStyle.warningColor
}
