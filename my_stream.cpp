#include "my_stream.h"

string Console_Stream::in()
{
	getline(cin, input);
	return input;
}

void Console_Stream::out(string str)
{
	cout << str << endl;
}