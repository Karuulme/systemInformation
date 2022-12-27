#include "storagePartitionsClass.h"
#include "installedProgramsClass.h"
#include "displayListClass.h"
#include "ramClass.h"
#include "kernelInfoClass.h"
#include "OSClass.h"
#include "keyboardAndLanguageClass.h"
int main() {
	storagePartitionsClass diskler;
	installedProgramsClass yukluProgramlar;
	displayListClass display;
	kernelInfoClass kernel;
	ramClass ram;
	OSClass os;
	keyboardAndLanguageClass keyboardLanguage;
	cout << "---------------------------------------------------------------------"<<endl;
	diskler.storageList();
	cout << "---------------------------------------------------------------------" << endl;
	yukluProgramlar.installedProgramsList();
	cout << "---------------------------------------------------------------------" << endl;
	display.getDisplay();
	cout << "---------------------------------------------------------------------" << endl;
	cout<<"GB Ram->" << ram.getRam()/1024/1024<<endl;
	cout << "---------------------------------------------------------------------" << endl;
	kernel.getKernel();
	cout << "---------------------------------------------------------------------" << endl;
	cout<<"isletim sistemi->"<<os.getOS();
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Kılavye->" << keyboardLanguage.getKeyboard();
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Dil->" << keyboardLanguage.getlenguage();
	cout << "---------------------------------------------------------------------" << endl;


};