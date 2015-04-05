#include <fstream>
#include <iostream>
#include "Settings.h"
#define BUFFER_SIZE 1024

// Read settings from file
//
//
using namespace std;

Settings::Settings(void)
{
	std::ifstream infile("settings.txt");
	char* key = new char[BUFFER_SIZE];
	char* value = new char[BUFFER_SIZE];
	this->uri = new char[BUFFER_SIZE];
	while(infile >> key >> value)
	{
		if(strcmp(key, "uri") == 0){
			strcpy(this->uri, value);
		}
		if(strcmp(key, "lineLength") == 0){
			this->lineLenght = atoi(value);
		}
	}
	delete(key);
	delete(value);
}

Settings::~Settings(void)
{
	delete(this->uri);
}

void Settings::toString(void)
{
	cout << "Settings" << endl;
	cout << "Uri: " << this->uri << endl;
	cout << "LineLength: " << this->lineLenght << endl;
}
