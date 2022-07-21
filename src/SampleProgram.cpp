#include "Paper.h"
#include <iostream>
#include <filesystem>

using namespace std;

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}

        vector<string> list;
        PaperListView *plv;

        void Start() override {
            SetTargetFPS(60);
            list.push_back("Running");
            list.push_back("#10#Paper!");
            list.push_back("Now using");
            list.push_back("Raylib 4.0!");
            plv = new PaperListView(GetCenter(), Vector2{250, 100}, list);
        }

        void Update () override {

        }

        void Draw() override {
            ClearBackground(WHITE);
            plv->Draw();
        }
};

int main(int argc, char *argv[]) {
    Program *p = new Program();
    p->PaperStart();
}    
