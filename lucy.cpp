#include "lucy.h"

void Lucy::talk()
{
	while (think());
}

bool Lucy::think()
{
	read();//listern

	

	write();//say

	return result;
}

void Lucy::load()
{
	Image *image;

	ifstream file("memory.txt", ios::in);

	while (file)
	{
		image = new Image();
		file >> *image;
		memory[image->name()] = image;
	}
}

void Lucy::save()
{
	ofstream file("memory.txt", ios::out);

	for (auto image : memory)
	{
		file << *image.second;
	}
}