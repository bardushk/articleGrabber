#pragma once
#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H

class Settings
{

public:
	Settings();
	~Settings();
	char* uri;
	int lineLenght;
	void toString();
};

#endif