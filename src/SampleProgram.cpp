#include "Paper.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}
        PaperTextBox ptb;
        Circle circle;

        void Start() override {
            SetTargetFPS(60);
            ptb = PaperTextBox(GetCenter(), (Vector2) {250, 50}, "Running Paper!", 14);
            circle = Circle(GetCenter(), 10);
        }

        void Update () override {
            
        }

        void Draw() override {
            ClearBackground(WHITE);
            PaperUtils::DrawCircle(circle, RED);
            ptb.Draw();
        }   
};

int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}
