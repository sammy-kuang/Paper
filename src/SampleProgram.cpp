#include "Paper.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}
        
        void Start() override {
            SetTargetFPS(30);
        }

        void Update () override {
        }

        void Draw() override {
            PaperUI::DrawThemeColor();
        }
};


int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}
