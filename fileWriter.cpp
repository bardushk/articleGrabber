#include <string>
#include <fstream>
#include <iostream>

using namespace std;

namespace fileWriter
{
	// Saves content to the text file, using path
	//
	//
	int writeFile(char* path, char * content)
	{
		ofstream file;
		file.open ("snob.txt");
		string str(content);
		file << str;
		file.close();
		return 0;
	}
}
