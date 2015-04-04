#define BUFFER_SIZE 5000000

#include <iostream>
#include "createDir.h"
#include "httpClient.h"
#include "fileWriter.h"
#include "htmlParser.h"

using namespace std;
using namespace httpClient;
using namespace createDir;
using namespace fileWriter;
using namespace htmlParser;

int main(int argc, char** argv)
{	
	if(argc != 2)
	{
		cout << "Wrong number of arguments. " << endl;
		return 1;
	}
	char* content = new char[BUFFER_SIZE];
	char* const uri = argv[1];
	char* path = getPathFromUri(uri);
	char* const hostName = getHostNameFromUri(uri);

	memset(&content[0], 0, BUFFER_SIZE);
	getContentByUri(hostName, uri, content);
	createDirByPath(path);
	string str(content);
	writeFile(path, getTitle(str));
	cout << "Ok" << endl;
	delete(content);
	return 0;	
}

