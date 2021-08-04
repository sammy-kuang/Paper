#include "Paper.h"
#include <iostream>
#include <filesystem>

using namespace std;

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}

        vector<string> list;
        PaperDropdownBox *plv;

        void Start() override {
            SetTargetFPS(60);
            list.push_back("Running");
            list.push_back("#10#Paper!");
            plv = new PaperDropdownBox(GetCenter(), Vector2{250, 50}, list);
        }

        void Update () override {
            plv->Draw();
        }

        void Draw() override {
            ClearBackground(WHITE);
        }   
};

int main(int argc, char *argv[]) {
    Program *paperApp = new Program();
    paperApp->PaperStart();
}
