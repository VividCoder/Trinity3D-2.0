#pragma once
#include "UIControl.h"
#include "WindowControl.h"
#include "ButtonControl.h"
#include "ListControl.h"
//#include <filesystem>
//#include <filesystem>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

class FileRequestorControl : public WindowControl
{
public:

	void SetDir(const char* ipath) {

		path p(ipath);

	
		for (auto i = directory_iterator(p); i != directory_iterator(); i++)
		{
			if (!is_directory(i->path())) //we eliminate directories in a list
			{
				cout << i->path().filename().string() << endl;
			}
			else
				continue;
		}
		while (true) {};

	};

	void Resized() {

		WindowControl::Resized();

		if (OK == NULL) {
			OK = new ButtonControl();
			Cancel = new ButtonControl();
			View = new ListControl();

			View->Set(5, 35, GetW() - 30, GetH() - 100);

			OK->Set(5, GetH() - 60, 120, 25);
			Cancel->Set(130, GetH() - 60, 120, 25);

			View->AddItem("File1/n");
			View->AddItem("File2/n");

			OK->SetText("OK!/n");

			AddControl(View);
			AddControl(OK);

			AddControl(Cancel);
		}

	};
	

private:

	ButtonControl* OK = NULL;
	ButtonControl* Cancel = NULL;
	ListControl* View;
	const char* Path = "";

};

