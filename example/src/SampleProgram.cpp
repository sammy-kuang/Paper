#include "Paper.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}
        PaperTextBox ptb;

        void Start() override {
            SetTargetFPS(60);
            ptb = PaperTextBox(GetCenter(), (Vector2) {250, 50}, "Running Paper!", 64);
        }

        void Update () override {
            
        }

        void Draw() override {
            ClearBackground(WHITE);
            ptb.Draw();
        }   
};

int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}