#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <Fileapi.h>
using namespace std;
class storagePartitionsClass
{

private:
	double byteToGb(long double byte);
public:
	void  storageList();
};

