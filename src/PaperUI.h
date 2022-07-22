#include <string>
#include <vector>
#include "PaperObjects.h"
#include "raylib.h"

class PaperApp;

class PaperUI {
    public:
        static std::string IconText(int iconId, std::string text);
        static void SetGUIOptions(int control, int property, int value);
        static void SetTextOnButtonCentered();
        static void LoadStyle(std::string styleFile);
        static void DrawThemeColor();
};

class PaperUIObject : public CenteredRectangle {
    public:
        PaperUIObject() {}
        PaperUIObject(Vector2 position, Vector2 size);
        void Draw() override;
        void DrawUncentered() override;
        void DrawPos(Vector2 pos) override {};
};

class PaperTextBox : public PaperUIObject {
    public:
        std::string initialText;
        int initialSize;
        PaperTextBox () {}
        PaperTextBox(Vector2 position, Vector2 size, std::string initialText, int initialSize = 25);

        std::string GetText();

        void DrawPos(Vector2 pos) override;
    private:
        char text[64];
        bool editMode = false;
};


class PaperSlider : public PaperUIObject {
    public:
        std::string label;
        bool showValue;
        int sliderValue;
        int minValue;
        int maxValue;
        PaperSlider() {}
        PaperSlider(Vector2 position, Vector2 size, std::string label, bool showValue, int sliderValue, int minValue, int maxValue);
        
        void DrawPos(Vector2 pos) override;

        std::string GetValueString();
        int GetValue();
};

class PaperSliderBar : public PaperSlider {
    public:
        PaperSliderBar() {}
        PaperSliderBar(Vector2 position, Vector2 size, std::string label,bool showValue, int sliderValue, int minValue, int maxValue);
            
        void DrawPos(Vector2 pos) override;
};

class PaperProgressBar : public PaperSlider {
    public:
        PaperProgressBar() {}
        PaperProgressBar(Vector2 position, Vector2 size, std::string label, bool showValue, int sliderValue, int minValue, int maxValue);
            
        void DrawPos(Vector2 pos) override;
};

class PaperClickable : public PaperUIObject {
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
        
        void DrawPos(Vector2 pos) override;
        bool Clicked();
};

class PaperCheckbox : public PaperClickable {
    public:
        PaperCheckbox() {}
        PaperCheckbox(Vector2 position, Vector2 size, std::string label);
        void DrawPos(Vector2 pos) override;
        bool Checked();
};

class PaperDropdownBox : public PaperUIObject {
    public:
        PaperDropdownBox() {}
        PaperDropdownBox(Vector2 position, Vector2 size, std::vector<std::string> initialList);
        int curIndex = 0;
        bool editMode = false;
        std::string text = "";
        void DrawPos(Vector2 pos) override;
        void CopyList(std::vector<std::string> list);
        void Add(std::string newElement);
    private:
        void ConstructString();
        std::vector<std::string> list;
};

class PaperListView : public PaperDropdownBox {
    public:
        int scrollIndex = 0;
        PaperListView() {}
        PaperListView(Vector2 position, Vector2 size, std::vector<std::string> initialList);
        void DrawPos(Vector2 pos) override;
};

class PaperGroupBox : public PaperUIObject {
    public:
        PaperGroupBox() {}
        PaperGroupBox(Vector2 position, Vector2 size, std::string label);
        std::string label;

        void DrawPos(Vector2 pos) override;
};

