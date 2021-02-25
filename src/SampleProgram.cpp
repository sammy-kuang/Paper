#include "Paper.h"
#include "raylib.h"
#include "raygui.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:

         
        Program() : PaperApp(1280, 720, "Paper Project") {}
        
        void Start() override {
            SetTargetFPS(60);
        }

        void Update () override {

        }

        void Draw() override {
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            GuiStatusBar((Rectangle) { 0, GetScreenHeight() - 20, GetScreenWidth(), 20 }, "Made in Paper!");
        }   
};

int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}