#include "PaperUI.h"
#include "PaperUtils.h"
#include <string>
#include <iostream>
#include <vector>
#include "raylib.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wenum-compare"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

#pragma GCC diagnostic pop

std::string PaperUI::IconText(int iconId, std::string text) {
    return GuiIconText(iconId,text.c_str());
}

void PaperUI::SetGUIOptions(int control, int property, int value) {
    GuiSetStyle(control, property, value);
}

void PaperUI::SetTextOnButtonCentered() {
    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
}

void PaperUI::LoadStyle(std::string path) {
    GuiLoadStyle(path.c_str());
}

void PaperUI::DrawThemeColor() {
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
}

PaperUIObject::PaperUIObject(Vector2 position, Vector2 size) : CenteredRectangle(position, size) {
    Center();
}

void PaperUIObject::Draw() {
    DrawPos(literalPosition);
}

void PaperUIObject::DrawUncentered() {
    DrawPos(position);
}

// PaperTextBox

PaperTextBox::PaperTextBox(Vector2 position, Vector2 size, std::string initialText, int initialSize) : PaperUIObject(position, size) {
    this->initialText = initialText;
    this->initialSize = initialSize;

    strcpy(this->text, initialText.c_str());
}


void PaperTextBox::DrawPos(Vector2 pos) {
    if(GuiTextBox(PaperUtils::CreateRectangle(pos,this->size), text, initialSize, editMode)) editMode = !editMode;
}


std::string PaperTextBox::GetText() {
    return this->text;
}

// PaperSlider
PaperSlider::PaperSlider(Vector2 position, Vector2 size, std::string label, bool showValue,int sliderValue, int minValue, int maxValue) : PaperUIObject(position, size) {
    this->label = label;
    this->showValue = showValue;
    this->sliderValue = sliderValue;
    this->minValue = minValue;
    this->maxValue = maxValue;
}

void PaperSlider::DrawPos(Vector2 pos) {
    sliderValue = GuiSlider(PaperUtils::CreateRectangle(pos,this->size), label.c_str(), showValue ? GetValueString().c_str() : NULL, sliderValue,minValue, maxValue);
}

std::string PaperSlider::GetValueString() {
    return std::to_string(sliderValue);
}

int PaperSlider::GetValue() {
    return sliderValue;
}

// PaperSliderBar
PaperSliderBar::PaperSliderBar(Vector2 position, Vector2 size, std::string label, bool showValue,int sliderValue, int minValue, int maxValue) : PaperSlider(position, size, label, showValue,sliderValue, minValue, maxValue) {}

void PaperSliderBar::DrawPos(Vector2 pos) {
    sliderValue = GuiSliderBar(PaperUtils::CreateRectangle(pos,this->size), label.c_str(), GetValueString().c_str(), sliderValue, minValue, maxValue);
}

// PaperProgressBar
PaperProgressBar::PaperProgressBar(Vector2 position, Vector2 size, std::string label, bool showValue,int sliderValue, int minValue, int maxValue) : PaperSlider(position, size, label, showValue,sliderValue, minValue, maxValue) {}

void PaperProgressBar::DrawPos(Vector2 pos) {
    sliderValue = GuiProgressBar(PaperUtils::CreateRectangle(pos,this->size), label.c_str(), GetValueString().c_str(), sliderValue, minValue, maxValue);
}

// PaperClickable
PaperClickable::PaperClickable(Vector2 position, Vector2 size, std::string label) : PaperUIObject(position, size) {
    this->label = label;
}



// PaperButton
PaperButton::PaperButton(Vector2 position, Vector2 size, std::string label) : PaperClickable(position, size, label) {}

void PaperButton::DrawPos(Vector2 pos) {
    this->clicked = GuiButton(PaperUtils::CreateRectangle(pos,this->size), label.c_str());
}

bool PaperButton::Clicked() {
    return this->clicked;
}

// PaperCheckbox
PaperCheckbox::PaperCheckbox(Vector2 pos, Vector2 size, std::string label) : PaperClickable(pos, size, label) {}

void PaperCheckbox::DrawPos(Vector2 pos) {
    this->clicked = GuiCheckBox(PaperUtils::CreateRectangle(pos,this->size), label.c_str(), clicked);
}

bool PaperCheckbox::Checked() {
    return this->clicked;
}

// PaperDropdownBox
PaperDropdownBox::PaperDropdownBox(Vector2 pos, Vector2 size, std::vector<std::string> list) : PaperUIObject(pos, size) {
    this->list = list;
    ConstructString();
}

void PaperDropdownBox::DrawPos(Vector2 pos) {
    if(GuiDropdownBox(PaperUtils::CreateRectangle(pos, this->size), text.c_str(), &curIndex, editMode)) editMode = !editMode;
}

void PaperDropdownBox::ConstructString() {
    if(list.size() < 1) return;

    for(int i = 0; i < list.size(); i++) {
        text.append(list[i]+";");
    }
    text.replace(text.size()-1, 1, "");
}

// PaperListView
PaperListView::PaperListView(Vector2 pos, Vector2 size, std::vector<std::string> list) : PaperDropdownBox(pos, size, list) {}

void PaperListView::DrawPos(Vector2 pos) {
    editMode = GuiListView(PaperUtils::CreateRectangle(pos, this->size), text.c_str(), &curIndex, editMode);
}

// PaperGroupBox
PaperGroupBox::PaperGroupBox(Vector2 pos, Vector2 size, std::string label) : PaperUIObject(pos, size) {
    this->label = label;
}

void PaperGroupBox::DrawPos(Vector2 pos) {
    GuiGroupBox(PaperUtils::CreateRectangle(pos, size), label.c_str());
}
