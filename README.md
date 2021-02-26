# Paper
## C++ rewrite of PaperSDL, dedicated to making raylib and raygui just a little easier to work with. https://github.com/raysan5/raylib

**Usage**:
Clone the files into your C++ project directory.
Use the "Paper.h" header file for quick access to all methods.
Read the header files for a list of methods.


### SampleProgram.cpp:
```
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
            ptb.DrawCentered();
        }   
};

int main(int argc, char *argv[]) {
    Program paperApp = Program();
    paperApp.PaperStart();
}
```
