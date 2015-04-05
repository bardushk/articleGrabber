#pragma once
#ifndef HTMLPARSER_H
#include <string>

using namespace std;

class HtmlParser
{
public:
	string getTag(string html, string tag, int & start);
	string getAllTags(string html, string tag);
	string hrefFormat(string html);
	string splitIntoStrings(string text, int stringLength);
};

#endif