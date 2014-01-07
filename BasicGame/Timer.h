#ifndef __BasicGame__Timer__
#define __BasicGame__Timer__

#include <sstream>
#include <stdint.h>

using namespace std;

namespace basicgame
{
	class Timer
	{
	private:
		int startTicks;
		int pauseTicks;

		bool paused;
		bool started;

	public:
		Timer();
		void start();
		void stop();
		void pause();
		void resume();
		int getTicks();

		bool isStarted();
		bool isPaused();
		~Timer();
	};

}
#endif