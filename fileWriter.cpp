#define BUFFER_SIZE 1024
#define HTTP_OFFSET 7

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


namespace fileWriter
{

	// Creates string for current date time
	//
	//
	char* getCurrentDate()
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
	int writeFile(char* path, string content)
	{
		ofstream file;
		char fileName[BUFFER_SIZE];
		sprintf(fileName, "%s/%s.txt", path, getCurrentDate());
		file.open (fileName);
		file << content;
		file.close();
		return 0;
	}

	// Returns URI without http://
	//
	//
	char* getPathFromUri(char* uri)
	{
		char* buffer = new char[BUFFER_SIZE];
		strcpy(buffer, uri + HTTP_OFFSET);
		return buffer;
	}

	// Returns domain from URI string
	//
	//
	char* getHostNameFromUri(char* uri)
	{
		char* buffer = new char[BUFFER_SIZE];
		memset(buffer, 0, BUFFER_SIZE);
		string str(uri);
		int length = str.find("/", HTTP_OFFSET);
		memcpy(buffer, uri + HTTP_OFFSET, length - HTTP_OFFSET);
		return buffer;
	}
}