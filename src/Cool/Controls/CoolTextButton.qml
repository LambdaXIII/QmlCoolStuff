import QtQuick 2.14
import Cool.Styles 1.0

CoolAbstractButton {
  id: control

  contentItem: Text {
    id: mainText
    text: control.text
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    color: enabled ? (checked ? CoolStyle.highlightColor : CoolStyle.textColor) : CoolStyle.disabledColor
  }
}
