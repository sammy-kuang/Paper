#include "raylib.h"
#include "PaperObjects.h"
#include "PaperApp.h"
#include <vector>

#ifndef PAPERUTILS_H
#define PAPERUTILS_H

class PaperUtils {

    public:
        // centering methods
        static Vector2 CenterRectToPoint(Vector2 point, Vector2 size);
        static Vector2 CenterTextToPoint(Vector2 point, Font font, float fontSize, std::string text, float spacing);
        static Vector2 CenterTextToPoint(Vector2 point, FontData fontData, std::string text);
        static Vector2 CenterTextureToPoint(Vector2 point, Texture2D texture);
        // mouse detection methods
        static bool IsMouseOver(Rectangle rect);
        static bool IsMouseOver(Circle circle);
        static bool IsMouseOver(Texture2D texture, Vector2 pos);
        
        static bool RectClick(Rectangle rect, MouseButton mb = MOUSE_LEFT_BUTTON);
        static bool RectClicked(Rectangle rect, MouseButton mb = MOUSE_LEFT_BUTTON);
        
        static bool TextureClick(Texture2D texture, Vector2 pos, MouseButton mb = MOUSE_LEFT_BUTTON);
        static bool TextureClicked(Texture2D texture, Vector2 pos, MouseButton mb = MOUSE_LEFT_BUTTON);

        // draw methods
        static void DrawText(FontData fontData, std::string text, Vector2 position, Color color);
        static void DrawCircle(Circle circle, Color color);
        static void DrawCenteredObject(CenteredObject obj);

        static bool CompareColor(Color a, Color b);
        static std::vector<Texture2D> GetTexturesFromDirectory(std::string directory);
        static std::vector<Texture2D> GetTexturesFromPaths(std::vector<std::string> paths);
        static std::vector<std::string> LoadGIF(std::string path, PaperApp *instance); 


        // additional methods
        static Rectangle CreateRectangle(Vector2 pos, Vector2 size);
};

#endif