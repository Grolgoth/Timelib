#ifndef TIMER_H
#define TIMER_H
#include <vector>

struct TimePoint
{
	int start;
	int time;
};

class Timer
{
	public:
		static Timer* getTimer();
		static void pauseAll();

		Timer();
		virtual ~Timer();
		virtual void start() = 0;
		virtual int get_elt() = 0;
		virtual void stop() = 0;
		virtual void Continue() = 0;
		inline bool getStopped() {return stopped;}
	protected:
		bool stopped;
		static std::vector<Timer*> timers;
		static std::vector<Timer*> paused;
};

#endif // TIMER_H
