#pragma once
#ifndef HTMLPARSER_H
#include <string>

using namespace std;

namespace htmlParser
{
	string getTag(string html, string tag, int & start);
	string getAllTags(string html, string tag);
	string hrefFormat(string html);
	string splitIntoStrings(string text, int stringLength = 80);
}
#endif