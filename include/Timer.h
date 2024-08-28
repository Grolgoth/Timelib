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
	friend class TimerManager;
	public:

		Timer();
		virtual ~Timer();
		virtual void start() = 0;
		virtual int get_elt() = 0;
		virtual void stop() = 0;
		virtual void Continue() = 0;
	protected:
		bool stopped;
};

class TimerManager
{
	public:
		static void pauseAll();

		TimerManager();
		~TimerManager();
		void start() {timer->start();}
		int get_elt() {return timer->get_elt();}
		void stop() {timer->stop();}
		void Continue() {timer->Continue();};
		bool getStopped() {return timer->stopped;}
	private:
		Timer* timer = nullptr;

		static std::vector<Timer*> timers;
		static std::vector<Timer*> paused;
};

#endif // TIMER_H
