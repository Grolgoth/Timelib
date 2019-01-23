#include "LinuxTimer.h"
#include "defines.h"

#ifdef OS_Linux

LinuxTimer::LinuxTimer()
{
	begin = getTime(); // to make sure no error occurs if get_elt is called while forgetting to start the timer
}

LinuxTimer::~LinuxTimer()
{
	//dtor
}

void LinuxTimer::start()
{
	stopped = false;
	begin = getTime();
}

void LinuxTimer::stop()
{
	stopped = true;
	end = getTime();
}

int LinuxTimer::get_elt()
{
	if (stopped)
	{
		double difference = (end.timesecs - begin.timesecs) * 1000;
		difference += (end.timenanosecs - begin.timenanosecs) / 1000000;
		return (int)difference;
	}
	timestruct current = getTime();
	double difference = (current.timesecs - begin.timesecs) * 1000;
	difference += (current.timenanosecs - begin.timenanosecs) / 1000000;
	return (int)difference;
}

timestruct LinuxTimer::getTime()
{
	struct timespec current;
	timestruct result;
	if(clock_gettime(CLOCK_REALTIME, &current) == -1)
	{
		std::cerr << "Error in linux native method clock_gettime." << std::endl;
		return;
	}
	result.timesecs = current.tv_sec;
	result.nanosecs = current.tv_nsec;
	return result;
}

#endif
