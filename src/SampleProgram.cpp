#include "Paper.h"
#include <iostream>
#include <filesystem>

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}
        PaperListView pdb;
        PaperGroupBox pgb;
        std::vector<std::string> list;

        void Start() override {
            SetTargetFPS(30);
            list.push_back("Made in");
            list.push_back("#80#Paper!");
            pgb = PaperGroupBox(GetCenter(), (Vector2){200, 200}, "Lists");
            pdb = PaperListView((Vector2){GetCenter().x, GetCenter().y}, (Vector2){150, 150}, list);
        }

        void Update () override {
            
        }

        void Draw() override {
            ClearBackground(WHITE);
            pdb.DrawCentered();
            pgb.DrawCentered();
        }   
};

int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}