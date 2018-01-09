#pragma once

#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

#include <iostream>
#include <string>

using namespace std;

class Image;

wostream& operator << (wostream &stream, Image &image);

wistream& operator >> (wistream &stream, Image &image);

class Image
{
	wstring _name;

	int lru = 0;//last recently used

	int fou;//frequency of use

	//vector<Image*> attr;

	unordered_map<wstring, int> ref;

	//vector<pair<string, int>> ref;//reference with weight

public:
	
	friend wostream& operator << (wostream &stream, Image &image);
	friend wistream& operator >> (wistream &stream, Image &image);

	Image(wstring name) : _name(name) {};

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

	wstring name()
	{
		return _name;
	};
};