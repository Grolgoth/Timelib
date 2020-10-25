#include "Timer.h"
#include "defines.h"
#include "windowstimer.h"
#include "LinuxTimer.h"
#include <iostream>

std::vector<Timer*> Timer::timers;
std::vector<Timer*> Timer::paused;

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

void Timer::pauseAll()
{
	if (paused.size() == 0)
	{
		for (Timer* timer : timers)
		{
			if (!timer->stopped)
			{
				paused.push_back(timer);
				timer->stop();
			}
		}
	}
	else
	{
		while (paused.size() > 0)
		{
			paused.back()->Continue();
			paused.pop_back();
		}
	}
}

Timer::Timer()
{
	stopped = true;
	timers.push_back(this);
}

Timer::~Timer()
{
	for (unsigned int i = 0; i < timers.size(); i++)
		if (timers[i] == this)
			timers.erase(timers.begin() + i);
}
