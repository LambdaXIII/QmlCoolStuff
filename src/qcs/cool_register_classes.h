#ifndef COOL_REGISTER_CLASSES_H
#define COOL_REGISTER_CLASSES_H

#include "basiccutcornerbox.h"

#include <QQmlEngine>

void cool_register_classes() {
#define COOL_ERI "Cool.Basic", 1, 0

  qmlRegisterType<QmlCool::BasicCutCornerBox>(
    COOL_ERI, "BasicCutCornerBox");

#undef COOL_ERI
}

#endif // COOL_REGISTER_CLASSES_H
