#pragma once

#include "lucy.h"
#include "my_stream.h"

int main(void)
{
	Lucy(new Console_Stream()).talk();

	return 0;
}