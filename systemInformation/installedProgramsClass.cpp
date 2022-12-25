#include "installedProgramsClass.h"

int installedProgramsClass::StringToWString(std::wstring& ws, const std::string& s)
{
    std::wstring wsTmp(s.begin(), s.end());
    ws = wsTmp;
    return 0;
}
#define BUFFER 8192

void installedProgramsClass::installedProgramsList() {
    PVOID   pvData = {};
    LPDWORD pcbData = (LPDWORD)pvData;
    HKEY  regKey;
    HKEY machine;
    string pathX;
    if (IsUserAnAdmin())
    {
        pathX = "SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\";
        machine = HKEY_LOCAL_MACHINE;
    }
    else {
        cout << "-------------DAHA FAZLASI ICIN YONETICI OLARAK BASLATIN-------------" << endl << endl;
        pathX = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\";
        machine = HKEY_CURRENT_USER;
    }
    std::wstring name;
    StringToWString(name, pathX);
    const wchar_t* szName = name.c_str();
    DWORD BufferSize = BUFFER;
    RegOpenKeyEx(machine, szName, 0, KEY_ALL_ACCESS, &regKey);
    TCHAR    achKey[_MAX_PATH];
    TCHAR    achClass[MAX_PATH] = TEXT("");
    DWORD    cchClassName = MAX_PATH;
    DWORD    cSubKeys = 0;
    DWORD    cbMaxSubKey;
    DWORD    cchMaxClass;
    DWORD    cValues;
    DWORD    cchMaxValue;
    DWORD    cbMaxValueData;
    DWORD    cbSecurityDescriptor;
    FILETIME ftLastWriteTime;
    DWORD i, retCode;
    RegQueryInfoKey(
        regKey,
        achClass,
        &cchClassName,
        NULL,
        &cSubKeys,
        &cbMaxSubKey,
        &cchMaxClass,
        &cValues,
        &cchMaxValue,
        &cbMaxValueData,
        &cbSecurityDescriptor,
        &ftLastWriteTime);
    DWORD   cbName;
    for (i = 0; i < cSubKeys; i++) {
        cbName = _MAX_PATH;
        retCode = RegEnumKeyEx(regKey, i,
            achKey,
            &cbName,
            NULL,
            NULL,
            NULL,
            &ftLastWriteTime);
        if (retCode == ERROR_SUCCESS)
        {
            std::string str;
            std::wstring wStr = achKey;
            str = std::string(wStr.begin(), wStr.end());
            string path2 = pathX + str;
            /* std::wstring to_wstring(const std::string & stringToConvert);
             std::wstring name;
             StringToWString(name, path2);
             const wchar_t* szName = name.c_str();*/
            char value[255];
            DWORD BufferSize = BUFFER;
            LSTATUS st = RegGetValueA(machine, path2.c_str(), "DisplayName", RRF_RT_ANY, NULL, (PVOID)&value, &BufferSize);
            cout << i << " " << value << endl;
        }
    }
    RegCloseKey(machine);
    RegCloseKey(regKey);
}
