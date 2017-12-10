#pragma once

#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

#include <iostream>
#include <string>

using namespace std;

class Image
{
	string name;

	int lru = 0;//last recently used

	int fou;//frequency of use

	//vector<Image*> attr;

	unordered_map<string, int> ref;

	//vector<pair<string, int>> ref;//reference with weight

public:
	
	friend ostream& operator << (ostream &stream, Image &image);
	friend istream& operator >> (istream &stream, Image &image);

	Image(string _name) : name(_name) {};

	Image() {};

	void update()
	{
		lru++;
		fou++;
	};

	void add_ref(Image *image)
	{
		if (!ref[image->name])
		{
			ref[image->name] = 1;
		}
		else
		{
			ref[image->name]++;
		}
	}

	string name()
	{
		return name;
	};
};

ostream& operator << (ostream &stream, Image &image)
{
	stream << ' ' << image.name << ' ' << image.fou << ' ';

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
	
	stream >> image.name >> image.fou;

	stream >> ref_name;

	while (ref_name != "|")
	{
		stream >> ref_fou;
		image.ref[ref_name] = ref_fou;
	}

	return stream;
}