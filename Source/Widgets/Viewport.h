// Author: Jake Rieger
// Created: 9/20/2024.
//

#pragma once

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>

class Viewport final : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    explicit Viewport(QWidget *parent = Q_NULLPTR) : QOpenGLWidget(parent) {}

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};
