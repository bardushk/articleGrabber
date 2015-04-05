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
		string result = html.substr(start + tagOpen.length(), end - start - tagOpen.length());
		start = end;
		return result;
	}

	// Get content from all tags 
	//
	//
	string getAllTags(string html, string tag)
	{
		string result("");
		int start = 0;
		for(;;)
		{
			result = result + getTag(html, tag, start) + string("\n\n");
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
			result += "[" + html.substr(linkStart, linkEnd - linkStart + 1) + "]";
			currentPosition = messageEnd + string("</a>").length();
		}	
		return result;
	}

	// Split string by N chars 
	// 
	//
	string splitIntoStrings(string text, int stringLength = 80)
	{
		string result("");
				setlocale(LC_ALL, "Russian");
		int spacePosition, stringStartPosition = 0, simbolCounter = 0;
		for(int currentPosition = 0; currentPosition < text.length(); currentPosition++)
		{
			if(text[currentPosition] == ' ')
			{
				spacePosition = currentPosition;
			}

			if(text[currentPosition] == '\n')
			{
				simbolCounter = 0;
				result += text.substr(stringStartPosition, currentPosition - stringStartPosition + 1);
				stringStartPosition = currentPosition + 1;
				continue;
			}
			if(text[currentPosition] < 0)
			{
				currentPosition++;		
			}
			simbolCounter++;
			
			if(simbolCounter >= stringLength)
			{
				result += text.substr(stringStartPosition, spacePosition + 1  - stringStartPosition) + "\n";
				currentPosition = spacePosition;
				stringStartPosition = currentPosition + 1;
				simbolCounter = 0;
			}
		}
		result += text.substr(stringStartPosition);
		return result;
	}
}