#pragma once

#include <stdint.h>

namespace ctre {
namespace phoenix {
namespace platform {

	void ReportError(int isError, int32_t errorCode, int isLVCode, const char *details,
					const char *location, const char *callStack);

} // namespace platform
} // namespace phoenix
} // namespace ctre