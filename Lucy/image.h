#pragma once

#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

#include <iostream>
#include <string>

#include <locale>
#include <codecvt>
#include <string>

using namespace std;

class Image;

wostream& operator << (wostream &stream, Image &image);

wistream& operator >> (wistream &stream, Image &image);

class Image
{
	wstring _name;

	int lru = 0;//last recently used

	int fou = 0;//frequency of use

	const int max_lru = 1000;
	const int max_fou = 10000;
	const int max_ref = 1000;
	const int min_ref = 1;

	unordered_map<wstring, int> ref;

public:
	
	friend wostream& operator << (wostream &stream, Image &image);
	friend wistream& operator >> (wistream &stream, Image &image);

	Image(wstring name) : _name(name) {};

	Image() {};

	void step_using()
	{
		lru = (++lru) % max_lru;
		fou = (++fou) % max_fou;
	};

	void add_ref(wstring name, int value)
	{
		if (!ref[name])
		{
			ref[name] = value;
		}
		else
		{
			ref[name] = (ref[name] + value) % max_ref;
		}
	}

	wstring name()
	{
		return _name;
	};
};