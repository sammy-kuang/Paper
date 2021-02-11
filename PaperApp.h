#include <string>
#include <vector>

#ifndef PAPERAPP_H
#define PAPERAPP_H

class PaperApp {
    public:
        int width;
        int height;
        std::string title;
        
        PaperApp(int x, int y, std::string title);

        virtual void Awake() {}
        virtual void Start() {}
        virtual void Update() {}
        virtual void OnClose() {}

        virtual void Draw();
        
        virtual void PaperDraw();
        virtual void PaperStart();

        void RemoveFileOnCleanup(std::string str);

    private:
        std::vector<std::string> filesToRemove;
        void Cleanup();
};

#endif