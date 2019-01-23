#include "windowstimer.h"
#include "defines.h"

#ifdef OS_Windows

#include "windows.h"

WindowsTimer::WindowsTimer()
{
	begin = GetTickCount();
}

WindowsTimer::~WindowsTimer()
{
	//dtor
}

void WindowsTimer::start()
{
	stopped = false;
	begin = GetTickCount();
}

void WindowsTimer::stop()
{
	stopped = true;
	end = GetTickCount();
}

int WindowsTimer::get_elt()
{
	if(stopped)
		return end - begin;
	return GetTickCount() - begin;
}

#endif
