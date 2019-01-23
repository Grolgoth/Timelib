#include "Timer.h"
#include "defines.h"
#include "windowstimer.h"
#include "LinuxTimer.h"
#include <iostream>

Timer* Timer::getTimer()
{
	#ifdef OS_Windows
		return new WindowsTimer();
	#elif(defined(OS_Linux))
		return new LinuxTimer();
	#endif
	std::cerr << "Error: could not create timer. Your OS is not supported by this library." << std::endl;
	std::cerr << "Currently only Linux and Windows_x86 are supported." << std::endl;
	return nullptr;
}

Timer::Timer()
{
	stopped = true;
}

Timer::~Timer()
{

}
