#ifndef WINDOWSTIMER_H
#define WINDOWSTIMER_H
#include "Timer.h"

typedef unsigned long DWORD;

class WindowsTimer : public Timer
{
	friend class Timer;
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

#endif // WINDOWSTIMER_H
