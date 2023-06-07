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
	 * \brief An extension of mutex that defines empty copy and
	 * move constructors and assignment operators.
	 *
	 * \details This allows classes using a #CopyMoveMutex to have copy and move semantics.
	 */
	template <class MutexType>
	class CopyMoveMutex : public MutexType {
	public:
		CopyMoveMutex() = default;
		CopyMoveMutex(CopyMoveMutex const &) : CopyMoveMutex{} {}
		CopyMoveMutex(CopyMoveMutex &&) : CopyMoveMutex{} {}
		CopyMoveMutex &operator=(CopyMoveMutex const &) { return *this; }
		CopyMoveMutex &operator=(CopyMoveMutex &&) { return *this; }
	};

}
}
}
