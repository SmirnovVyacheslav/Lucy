#pragma once

#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

#include <iostream>
#include <string>

using namespace std;

class Image;

ostream& operator << (ostream &stream, Image &image);

istream& operator >> (istream &stream, Image &image);

class Image
{
	string _name;

	int lru = 0;//last recently used

	int fou;//frequency of use

	//vector<Image*> attr;

	unordered_map<string, int> ref;

	//vector<pair<string, int>> ref;//reference with weight

public:
	
	friend ostream& operator << (ostream &stream, Image &image);
	friend istream& operator >> (istream &stream, Image &image);

	Image(string name) : _name(name) {};

	Image() {};

	void update()
	{
		lru++;
		fou++;
	};

	void add_ref(Image *image)
	{
		if (!ref[image->name()])
		{
			ref[image->name()] = 1;
		}
		else
		{
			ref[image->name()]++;
		}
	}

	string name()
	{
		return _name;
	};
};