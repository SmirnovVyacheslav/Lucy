#include "lucy.h"

void Lucy::talk()
{
	while (think());
}

bool Lucy::think()
{
	read();//listern

	if (in_msg.size() > 0 && in_msg[0] == L"Пока")
	{
		result = false;
	}

	write();//say

	return result;
}

void Lucy::load()
{
	Image *image;

	wifstream file("memory.txt", ios::in);
	file.imbue(locale(".1251"));

	while (!file.eof())
	{
		image = new Image();
		file >> *image;
		memory[image->name()] = image;
	}
}

void Lucy::save()
{
	wofstream file("memory.txt", ios::out);
	file.imbue(locale(".1251"));

	for (auto image : memory)
	{
		file << *image.second;
	}
}