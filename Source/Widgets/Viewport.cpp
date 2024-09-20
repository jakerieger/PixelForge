// Author: Jake Rieger
// Created: 9/20/2024.
//

#include "Viewport.h"

void Viewport::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Viewport::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void Viewport::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
