#pragma once
#pragma once
#ifndef FILEWRITER_H
#define FILEWRITER_H

namespace fileWriter
{
	int writeFile(char* path, char * content);
	char* getPathFromUri(char* path);
	char* getHostNameFromUri(char* uri);
}

#endif