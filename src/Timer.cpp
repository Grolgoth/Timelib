#include "Timer.h"
#include "defines.h"
#ifdef OS_Windows
#include "windowstimer.h"
#elif(defined(OS_Linux))
#include "LinuxTimer.h"
#endif
#include <iostream>

std::vector<Timer*> TimerManager::timers;
std::vector<Timer*> TimerManager::paused;

TimerManager::TimerManager()
{
	#ifdef OS_Windows
		timer = new WindowsTimer();
	#elif(defined(OS_Linux))
		timer = new LinuxTimer();
	#endif
	if (timer == nullptr)
	{
		std::cerr << "Error: could not create timer. Your OS is not supported by this library." << std::endl;
		std::cerr << "Currently only Linux and Windows_x86 are supported." << std::endl;
	}
	timers.push_back(timer);
}

TimerManager::~TimerManager()
{
	for (unsigned int i = 0; i < timers.size(); i++)
		if (timers[i] == timer)
			timers.erase(timers.begin() + i);
	delete timer;
}

void TimerManager::pauseAll()
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
}

Timer::~Timer()
{

}
