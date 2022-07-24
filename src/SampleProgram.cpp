#include "Paper.h"
#include <iostream>
#include <filesystem>

using namespace std;

class Program : public PaperApp {
    public:
        Program() : PaperApp(640, 480, "Paper Project") {}
        
        void Start() override {
            SetTargetFPS(60);
        }

        void Update () override {
        
        }

        void Draw() override {
            ClearBackground(WHITE);
        }
};

int main(int argc, char *argv[]) {
    Program *p = new Program();
    p->PaperStart();
}    
