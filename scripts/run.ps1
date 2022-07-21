gcc src/*.cpp -o game.exe -O1  -I include/ -L lib/ -lfreeimage -lraylib -lstdc++ -lopengl32 -lgdi32 -lwinmm
.\game.exe