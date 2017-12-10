#include "my_stream.h"

mutex inp_mtx;

void input_thread(queue<string>& input_msg)
{
	string str;

	while (true)
	{
		getline(cin, str);

		inp_mtx.lock();
		input_msg.push(str);
		inp_mtx.unlock();
	}
}

//void Console_Stream::input_thread(queue<string>& input_msg)
//{
//	string str;
//
//	while (true)
//	{
//		getline(cin, str);
//
//		inp_mtx.lock();
//		input_msg.push(str);
//		inp_mtx.unlock();
//	}
//}

Console_Stream::Console_Stream()
{
	thread input(input_thread, ref(input_msg));

	input.detach();
};

string Console_Stream::in()
{
	string res = "";

	if (inp_mtx.try_lock())
	{
		if (!input_msg.empty())
		{
			res = input_msg.front();
			input_msg.pop();
		}
		
		inp_mtx.unlock();
	}
	
	return res;
}

void Console_Stream::out(string str)
{
	cout << str << endl;
}