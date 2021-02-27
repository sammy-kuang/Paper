#include <string>
#include <vector>
#include "raylib.h"

class PaperUI {
    public:
        static std::string IconText(int iconId, std::string text);
        static void SetGUIOptions(int control, int property, int value);
        static void SetTextOnButtonCentered();
};

class UIObject {
    public:
        Vector2 position;
        Vector2 size;
        Rectangle rectangle;
        UIObject() {}
        UIObject(Vector2 position, Vector2 size);
        void Draw();
        void DrawCentered();
        virtual void DrawPos(Vector2 pos, Vector2 size) {};
    private:
        Vector2 centerPos;
};

class PaperTextBox : public UIObject {
    public:
        std::string initialText;
        int initialSize;
        PaperTextBox () {}
        PaperTextBox(Vector2 position, Vector2 size, std::string initialText, int initialSize = 25);

        std::string GetText();

        void DrawPos(Vector2 pos, Vector2 size) override;
    private:
        char text[64];
        bool editMode = false;
};


class PaperSlider : public UIObject {
    public:
        std::string label;
        bool showValue;
        int sliderValue;
        int minValue;
        int maxValue;
        PaperSlider() {}
        PaperSlider(Vector2 position, Vector2 size, std::string label, bool showValue, int sliderValue, int minValue, int maxValue);
        
        void DrawPos(Vector2 pos, Vector2 size) override;

        std::string GetValueString();
        int GetValue();
};

class PaperSliderBar : public PaperSlider {
    public:
        PaperSliderBar() {}
        PaperSliderBar(Vector2 position, Vector2 size, std::string label,bool showValue, int sliderValue, int minValue, int maxValue);
            
        void DrawPos(Vector2 pos, Vector2 size) override;
};

class PaperClickable : public UIObject {
    public:
        PaperClickable() {}
        PaperClickable(Vector2 position, Vector2 size, std::string label);
        std::string label;
        bool clicked = false;
};

class PaperButton : public PaperClickable {
    public:
        PaperButton() {}
        PaperButton(Vector2 position, Vector2 size, std::string label);
        
        void DrawPos(Vector2 pos, Vector2 size) override;
        bool Clicked();
};

class PaperCheckbox : public PaperClickable {
    public:
        PaperCheckbox() {}
        PaperCheckbox(Vector2 position, Vector2 size, std::string label);
        void DrawPos(Vector2 pos, Vector2 size) override;
        bool Checked();
};

class PaperDropdownBox : public UIObject {
    public:
        PaperDropdownBox() {}
        PaperDropdownBox(Vector2 position, Vector2 size, std::vector<std::string> list);
        std::vector<std::string> list;
        int curIndex = 0;
        bool editMode = false;
        std::string text = "";
        void DrawPos(Vector2 pos, Vector2 size) override;
    private:
        void ConstructString();
};

class PaperListView : public PaperDropdownBox {
    public:
        PaperListView() {}
        PaperListView(Vector2 position, Vector2 size, std::vector<std::string> list);
        void DrawPos(Vector2 pos, Vector2 size) override;
};

class PaperGroupBox : public UIObject {
    public:
        PaperGroupBox() {}
        PaperGroupBox(Vector2 position, Vector2 size, std::string label);
        std::string label;

        void DrawPos(Vector2 pos, Vector2 size) override;
};

