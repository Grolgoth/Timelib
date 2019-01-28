#include "windowstimer.h"
#include "defines.h"

#ifdef OS_Windows

#include "windows.h"

WindowsTimer::WindowsTimer()
{
	stopped = false;
	timeBeginPeriod(1);
	begin = timeGetTime();
}

WindowsTimer::~WindowsTimer()
{
	timeEndPeriod(1);
	//dtor
}

void WindowsTimer::start()
{
	stopped = false;
	begin = timeGetTime();
}

void WindowsTimer::stop()
{
	stopped = true;
	end = timeGetTime();
}

int WindowsTimer::get_elt()
{
	if(stopped)
		return end - begin;
	return timeGetTime() - begin;
}

#endif
