#include "lucy.h"
#include "my_stream.h"

#include <csignal>
#include <cstdlib>

Lucy* lucy = nullptr;

void atexit_handler()
{
	if (lucy)
		lucy->~Lucy();
	
	std::abort();
}

void signal_handler(int signal)
{
	if (signal == SIGABRT && lucy)
	{
			lucy->~Lucy();
	}
	else
	{
		std::wcout << "Unexpected signal: " << signal << std::endl;
	}
	std::_Exit(EXIT_FAILURE);
}

#ifdef _WIN32
BOOL CtrlHandler(DWORD fdwCtrlType)
{
	if (lucy)
		lucy->~Lucy();
	return true;
}
#endif

int main(void)
{
	//Lucy(new Console_Stream()).talk();

	if (std::atexit(atexit_handler) != 0)
	{
		std::wcerr << "Failed to set exit handler" << std::endl;
		return EXIT_FAILURE;
	}

	std::set_terminate(atexit_handler);

	std::at_quick_exit(atexit_handler);

	if (std::signal(SIGABRT, signal_handler) == SIG_ERR)
	{
		std::wcerr << "Failed to set signal handler" << std::endl;
		return EXIT_FAILURE;
	}

#ifdef _WIN32
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		std::wcerr << "Failed to set exit handler" << std::endl;
		return EXIT_FAILURE;
	}
#endif

	lucy = new Lucy(new Console_Stream());

	lucy->talk();

	return 0;
}
