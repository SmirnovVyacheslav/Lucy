#pragma once

#include <memory>
#include <vector>
#include <map>

using namespace std;

class Image
{
	string name;

	int tone;

	int lru;

	vector<Image*> attr;

	vector<pair<Image*, int>> ref;

public:
	
	Image(string _name);
};