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
		mutable size_t _waitCnt = 0;
		mutable std::mutex _m;
		mutable std::condition_variable _cv;

	public:
		/**
		 * Wait for event to be signaled, or for timeout
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
		 * Clear the event. Any threads waiting on WaitForSignal() will time out
		 * if this is the last thread to clear the signal.
		 */
		void Clear();
		/**
		 * Reset the event signal to 0 without signaling other threads.
		 */
		void Reset();
	};
}
}
}
