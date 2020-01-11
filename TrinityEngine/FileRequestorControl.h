#pragma once
#include "UIControl.h"
#include "WindowControl.h"
#include "ButtonControl.h"

class FileRequestorControl : public WindowControl
{
public:

	void Resized() {

		WindowControl::Resized();

		if (OK == NULL) {
			OK = new ButtonControl();
			Cancel = new ButtonControl();

			OK->Set(5, GetH() - 60, 120, 25);
			Cancel->Set(130, GetH() - 60, 120, 25);

			OK->SetText("OK!/n");

			AddControl(OK);

			AddControl(Cancel);
		}

	};
	

private:

	ButtonControl* OK = NULL;
	ButtonControl* Cancel = NULL;

};

