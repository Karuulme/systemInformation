#pragma once
#include <iostream>
#include <string>
#include <Shlobj_core.h>
using namespace std;
class installedProgramsClass
{
private:
	int StringToWString(std::wstring& ws, const std::string& s);
public:
	void installedProgramsList();
};

