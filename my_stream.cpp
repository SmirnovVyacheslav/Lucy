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

Console_Stream::Console_Stream()
{
	wcin.imbue(locale(".866"));
	wcout.imbue(locale(".866"));

	thread input(input_thread, ref(input_msg));

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