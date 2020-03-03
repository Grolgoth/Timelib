#ifndef LINUXTIMER_H
#define LINUXTIMER_H
#include "Timer.h"

struct timestruct
{
	int timesecs;
	int timenanosecs;
};

class LinuxTimer : public Timer
{
	friend class Timer;
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

#endif // LINUXTIMER_H
