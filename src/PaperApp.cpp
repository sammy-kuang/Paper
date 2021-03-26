#include <iostream>
#include <string>
#include "FreeImage.h"
#include "raylib.h"
#include "PaperObjects.h"
#include "PaperApp.h"


PaperApp::PaperApp(int x, int y, std::string title) {
    this->initWidth = x;
    this->initHeight = y;
    this->title = title;
}

void PaperApp::Draw() {
    ClearBackground(WHITE);
}

void PaperApp::PaperUpdate() {
    for(int i = 0; i < tasks.size(); i++) {
        tasks[i]->Run();
    }
}

void PaperApp::PaperDraw() {
    BeginDrawing();
    Draw();
    EndDrawing();
}

void PaperApp::PaperStart() {
    FreeImage_Initialise(); // initialize FreeImage only once

    Awake();
    InitWindow(initWidth, initHeight, title.c_str());
    std::cout << "PAPER: OpenGL context opened" << std::endl;
    Start();

    while (!WindowShouldClose())
    {
        PaperUpdate();
        Update();
        PaperDraw();
    }

    OnClose();
    Cleanup();
    CloseWindow();

    FreeImage_DeInitialise(); // deinitialize FreeImage only once
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

Vector2 PaperApp::GetCenter() {
    return (Vector2){(float)(GetScreenWidth())/2, (float)(GetScreenHeight())/2};
}

void PaperApp::AddTask(PaperTask *task) {
    this->tasks.push_back(task);
}