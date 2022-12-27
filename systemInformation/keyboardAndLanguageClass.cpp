#include "keyboardAndLanguageClass.h"
int keyboardAndLanguageClass::getKeyboard(){
	return GetConsoleCP();
	//https://learn.microsoft.com/en-us/windows/win32/intl/code-page-identifiers
}
int keyboardAndLanguageClass::getlenguage(){
	return GetUserDefaultUILanguage();
	//https://learn.microsoft.com/en-us/openspecs/office_standards/ms-oe376/6c085406-a698-4e12-9d4d-c3b0ee3dbc4a
}
