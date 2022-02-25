#pragma once
#include "ctre/phoenix/export.h"
#include <stdint.h>
#include <sstream>
#include <deque>
#include <vector>

namespace ctre {
	namespace phoenix {
		namespace string_util {
			CTREXPORT std::deque<std::string> string_split(const std::string& input, char delimiter);
			CTREXPORT std::string toLower(const std::string& input);
			CTREXPORT int strcmp_nocase(char const* a, char const* b);
			CTREXPORT uint32_t safe_memcpy_(uint8_t* dest, const uint8_t* src, uint32_t numBytesToCopy, uint32_t capacity);
			CTREXPORT uint32_t safe_memcpy_(uint8_t* dest, const uint8_t* src, int32_t numBytesToCopy, int32_t capacity);
			CTREXPORT uint32_t safe_copyDoubles(double* dest, const double* src, int32_t numDoubles, int32_t capacityDoubles);
			CTREXPORT uint32_t safe_copyDoubles(double* dest, const std::vector<double>& src, int32_t capacityDoubles);
			CTREXPORT uint32_t safe_strlen(const char* s, int32_t maxsize);
			CTREXPORT void safe_strcopy(std::string& dest, const char* src);
			CTREXPORT char *strtok_next(char **str_ptr, char const *delimiters);
		} // namespace string_util
	} // namespace phoenix
} // namespace ctre
