#include "raylib.h"
#include <string>
#include <vector>

class PaperApp;

#ifndef PAPEROBJECTS_H
#define PAPEROBJECTS_H

class Circle {
    public:
        Vector2 position;
        float radius;
        Circle() {}
        Circle(Vector2 position, float radius);
};

class FontData {
    public:
        Font font;
        float fontSize;
        float spacing;
        FontData() {}
        FontData(Font font, float fontSize, float spacing = 0.0f);
};

class CenteredObject {
    public:
        Vector2 literalPosition;
        Vector2 position;
        CenteredObject() {}
        CenteredObject(Vector2 pos);
        virtual void Center() {}
        virtual void Draw() {}
        virtual void DrawPos(Vector2 position) {}
        virtual void DrawUncentered() {}
        void Tween(Vector2 newPos, float totalTime, float stepTime, float curTime = 0);
};

class CenteredRectangle : public CenteredObject {
    public:
        Rectangle rectangle;
        Vector2 size;
        CenteredRectangle() {}
        CenteredRectangle(Vector2 pos, Vector2 size);
        Rectangle GetRectangle();
        void Center() override;
        void Draw() override;
        void DrawUncentered() override;
        void Draw(Color color);
};

class TextObject : public CenteredObject {
    public:
        std::string text;
        FontData fontData;
        Color color;

        TextObject() {}
        TextObject(Vector2 pos, FontData fontData, Color color, std::string text);
        TextObject(Vector2 pos, FontData fontData, Color color);

        void SetText(std::string newText);
        void Center() override;
        void Draw() override;
};

class CenteredText : public TextObject {
    public:
        CenteredText() {}
        CenteredText(Vector2 pos, FontData fd, Color color);
        CenteredText(Vector2 pos, FontData fd, Color color, std::string text);
        void Center() override;
};

class CenteredAnimatedTexture : public CenteredObject {
    private:
        float timeUntilNextFrame;
        float nextFrameTime;
        Texture2D currentFrame;
        int currentIndex = 0;
    public:
        std::vector<Texture2D> frames;
        CenteredAnimatedTexture() {}
        CenteredAnimatedTexture(Vector2 pos, std::vector<Texture2D> frames, float timeUntilNextFrame);
        void Update(float deltaTime);
        void Center() override;
        void Draw() override;
        bool CanDraw();

};

// Implementation of Tasks concept

class PaperTask {
    public:
        PaperTask(PaperApp *app);
        virtual void Run() {}
    private:
        PaperApp *app;
};

#endif



