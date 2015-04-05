#include <string>

using namespace std;

namespace htmlParser
{
	// Get tag content from html 
	//
	//
	string getTag(string html, string tag, int & start)
	{
		string const tagOpen = string("<") + tag + ">";
		string const tagClose = string("</") + tag + ">";
		start = html.find(tagOpen, start);
		if(start < 0) return "";
		int end = html.find(tagClose, start);
		if(end < 0) return "";
		string result = html.substr(start, end - start + tagClose.length());
		start = end;
		return result;
	}

	// Get content from all tags 
	//
	//
	string getAllTags(string html, string tag)
	{
		string result = string("");
		int start = 0;
		for(;;)
		{
			result = result + getTag(html, tag, start) + string("\n");
			if(start < 0) break;
		}
		return result;
	}

	// Format <a href = "linkAddress" sometags>text</a>
	// to message [linkAddress]
	//
	string hrefFormat(string html)
	{
		int currentPosition = 0, 
			tagStart, 
			linkStart, 
			linkEnd, 
			messageStart, 
			messageEnd;
		string result("");
		for(;;)
		{
			tagStart = html.find("<a", currentPosition);
			if(tagStart < 0)
			{
				result += html.substr(currentPosition);
				break;
			}
			result += html.substr(currentPosition, tagStart - currentPosition);
			linkStart = html.find("\"", html.find("href", tagStart));
			linkEnd = html.find("\"", linkStart + 1);
			messageStart = html.find(">", linkEnd) + 1;
			messageEnd = html.find("</a>", messageStart);
			result += html.substr(messageStart, messageEnd - messageStart);
			result += "[" + html.substr(linkStart, linkEnd - linkStart) + "]";
			currentPosition = messageEnd + string("</a>").length();
		}	
		return result;
	}
}