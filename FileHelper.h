#pragma once
#ifndef FILEHELPER_H
#define FILEHELPER_H

class FileHelper
{
	char* _getCurrentDate();
public:
	int writeFile(char* path, std::string content);
	char* getPathFromUri(char* uri);
	char* getHostNameFromUri(char* uri);
};

#endif