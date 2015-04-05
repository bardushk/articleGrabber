#define BUFFER_SIZE 5000000

#include <iostream>
#include "createDir.h"
#include "httpClient.h"
#include "FileHelper.h"
#include "HtmlParser.h"
#include "CreateDir.h"
#include "HttpClient.h"
#include "Settings.h"

using namespace std;

int main(int argc, char** argv)
{	
	FileHelper FileHelper;
	CreateDir createDir;
	HttpClient httpHelper;
	Settings settings;
	HtmlParser htmlParser;

	char* content = new char[BUFFER_SIZE];

	settings.toString();
		
	if(argc == 2) 
	{
		strcpy(settings.uri, argv[1]); 
	}
	char* path = FileHelper.getPathFromUri(settings.uri);
	char* const hostName = FileHelper.getHostNameFromUri(settings.uri);


	memset(&content[0], 0, BUFFER_SIZE);
	httpHelper.getContentByUri(hostName, settings.uri, content);
	string str(content);
	createDir.createDirByPath(path);
	int start = 0;
	FileHelper.writeFile(path, htmlParser.splitIntoStrings(htmlParser.hrefFormat(htmlParser.getTag(str, "title", start) + string("\n\n") + htmlParser.getAllTags(str, "p")), settings.lineLenght));
	cout << "Ok" << endl;

	delete(content);
	return 0;	
}

