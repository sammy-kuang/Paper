#include "Paper.h"
#include "raylib.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:
        CenteredText centeredText;
        FontData fd;

        Program() : PaperApp(1280, 720, "Paper Project") {}
        
        void Start() override {
            SetTargetFPS(60);

            fd = FontData(GetFontDefault(), 32.0f, 1.0f);
            centeredText = CenteredText((Vector2){(float)this->width/2, (float)this->height/2}, fd, BLACK, "Made in Paper!");
        }

        void Update () override {

        }

        void Draw() override {
            ClearBackground(WHITE);
            centeredText.Draw();
        }
};

int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}