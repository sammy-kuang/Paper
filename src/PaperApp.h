#include <string>
#include <vector>
#include "raylib.h"

#ifndef PAPERAPP_H
#define PAPERAPP_H

class PaperApp {
    public:
        std::string title;
        
        PaperApp(int x, int y, std::string title);

        virtual void Awake() {} // Before window is first initialized
        virtual void Start() {} // After window is initialized
        virtual void Update() {} // Logic loop
        virtual void OnClose() {} // Events to be called when the program is closed
        virtual void OnCleanup() {} // Events to be called when the program begins its file cleanup (after OnClose)

        virtual void Draw(); // Draw loop (Moved as there is a default now)
        
        virtual void PaperDraw(); // Paper's draw order
        virtual void PaperStart(); // Paper's start order

        void RemoveFileOnCleanup(std::string str);
        Vector2 GetCenter();

    private:
        int initWidth;
        int initHeight;
        std::vector<std::string> filesToRemove;
        void Cleanup();
};

#endif