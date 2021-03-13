#include "Paper.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}
        PaperCheckbox pcb;

        void Start() override {
            SetTargetFPS(30);
            pcb = PaperCheckbox(GetCenter(), (Vector2){50, 50}, "Done?");
        }

        void Update () override {
        }

        void Draw() override {
            ClearBackground(RAYWHITE);
            pcb.Draw();
        }
};


int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}
