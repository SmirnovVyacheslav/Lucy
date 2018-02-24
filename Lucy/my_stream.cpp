#include "my_stream.h"

mutex inp_mtx;

void input_thread(queue<wstring>& input_msg)
{
	wstring str;

	while (true)
	{
		getline(wcin, str);

		inp_mtx.lock();
		input_msg.push(str);
		inp_mtx.unlock();
	}
}

Console_Stream::~Console_Stream()
{
	input.~thread();
}

Console_Stream::Console_Stream()
{
#ifdef _WIN32
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
#endif

	//thread input(input_thread, ref(input_msg));
	input = thread(input_thread, ref(input_msg));

	input.detach();
};

wstring Console_Stream::in()
{
	wstring res;

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

void Console_Stream::out(wstring str)
{
	wcout << str << endl;
}