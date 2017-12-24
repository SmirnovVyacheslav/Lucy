#include "image.h"

ostream& operator << (ostream &stream, Image &image)
{
	stream << ' ' << image.name() << ' ' << image.fou << ' ';

	for (auto ref : image.ref)
	{
		stream << ref.first << ' ' << ref.second << ' ';
	}

	stream << '|';

	return stream;
}

istream& operator >> (istream &stream, Image &image)
{
	string ref_name;
	int ref_fou;

	stream >> image.name() >> image.fou;

	stream >> ref_name;

	while (ref_name != "|")
	{
		stream >> ref_fou;
		image.ref[ref_name] = ref_fou;
	}

	return stream;
}