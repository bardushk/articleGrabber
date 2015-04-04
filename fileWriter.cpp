#define BUFFER_SIZE 1024
#define HTTP_OFFSET 7

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

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
	int writeFile(char* path, char* content)
	{
		ofstream file;
		char fileName[BUFFER_SIZE];
		sprintf(fileName, "%s/%s.txt", path, getCurrentDate());
		file.open (fileName);
		string str(content);
		file << str;
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

	char* getHostNameFromUri(char* uri)
	{
		char* buffer = new char[BUFFER_SIZE];
		strcpy(buffer, strstr(uri + HTTP_OFFSET, "/"));
		return buffer;
	}
}
