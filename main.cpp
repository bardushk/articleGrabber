#define BUFFER_SIZE 5000000

#include <iostream>
#include "createDir.h"
#include "httpClient.h"
#include "FileHelper.h"
#include "HtmlParser.h"
#include "CreateDir.h"
#include "HttpClient.h"

using namespace std;

int main(int argc, char** argv)
{	
	if(argc != 2)
	{
		cout << "Wrong number of arguments. " << endl;
		return 1;
	}

	FileHelper FileHelper;
	CreateDir createDir;
	HttpClient httpHelper;

	char* content = new char[BUFFER_SIZE];
	char* const uri = argv[1];
	char* path = FileHelper.getPathFromUri(uri);
	char* const hostName = FileHelper.getHostNameFromUri(uri);

	HtmlParser htmlParser;

	memset(&content[0], 0, BUFFER_SIZE);
	httpHelper.getContentByUri(hostName, uri, content);
	string str(content);
	createDir.createDirByPath(path);
	int start = 0;
	FileHelper.writeFile(path, htmlParser.splitIntoStrings(htmlParser.hrefFormat(htmlParser.getTag(str, "title", start) + string("\n\n") + htmlParser.getAllTags(str, "p")), 80));
	cout << "Ok" << endl;

	delete(content);
	return 0;
}

