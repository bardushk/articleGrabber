#define BUFFER_SIZE 5000000
#define HTTP_OFFSET 8

#include <iostream>
#include "createDir.h"
#include "httpClient.h"
#include "fileWriter.h"

using namespace std;
using namespace httpClient;
using namespace createDir;
using namespace fileWriter;

int main()
{	
	char* content = new char[BUFFER_SIZE];
	char* const path = "FOO/Bar/klop";
	char* const hostName = "snob.ru";
	char* const uri = "http://snob.ru/magazine/entry/90524";

	memset(&content[0], 0, BUFFER_SIZE);
	getContentByUri(hostName, uri, content);
	createDirByPath(path);
	writeFile(uri + HTTP_OFFSET, content);
	cout << "Ok" << endl;
	delete(content);
	return 0;	
}

