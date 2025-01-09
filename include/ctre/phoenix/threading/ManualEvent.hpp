/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <array>
#include <condition_variable>

namespace ctre {
namespace phoenix {
namespace threading {
	/**
	 * Manual Event object, useful for signaling
	 * other threads about an event.
	 */
	class CTREXPORT ManualEvent {
	private:
		size_t _signal;
		mutable std::mutex _m;
		mutable std::condition_variable _cv;

	public:
		/**
		 * \param initialSignal whether this event defaults to signaled
		 */
		ManualEvent(bool initialSignal = false);

		/**
		 * Wait for event to be signaled, or for timeout.
		 * \param timeoutMs timeout of the wait; -1 is indefinite, 0 is a fast check
		 * \returns true if event is signaled, false if timed out
		 */
		bool WaitForSignal(int timeoutMs) const;

		/**
		 * Waits for all events to be signaled, or for timeout.
		 * \param timeoutMs timeout of the wait; -1 is indefinite, 0 is a fast check
		 * \param minTimeoutMs when timeoutMs > 0, minimum amount of time to wait for
		 *                     a signal; this can be used to ensure that a non-zero
		 *                     timeout is used for every signal; typically 0 or 1 ms
		 * \param events comma-separated list of event references to wait on
		 * \returns true if all events are signaled, false if timed out
		 */
		template < typename... Event, typename = std::enable_if_t<std::conjunction_v<std::is_same<Event, ManualEvent>...>> >
		static bool WaitForAllSignals(int timeoutMs, int minTimeoutMs, Event &... events)
		{
			std::array eventsArr{(&events)...};
			return WaitForAllSignals(timeoutMs, minTimeoutMs, eventsArr.data(), eventsArr.size());
		}

		/**
		 * Waits for all events to be signaled, or for timeout.
		 * \param timeoutMs timeout of the wait; -1 is indefinite, 0 is a fast check
		 * \param minTimeoutMs when timeoutMs > 0, minimum amount of time to wait for
		 *                     a signal; this can be used to ensure that a non-zero
		 *                     timeout is used for every signal; typically 0 or 1 ms
		 * \param events pointer to an array of event pointers to wait on
		 * \param eventCnt number of events in the array
		 * \returns true if all events are signaled, false if timed out
		 */
		static bool WaitForAllSignals(int timeoutMs, int minTimeoutMs, ManualEvent *const *events, size_t eventCnt);

		/**
		 * Signal the event. Any threads waiting on WaitForSignal() will return true.
		 */
		void Signal();
		/**
		 * Clear the event signal without signaling other threads.
		 */
		void Clear();
		/**
		 * Reset the event signal to false and force any threads waiting on WaitForSignal() to time out.
		 */
		void Reset();
	};
}
}
}
