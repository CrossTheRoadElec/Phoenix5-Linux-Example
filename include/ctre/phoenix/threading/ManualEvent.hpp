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
	 * Manual Event object, useful for signaling
	 * other threads about an event.
	 */
	class CTREXPORT ManualEvent {
	private:
		bool _signal;
		mutable size_t _waitCnt = 0;
		mutable std::mutex _m;
		mutable std::condition_variable _cv;

	public:
		/**
		 * \param initialSignal object defaults to Signaled or Not Signaled (default is not signaled).
		 */
		ManualEvent(bool initialSignal = false);

		/**
		 * Wait for event to be signaled, or for timeout
		 * \returns true if event is signaled, false if timed out.
		 */
		bool WaitForSignal(int timeoutMs) const;

		/**
		 * Signal the event. Any threads waiting on WaitForSignal() will return true.
		 */
		void Signal();
		/**
		 * Clear the event. Any threads waiting on WaitForSignal() will time out.
		 */
		void Clear();
		/**
		 * Reset the event signal without signaling other threads.
		 */
		void Reset();
	};
}
}
}
