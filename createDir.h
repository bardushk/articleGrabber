#pragma once
#ifndef CREATEFOLDER_H
#define CREATEFOLDER_H
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class CreateDir
{
	int _getNextDir(const string& path, string &dirName, int start);
	bool CreateDir::_dirExists(const string& dirName_in);
	wstring CreateDir::_s2ws(const string& s);
public:
	int createDirByPath(const string a);
};

#endif