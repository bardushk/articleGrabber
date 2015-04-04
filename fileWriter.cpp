#define BUFFER_SIZE 1024
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
	  char buffer[BUFFER_SIZE];
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
		char* fileName = new char[BUFFER_SIZE];
		sprintf(fileName, "%s/%s.txt", path, getCurrentDate());
		file.open (fileName);
		string str(content);
		file << str;
		file.close();
		return 0;
	}
}
