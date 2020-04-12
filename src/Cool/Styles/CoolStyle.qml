pragma Singleton

import QtQuick 2.0

QtObject {
  id: coolStyle

  property color backgroundColor: "#1c1c1c"
  property color backgroundStrokeColor: "#979797"
  property color warningColor: "#e23e2c"
  property color highlightColor: "orange"
  property color controlBackgroundColor: "#2b2b2b"
  property color textColor: "#cfcfcf"
  property color disabledColor: "#636363"

  property real windowCutSize: 40
  property real controlCutSize: 10
}
