/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include <mutex>

namespace ctre {
namespace phoenix {
namespace threading {

	/**
	 * \brief An extension of mutex that defines an empty move
	 * constructor and assignment operator.
	 *
	 * \details This allows classes using a #MovableMutex to have move semantics.
	 */
	template <class MutexType>
	class MovableMutex : public MutexType {
	public:
		MovableMutex() = default;
		/* allow move semantics */
		MovableMutex(MovableMutex &&) : MovableMutex{} {}
		MovableMutex &operator=(MovableMutex &&) { return *this; }
	};

}
}
}
