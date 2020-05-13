#pragma once
#include <stdint.h>
#include <sstream>
#include <deque>
#include <vector>

namespace ctre {
	namespace phoenix {
		namespace string_util {
			std::deque<std::string> string_split(const std::string& input, char delimiter);
			std::string toLower(const std::string& input);
			int strcmp_nocase(char const* a, char const* b);
			uint32_t safe_memcpy_(uint8_t* dest, const uint8_t* src, uint32_t numBytesToCopy, uint32_t capacity);
			uint32_t safe_memcpy_(uint8_t* dest, const uint8_t* src, int32_t numBytesToCopy, int32_t capacity);
			uint32_t safe_copyDoubles(double* dest, const double* src, int32_t numDoubles, int32_t capacityDoubles);
			uint32_t safe_copyDoubles(double* dest, const std::vector<double>& src, int32_t capacityDoubles);
			uint32_t safe_strlen(const char* s, int32_t maxsize);
			void safe_strcopy(std::string& dest, const char* src);
		} // namespace string_util
	} // namespace phoenix
} // namespace ctre
