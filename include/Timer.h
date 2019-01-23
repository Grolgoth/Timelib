#ifndef TIMER_H
#define TIMER_H

class Timer
{
	public:
		static Timer* getTimer();

		Timer();
		virtual ~Timer();
		virtual void start() = 0;
		virtual int get_elt() = 0;
		virtual void stop() = 0;
	protected:
		bool stopped;
};

#endif // TIMER_H