/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#ifdef __FRC_ROBORIO__
#include <unistd.h>
#else
#include <thread>
#endif

#include <chrono>

namespace ctre {
namespace phoenix {
namespace platform {

	/**
	 * \param timeUs	How long to yield current thread in microseconds (us).
	 *					If platform cannot honor us resolution, round up to nearest
	 *					value that platform can honor.
	 */
	static inline void SleepUs(int timeUs)
	{
#ifdef __FRC_ROBORIO__
		usleep(timeUs);
#else
		std::this_thread::sleep_for(std::chrono::microseconds{timeUs});
#endif
	}

	/** The raw current time source. */
	std::chrono::steady_clock::duration CurrentTimeRaw();

	/**
	 * Returns the current time of the system, converted to the given duration.
	 * The default duration is in microseconds.
	 *
	 * This time source is typically continuous and monotonic. However, it may
	 * be overridden in simulation to use a non-monotonic, non-continuous source.
	 */
	template <typename DURATION = std::chrono::microseconds>
	static inline auto CurrentTime()
	{
		using namespace std::chrono;
		return duration_cast<DURATION>(CurrentTimeRaw()).count();
	}

	/**
	 * Returns the monotonic time of the system, converted to the given duration.
	 * The default duration is in microseconds.
	 *
	 * This time source is guaranteed to be continuous and monotonic.
	 */
	template <typename DURATION = std::chrono::microseconds>
	static inline auto SystemTime()
	{
		using namespace std::chrono;
		return duration_cast<DURATION>(steady_clock::now().time_since_epoch()).count();
	}

} // namespace platform
} // namespace phoenix
} // namespace ctre
