#define WIN32_LEAN_AND_MEAN
#define MAXBUF  2048

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

namespace httpClient
{


	string to_utf8(const wchar_t* buffer, int len)
	{
		int nChars = ::WideCharToMultiByte(
			CP_UTF8,
			0,
			buffer,
			len,
			NULL,
			0,
			NULL,
			NULL);
		if (nChars == 0) return "";

		string newbuffer;
		newbuffer.resize(nChars) ;
		::WideCharToMultiByte(
			CP_UTF8,
			0,
			buffer,
			len,
			const_cast< char* >(newbuffer.c_str()),
			nChars,
			NULL,
			NULL); 

		return newbuffer;
	}

	std::string to_utf8(const std::wstring& str)
	{
		return to_utf8(str.c_str(), (int)str.size());
	}

	//
	// 
	//
	int getContentByUri(char* const host_name, char* const uri, char* content)
	{
		WORD wVersionRequested;
		WSADATA wsaData;
		int error, bytesRead;
		char buffer[MAXBUF];
		struct hostent * remoteHost;

		/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
		wVersionRequested = MAKEWORD(2, 2);

		error = WSAStartup(wVersionRequested, &wsaData);
		if (error != 0) {
			/* Tell the user that we could not find a usable */
			/* Winsock DLL.                                  */
			cout << "WSAStartup failed with error: " << error << endl;
			return 1;
		}

		/* Confirm that the WinSock DLL supports 2.2.*/
		/* Note that if the DLL supports versions greater    */
		/* than 2.2 in addition to 2.2, it will still return */
		/* 2.2 in wVersion since that is the version we      */
		/* requested.                                        */

		if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
			cout << "Could not find a usable version of Winsock.dll" << endl;
			WSACleanup();
			return 1;
		}

		int s;
		s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

		remoteHost = gethostbyname(host_name);

		SOCKADDR_IN anAddr;
		anAddr.sin_family = AF_INET;
		anAddr.sin_port = htons(80);
		anAddr.sin_addr.S_un.S_addr = *(u_long *) remoteHost->h_addr_list[0];

		if(connect(s, (struct sockaddr *)&anAddr, sizeof(struct sockaddr)))
		{
			printf("Error in connection\n");
			return 1;
		}

		sprintf(buffer, "GET %s HTTP/1.0\r\n\r\n", uri);
		send(s, buffer, strlen(buffer), 0);
		size_t offset = 0;

		bytesRead = 0;
		do
		{
			bytesRead = recv(s, content + offset, MAXBUF, 0);
			if ( bytesRead > 0 )
			{
				offset += bytesRead;
			}
		}
		while ( bytesRead > 0 );

		closesocket(s);
		WSACleanup();
	}
}
