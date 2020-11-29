#include "save.h"
#include <fstream>
#include <iostream>

//private functions



void Save::saveToFile()
{
	saveFile.open("test.txt", std::ios::in | std::ios::out);
	if (this->saveFile.is_open()) {
		std::cout << "udalo sie" << std::endl;
		saveFile << "testowy napis \n";
	}
	saveFile.close();
}





//constructor and destructor

Save::Save()
{
}

Save::~Save()
{
}

