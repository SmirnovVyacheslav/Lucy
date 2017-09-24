#pragma once

#include <memory>
#include <random>

#include "my_stream.h"
#include "image.h"
#include "person.h"

using namespace std;

class Lucy: public Person
{
	using Action = void (Lucy::*)();

	Action *acts;

	unique_ptr<Stream> stream;

	unique_ptr<Person> opponent;

	string last_msg;

	

	/*bool continue_conv;

	Random_Wish* wish;

	int base_wish;*/

public:
	Lucy(Stream* _stream) : stream(_stream)
	{
		/*::Person("Lucy", "19", "woman");
		opponent.reset(new Person());
		
		focus.reset(new Image("Приветствие"));

		continue_conv = true;

		action = new my_fnc[3];
		action[0] = &Lucy::ask;
		action[1] = &Lucy::say;
		action[2] = &Lucy::wait;

		wish = new Random_Wish();

		base_wish = 30;*/
	};

	void talk();

	bool think();
};