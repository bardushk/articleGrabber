#pragma once
#pragma once
#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <string>

using namespace std;

namespace fileWriter
{
	int writeFile(char* path, string content);
	char* getPathFromUri(char* path);
	char* getHostNameFromUri(char* uri);
}

#endif