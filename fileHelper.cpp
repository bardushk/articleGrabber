#define BUFFER_SIZE 1024
#define HTTP_OFFSET 7

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>
#include "FileHelper.h"

using namespace std;

// Creates string for current date time
//
//
char* FileHelper::_getCurrentDate()
{
	time_t rawTime;
	struct tm * timeInfo;
	char *buffer = new char[BUFFER_SIZE];
	time (&rawTime);
	timeInfo = localtime(&rawTime);
	strftime(buffer,80,"%Y_%m_%d__%I_%M_%S", timeInfo);
	return buffer;
}

// Saves content to the text file, using path
//
//
int FileHelper::writeFile(char* path, string content)
{		
	setlocale(LC_ALL, "Russian");
	ofstream file;
	char fileName[BUFFER_SIZE];
	sprintf(fileName, "%s/%s.txt", path, FileHelper::_getCurrentDate());

	file.open (fileName);
	file << content; 
	file.close();

	return 0;
}

// Returns URI without http://
//
//
char* FileHelper::getPathFromUri(char* uri)
{
	char* buffer = new char[BUFFER_SIZE];
	strcpy(buffer, uri + HTTP_OFFSET);
	return buffer;
}

// Returns domain from URI string
//
//
char* FileHelper::getHostNameFromUri(char* uri)
{
	char* buffer = new char[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);
	string str(uri);
	int length = str.find("/", HTTP_OFFSET);
	memcpy(buffer, uri + HTTP_OFFSET, length - HTTP_OFFSET);
	return buffer;
}
