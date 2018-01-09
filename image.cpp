#include "image.h"

wostream& operator << (wostream &stream, Image &image)
{
	stream << ' ' << image.name() << ' ' << image.fou << ' ';

	for (auto ref : image.ref)
	{
		stream << ref.first << ' ' << ref.second << ' ';
	}

	stream << '|';

	return stream;
}

wistream& operator >> (wistream &stream, Image &image)
{
	wstring ref_name;
	int ref_fou;

	stream >> image._name >> image.fou;

	stream >> ref_name;

	while (ref_name != L"|")
	{
		stream >> ref_fou;
		image.ref[ref_name] = ref_fou;
		stream >> ref_name;
	}

	return stream;
}