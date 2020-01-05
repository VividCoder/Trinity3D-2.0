#pragma once
#include <vector>
class UIControl
{
public:
	UIControl();
	virtual void Update() {};
	virtual void Render() {};
	virtual void MouseEnter() {};
	virtual void MouseLeave() {};
	virtual void MouseDown(int button) {  };
	virtual void MouseUp(int button) {};
	void Action();
	UIControl * Set(int x, int y, int w, int h);
	UIControl * SetText(const char* txt);
	int GetX();
	int GetY();
	int GetW();
	int GetH();
	void AddControl(UIControl* control);
	void SetRoot(UIControl* root);
	int ControlsCount();
	UIControl* GetControl(int index);
private:
	void (*actionPtr)();
	UIControl* Root;
	std::vector<UIControl*> Controls;
	const char* Text;
	int X, Y, W, H;

};


