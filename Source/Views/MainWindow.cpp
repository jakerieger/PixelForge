// Author: Jake Rieger
// Created: 9/20/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Widgets/Viewport.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDockWidget>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const auto layout = new QVBoxLayout(ui->centralWidget);
    layout->setStretch(0, 1);
    layout->setContentsMargins(0,0,0,0);

    const auto viewport = new Viewport(this);

    // Create panels
    const auto mainToolbar = new QWidget(this);
    mainToolbar->setFixedWidth(48);
    mainToolbar->setStyleSheet("background-color: #111313;");
    const auto mainToolbarLayout = new QVBoxLayout(mainToolbar);
    mainToolbarLayout->addWidget(new QLabel("Toolbar"));

    const auto topToolbar = new QWidget(this);
    topToolbar->setFixedHeight(48);
    topToolbar->setStyleSheet("background-color: #111313;");
    const auto topLayout = new QHBoxLayout(topToolbar);
    topLayout->addWidget(new QLabel("Top", topToolbar));

    const auto editPanels = new QDockWidget(this);
    editPanels->setMinimumWidth(300);
    editPanels->setWidget(new QLabel("Edit Panels", this));
    addDockWidget(Qt::RightDockWidgetArea, editPanels);

    layout->addWidget(topToolbar);
    auto layoutWrapper = new QHBoxLayout();
    layoutWrapper->addWidget(mainToolbar);
    layoutWrapper->addWidget(viewport);
    layout->addLayout(layoutWrapper);

    setCentralWidget(ui->centralWidget);
    ui->centralWidget->setLayout(layout);

    CreateMenuBar();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::CreateMenuBar() {
    const auto menuBar = this->menuBar();

    // File menu
    {
        const auto fileMenu = menuBar->addMenu("File");
        auto newAction = fileMenu->addAction("New", QKeySequence::New);
        auto openAction = fileMenu->addAction("Open", QKeySequence::Open);
        auto saveAction = fileMenu->addAction("Save", QKeySequence::Save);
        auto saveAsAction = fileMenu->addAction("Save As..", QKeySequence::SaveAs);
        fileMenu->addSeparator();
        const auto exitAction = fileMenu->addAction("Exit", QKeySequence::Quit);
        std::ignore = connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
    }
}
