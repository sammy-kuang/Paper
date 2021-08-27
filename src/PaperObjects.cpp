#include <string>
#include <vector>
#include <iostream>
#include "raylib.h"
#include "PaperObjects.h"
#include "PaperUtils.h"
#include "PaperApp.h"

Circle::Circle(Vector2 position, float radius) {
    this->position = position;
    this->radius = radius;
}

FontData::FontData(Font font, float fontSize, float spacing) {
    this->font = font;
    this->fontSize = fontSize;
    this->spacing = spacing;
}

CenteredObject::CenteredObject(Vector2 pos) {
    this->position = pos;
}

 
// centered rectangle start
CenteredRectangle::CenteredRectangle(Vector2 pos, Vector2 size) :  CenteredObject(pos) {
    this->size = size;
    Center();
}

void CenteredRectangle::Center() {
    literalPosition = PaperUtils::CenterRectToPoint(position, size);
    rectangle = (Rectangle){literalPosition.x, literalPosition.y, size.x, size.y};
}

void CenteredRectangle::Draw() {
    DrawRectangleRec(rectangle, BLACK);
}

void CenteredRectangle::Draw(Color color) {
    DrawRectangleRec(rectangle, color);
}

void CenteredRectangle::DrawUncentered() {
    DrawRectangleRec((Rectangle){position.x, position.y, size.x, size.y}, BLACK);
}

Rectangle CenteredRectangle::GetRectangle() {
    return this->rectangle;
}

// text object start
TextObject::TextObject(Vector2 pos, FontData fontData, Color color, std::string text) : CenteredObject(pos) {
    this->fontData = fontData;
    this->color = color;
    this-> text = text;

    Center();
}   

TextObject::TextObject(Vector2 pos, FontData fontData, Color color) : CenteredObject(pos) {
    this->fontData = fontData;
    this->color = color;

    Center();
}

void TextObject::SetText(std::string newText) {
    text = newText;
    Center();
}

void TextObject::Center() {
    literalPosition = position;
}

void TextObject::Draw() {
    PaperUtils::DrawText(fontData, text, literalPosition, color);
}

// centered text start
CenteredText::CenteredText(Vector2 pos, FontData fd, Color color, std::string text) : TextObject(pos, fd, color, text){Center();}
CenteredText::CenteredText(Vector2 pos, FontData fd, Color color) : TextObject(pos, fd, color) {Center();}

void CenteredText::Center() {
    literalPosition = PaperUtils::CenterTextToPoint(position, fontData, text);
}

// centered texture start
CenteredTexture::CenteredTexture(Vector2 pos, Texture2D texture) : CenteredObject(pos) {
    this->texture = texture;
    Center();
}

void CenteredTexture::Center() {
    literalPosition = PaperUtils::CenterTextureToPoint(position, texture);
}

void CenteredTexture::Draw() {
    DrawTexture(texture, literalPosition.x, literalPosition.y, WHITE);
}

// centered animated texture start
CenteredAnimatedTexture::CenteredAnimatedTexture(Vector2 pos, std::vector<Texture2D> images, float timeUntilNextFrame) : CenteredObject(pos) {
    this->frames = images;

    if(!CanDraw()) {
        std::cout << "PAPER: WARNING: No textures provided in animated texture!" << std::endl;
    }

    this->timeUntilNextFrame = timeUntilNextFrame;
    nextFrameTime = timeUntilNextFrame;
    currentFrame = frames[currentIndex];

    Center();
}

void CenteredAnimatedTexture::Update(float deltaTime) {
    if(nextFrameTime > 0) {
        nextFrameTime -= deltaTime;
    }
    else {
        currentIndex++;
        if(currentIndex>frames.size()-1) {
            currentIndex = 0;
        }
        currentFrame = frames[currentIndex];
        nextFrameTime = timeUntilNextFrame;
    }
}

void CenteredAnimatedTexture::Center() {
    literalPosition = PaperUtils::CenterTextureToPoint(position, currentFrame);
}

void CenteredAnimatedTexture::Draw() {
    
    if(!CanDraw()) {
        std::cout << "PAPER: ERROR: Not drawing animated texture; No textures provided!" << std::endl;
        return;
    }

    Update(GetFrameTime());
    DrawTexture(currentFrame, literalPosition.x, literalPosition.y, WHITE);
}

bool CenteredAnimatedTexture::CanDraw() {
    return frames.size() > 0;
}

PaperTask::PaperTask(PaperApp *app) {
    this->app = app;
    app->AddTask(this);
}

void PaperTask::Run() {
    std::cout << "Running a PaperTask" << std::endl;
}