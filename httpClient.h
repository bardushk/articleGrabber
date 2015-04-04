#pragma once
#ifndef HTTPCLIENT_H

namespace httpClient
{
	int getContentByUri(char* const host_name, char* const uri, char* content);
}

#endif