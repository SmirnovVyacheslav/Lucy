#pragma once

#include <string>
#include <memory>

#include "image.h"

using namespace std;

class Recent_Images
{
public:
	int memory_sz;

	vector<shared_ptr<Image>> recent_img;

	Recent_Images() : memory_sz(20)
	{
		recent_img = vector<shared_ptr<Image>>(memory_sz);
	};

	void add(Image *img)
	{
		if (recent_img.size() == memory_sz)
			recent_img.erase(recent_img.cbegin());

		recent_img.push_back(shared_ptr<Image>(img));
	}
};

class Person
{
public:
	map<Image *, string> my_data;

	int my_tune, my_question, my_statement, my_wait;

	Image *focus;

	unique_ptr<Recent_Images> my_recent_images;

	Person() :
		my_tune(0), my_question(0), my_statement(0), my_wait(0)
	{
		focus = nullptr;
		my_recent_images.reset(new Recent_Images);
	};

	Person(string name, string age, string sex) : 
		my_tune(0), my_question(0), my_statement(0), my_wait(0)
	{
		focus = nullptr;
		my_recent_images.reset(new Recent_Images);
	};

	int wish_to_ask()
	{
		return - my_question + my_statement + my_wait;
	}

	int wish_to_say()
	{
		return my_question + my_statement + my_wait;
	}

	int wish_to_wait()
	{
		return - my_question - my_statement - my_wait;
	}
	
};