#pragma once
#include <vector>
#include <functional>
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
	virtual void Resized() {};
	void Action();
	UIControl * Set(int x, int y, int w, int h);
	UIControl * SetText(const char* txt);
	int GetX();
	int GetY();
	int GetW();
	int GetH();
	const char* GetText();
	virtual bool InBounds(int x, int y);
	void AddControl(UIControl* control);
	void SetRoot(UIControl* root);
	int ControlsCount();
	bool GetActive() {
		return Active;
	};
	void SetActive(bool active) {
		Active = active;
	};
	UIControl* GetControl(int index);
	void SetAction(void(*action)());
	void SetSize(int w, int h)
	{
		W = w;
		H = h;
		Resized();
	}
	void SetActionOne(std::function<void()> one) {
		actOne = one;
	};
	void SetDrag(std::function<void(int, int) > drag)
	{
		actDrag = drag;
	}

	virtual void Dragged(int x,int y)
	{
		if (actDrag != NULL) {
			actDrag(x, y);
		}
	}


	void SetX(int x) {
		X = x;
	};

	void SetY(int y) {
		Y = y;
	}

private:
	void (*actionPtr)();
	UIControl* Root;
	std::vector<UIControl*> Controls;
	const char* Text;
	int X, Y, W, H;
	bool Active = false;
	std::function<void()> actOne;
	std::function<void(int, int)> actDrag;

};


