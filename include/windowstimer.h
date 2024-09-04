#ifndef WINDOWSTIMER_H
#define WINDOWSTIMER_H
#include "defines.h"
#include "Timer.h"

#ifdef OS_Windows
#include <windows.h>

class WindowsTimer : public Timer
{
	friend class TimerManager;
	public:
		~WindowsTimer();
		void start();
		int get_elt();
		void stop();
		void Continue();

	private:
		WindowsTimer();
		DWORD begin;
		DWORD end;
};

#endif // OS_WINDOWS

#endif // WINDOWSTIMER_H
