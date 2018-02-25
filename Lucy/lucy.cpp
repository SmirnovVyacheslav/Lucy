#include "lucy.h"

void Lucy::talk()
{
	while (result)
	{
		read();//listern

		

		write();//say
	};
}

void Lucy::load()
{
	Image *image;

	wifstream file("memory.txt", ios::in);
	file.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));

	if (file.is_open())
	{
		while (!file.eof())
		{
			image = new Image();
			file >> *image;
			memory[image->name()] = image;
		}
	}

	file.close();
}

void Lucy::save()
{
	wofstream file;
	file.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));

	file.open("memory.txt", ios::out);

	for (auto image : memory)
	{
		file << *image.second;
	}

	file.close();
}
