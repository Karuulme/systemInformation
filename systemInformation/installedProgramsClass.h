#pragma once
#include "library.cpp"
class installedProgramsClass
{
private:
	int StringToWString(std::wstring& ws, const std::string& s);
public:
	void installedProgramsList();
};

