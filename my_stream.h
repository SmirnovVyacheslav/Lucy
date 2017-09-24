#pragma once

#include <string>
#include <iostream>

using namespace std;

class Stream
{
public:
	//Stream() {};

	virtual string in() = 0;

	virtual void out(string str) = 0;
};

class Console_Stream : public Stream
{
	string input;

public:
	//Console_Stream() {};

	string in();

	void out(string str);
};