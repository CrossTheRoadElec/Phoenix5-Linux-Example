/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <condition_variable>

namespace ctre {
namespace phoenix {
namespace threading {
	/**
	 * Reference-counted Manual Event. Each Signal()
	 * increments a reference count, and each Clear()
	 * decrements the count. The event is signaled while
	 * the count is greater than 0.
	 *
	 * This is useful for a situation where multiple threads
	 * signal an operation to run, and the operation should not
	 * stop until all threads clear the event.
	 */
	class CTREXPORT RcManualEvent {
	private:
		size_t _signal = 0;
		size_t _refCnt = 0;
		mutable std::mutex _m;
		mutable std::condition_variable _cv;

	public:
		/**
		 * Wait for event to be signaled, or for timeout
		 * \param timeoutMs timeout of the wait; -1 is indefinite, 0 is a fast check
		 * \returns true if event is signaled, false if timed out.
		 */
		bool WaitForSignal(int timeoutMs) const;

		/**
		 * Signal the event. Any threads waiting on WaitForSignal() will return true.
		 * The caller must clear the signal once it is done, otherwise the reference
		 * count may never return to 0.
		 */
		void Signal();
		/**
		 * Clear the event signal without signaling other threads.
		 */
		void Clear();
		/**
		 * Reset the event signal to 0 and force any threads waiting on WaitForSignal() to time out.
		 */
		void Reset();
	};
}
}
}
