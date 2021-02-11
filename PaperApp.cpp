#include <iostream>
#include <string>
#include "raylib.h"
#include "PaperApp.h"


PaperApp::PaperApp(int x, int y, std::string title) {
    this->width = x;
    this->height = y;
    this->title = title;
}

// void PaperApp::Awake() {}
// void PaperApp::Start() {}
// void PaperApp::Update() {}
// void PaperApp::OnClose() {}

void PaperApp::Draw() {
    ClearBackground(WHITE);
}

void PaperApp::PaperDraw() {
    BeginDrawing();
    Draw();
    EndDrawing();
}

void PaperApp::PaperStart() {
    Awake();
    InitWindow(width, height, title.c_str());
    std::cout << "PAPER: OpenGL context opened" << std::endl;
    Start();

    while (!WindowShouldClose())
    {
        Update();
        PaperDraw();
    }

    OnClose();
    Cleanup();
    CloseWindow();
}

void PaperApp::RemoveFileOnCleanup(std::string str) {
    filesToRemove.push_back(str);
}

void PaperApp::Cleanup() {
    std::cout << "PAPER: Cleaning up" << std::endl;
    for(int i = 0; i < filesToRemove.size(); i++) {
        int success = remove(filesToRemove[i].c_str());

        if(success != 0)
            std::cout << "PAPER: ERROR: Error trying to remove a file on cleanup: " + (std::string)filesToRemove[i] << std::endl;
    }
}