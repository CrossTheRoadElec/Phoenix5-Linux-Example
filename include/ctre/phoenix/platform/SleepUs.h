#pragma once

#include <chrono>
#include <thread>

#ifdef __FRC_ROBORIO__
#include <unistd.h>
#endif

namespace ctre {
namespace phoenix {
namespace platform {

	/**
	 * @param timeUs	How long to yield current thread in microseconds (us).
	 *					If platform cannot honor us resolution, round to nearest
	 *					value that platform can honor.
	 */
	static inline void SleepUs(int timeUs)
	{
#ifdef __FRC_ROBORIO__
		usleep(timeUs);
#else
		std::this_thread::sleep_for(std::chrono::microseconds(timeUs));
#endif
	}

} // namespace platform
} // namespace phoenix
} // namespace ctre