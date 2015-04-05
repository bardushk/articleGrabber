#pragma once
#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

using namespace std;

class HttpClient
{
	string _to_utf8(const wchar_t* buffer, int len);
	string _to_utf8(const std::wstring& str);
public:
	int getContentByUri(char* const host_name, char* const uri, char* content);
};

#endif