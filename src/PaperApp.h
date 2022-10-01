#ifndef PAPERAPP_H
#define PAPERAPP_H
#include <string>
#include <vector>
#include "raylib.h"


class PaperTask;

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
        virtual void PaperUpdate(); // Additional update loop for "tasks"

        // Tasks are a concept for background processing of tasks for internal Paper work. 
        std::vector<PaperTask*> tasks;
        void AddTask(PaperTask *task);

        void RemoveFileOnCleanup(std::string str);
        Vector2 GetCenter();

    private:
        int initWidth;
        int initHeight;
        std::vector<std::string> filesToRemove;
        void Cleanup();
};

#endif