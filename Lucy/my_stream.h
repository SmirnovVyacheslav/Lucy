#pragma once

#include <thread>
#include <mutex>

#include <queue>

#include <string>
#include <iostream>

using namespace std;

#ifdef _WIN32
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#endif

class Stream
{
public:

	virtual wstring in() = 0;

	virtual void out(wstring str) = 0;
};

class Console_Stream : public Stream
{
	queue<wstring> input_msg;

	thread input;

public:
	Console_Stream();

	~Console_Stream();

	wstring in();

	void out(wstring str);
};