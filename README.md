# Paper
## C++ rewrite of PaperSDL, dedicated to making raylib and raygui just a little easier to work with. https://github.com/raysan5/raylib

### Usage:
Copy the files from the example folder into a directory of your choosing

Create a folder called "build", and navigate into it

Compile your source folder using CMake:
```bash
mkdir build # create a build directory
cd build # navigate into your new build directory
cmake .. # configure the project
make -j8 # compile the project (you can substitute the 8 with the number of cores you have)
./SampleProgram # you should be able to run the binary now! if you're on windows, the command will be .\SampleProgram.exe
```
This should produce a binary called "SampleProgram". You can change the program name by changing line 2 on the CMakeLists.txt file.

### SampleProgram.cpp:
```cpp
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
```
