#pragma once

#include <thread>
#include <mutex>

#include <chrono>
#include <future>

#include <queue>

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
	//string input;

	queue<string> input_msg;

	//void input_thread(queue<string>& str);

public:
	Console_Stream();

	string in();

	void out(string str);
};