
#include <iostream>
#include <windows.h>
#include <string>
#include "CreateDir.h"

using namespace std;

//
// Get next dirName from path string
// start current simbol position for sear
// 
int CreateDir::_getNextDir(const string& path, string &dirName, int start)
{
	int position = 0, length = 0;
	position = path.find("/", start);
	if(position < 0) 
	{
		dirName = path;
		return -1;
	}
	length = position - start;
	dirName = path.substr(0, position);
	return position + 1;
}

// Check if the directory exists
//
bool CreateDir::_dirExists(const string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

wstring CreateDir::_s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

// Creates directories if they not exists by path string
// Starts with current directory
//
int CreateDir::createDirByPath(const string path)
{
	int start = 0;
	string dirName;
	for(;;)
	{
		start = CreateDir::_getNextDir(path, dirName, start);
		if(!CreateDir::_dirExists(dirName))
		{
			if(!CreateDirectory(CreateDir::_s2ws(dirName).c_str(), NULL))
			{
				cout << "Error " << GetLastError() << endl;
				return 1;
			}
		}
		if(start < 0) break;
	}
	return 0;
}
