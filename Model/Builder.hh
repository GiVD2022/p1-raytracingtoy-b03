#pragma once

#include <QtWidgets>
#include "Controller.hh"

class Builder : public QObject {
    Q_OBJECT

public:
    Builder(){};

public slots:
    void newSphere();
    void newTriangle();
    void newMesh();
    void newSimulatedScene();
    void newVirtualScene();
    void newDataScene();
    void loadSettings();
    void activaColorShading();
    void activaNormalShader();

signals:
     void settingsChanged();
};

