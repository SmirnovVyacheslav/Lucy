#pragma once

#include <memory>
#include <random>

#include <string>
#include <sstream>
#include <fstream>

#include <unordered_map>


#include "my_stream.h"
#include "image.h"

using namespace std;

class Lucy
{
	struct Sentence
	{
		int start, end;
		Image *subject;

		Sentence(int _start = 0, int _end = 0, Image *_subject = nullptr):
			start(_start), end(_end), subject(_subject) {}
	};

	vector<Sentence*> conversation;

	vector<Image*> images;

	vector<Image*> image_sense;

	unique_ptr<Stream> stream;

	bool result = true;

	unordered_map<wstring, Image*> memory;

	wostringstream oss;
	wistringstream iss;

	void sense(Sentence* sentence)
	{
		sentence->subject = nullptr;
	}

	void sense(Image* image)
	{
		image_sense.clear();
	}

	Image* find_image(wstring name)
	{
		if (!memory[name])
		{
			memory[name] = new Image(name);
		}

		return memory[name];
	};

	void step_links(Sentence *sentence)
	{
		for (int i = sentence->start; i <= sentence->end; ++i)
		{
			for (int j = sentence->start; j <= sentence->end; ++j)
			{
				if (i == j)
				{
					continue;
				}
				else if (j - i == 1)
				{
					images[i]->add_ref(images[j]->name(), 3);
				}
				else if (j - i == -1)
				{
					images[i]->add_ref(images[j]->name(), 2);
				}
				else
				{
					images[i]->add_ref(images[j]->name(), 1);
				}
			}
		}
	};

	void read()
	{
		wstring word;

		iss.clear();
		if (stream)
			iss.str(stream->in());
		else
			return;
		
		if (!(iss >> word))
			return;

		images.push_back(find_image(word));
		images.back()->step_using();

		Sentence *sentence = new Sentence(images.size() - 1);

		while (iss >> word)
		{
			images.push_back(find_image(word));
			images.back()->step_using();
		}

		sentence->end = images.size() - 1;

		step_links(sentence);

		sense(sentence);

		conversation.push_back(sentence);
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
		stream.release();
		save();
	}

	void talk();
};