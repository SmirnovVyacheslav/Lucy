#pragma once

#include <memory>
#include <random>
#include <string>
#include <sstream>

#include <unordered_map>

#include <fstream>

//#include <windows.h>

#include "my_stream.h"
#include "image.h"
//#include "person.h"

using namespace std;

class Lucy//: public Person
{
	unique_ptr<Stream> stream;

	bool result = true;

	wstring in, out;

	vector<wstring> in_msg, out_mgs;

	unordered_map<wstring, Image*> memory;

	vector<wstring> conv;

	wostringstream oss;
	wistringstream iss;

	vector<Image*> cache;

	Image* find(wstring name)
	{
		if (!memory[name])
		{
			memory[name] = new Image(name);
		}

		return memory[name];
	};

	void update_ref()
	{
		if (cache.size() > 1)
		{
			for (int i = 0; i < cache.size() - 1; ++i)
			{
				cache[i]->add_ref(cache[i + 1]);
			}
		}
	};

	void read()
	{
		Image *image;
		wstring word;
		iss.clear();
		iss.str(stream->in());

		in_msg.clear();
		cache.clear();

		while (iss >> word)
		{
			image = find(word);
			image->update();

			cache.push_back(image);

			in_msg.push_back(word);
		}

		update_ref();
	};

	void write()
	{
		if (oss.str() != L"")
		{
			stream->out(oss.str());
		}
		
		oss.clear();
	};

	void load();

	void save();

public:
	Lucy(Stream* _stream) : stream(_stream)
	{
		load();
	};

	~Lucy()
	{
		save();
	}

	void talk();

	bool think();
};