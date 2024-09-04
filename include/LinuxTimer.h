#ifndef LINUXTIMER_H
#define LINUXTIMER_H
#include "defines.h"
#include "Timer.h"

#ifdef OS_Linux

struct timestruct
{
	int timesecs;
	int timenanosecs;
};

class LinuxTimer : public Timer
{
	friend class TimerManager;
	public:
		~LinuxTimer();
		void start();
		void stop();
		int get_elt();
		void Continue();

	private:
		LinuxTimer();
		timestruct begin;
		timestruct end;
		timestruct getTime();
};

#endif // OS_LINUX

#endif // LINUXTIMER_H
