/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <sstream>
#include <stdint.h>
#include <string>
#include <vector>

namespace ctre {
namespace phoenix {
namespace string_util {

	/** Splits a string by the given delimiter */
	CTREXPORT std::vector<std::string> string_split(std::string const &input, char delimiter);
	/** Creates a new, lowercase version of the given string */
	CTREXPORT std::string toLower(std::string_view input);
	/** Converts the given string to lowercase in-place */
	CTREXPORT void makeLower(std::string &input);
	/** Creates a new, uppercase version of the given string */
	CTREXPORT std::string toUpper(std::string_view input);
	/** Converts the given string to uppercase in-place */
	CTREXPORT void makeUpper(std::string &input);
	/** Case-insensitive strcmp */
	CTREXPORT int strcmp_nocase(char const *a, char const *b);
	/** \returns number of doubles copied */
	CTREXPORT uint32_t safe_copyDoubles(double *dest, double const *src, int32_t numDoubles, int32_t capacityDoubles);
	/** \returns number of doubles copied */
	CTREXPORT uint32_t safe_copyDoubles(double *dest, std::vector<double> const &src, int32_t capacityDoubles);
	/** Safely copies data from the source to the destination. At most capacity bytes will be copied. */
	CTREXPORT size_t safe_memcpy(void *dest, void const *src, size_t numBytesToCopy, size_t capacity);
	/**
	 * Safely copies a string to the destination. The source will be copied until the
	 * destination is full, and the destination will be null-terminated.
	 */
	CTREXPORT char *safe_strcpy(char *dest, char const *src, size_t capacity);
	/**
	 * Safely copies a string to the destination. The source will be copied until the
	 * destination is full or the source capacity has been reached, and the destination
	 * will be null-terminated.
	 */
	CTREXPORT char *safe_strcpy(char *dest, char const *src, size_t capacityDest, size_t capacitySrc);
	/**
	 * Safely concatenates a string to the destination. The source will be concatenated
	 * until the destination is full, and the destination will be null-terminated.
	 */
	CTREXPORT char *safe_strcat(char *dest, char const *src, size_t capacity);
	/**
	 * Safely concatenates a string to the destination. The source will be concatenated
	 * until the destination is full or the source capacity has been reached,
	 * and the destination will be null-terminated.
	 */
	CTREXPORT char *safe_strcat(char *dest, char const *src, size_t capacityDest, size_t capacitySrc);
	/**
	 * Safer strtok that finds and returns a pointer to the next token
	 * in *str_ptr, separated using one of the delimiters passed in.
	 * This also function modifies the input str_ptr to point to the
	 * remaining string after the delimiter, or NULL if none is found.
	 *
	 * This function is similar to the POSIX `strsep()`
	 *
	 * Unlike strtok, you should always pass in str_ptr.
	 * The caller must make sure both inputs are null terminated.
	 *
	 * ~~~{.c}
	 * char str_buffer[] = "\nThis is\n a  test ";
	 * char *str = str_buffer;
	 * char *token = safe_strtok(&str, " \n");
	 * while (token != NULL) {
	 *     printf("%s\n", token);
	 *     token = safe_strtok(&str, " \n");
	 * }
	 * ~~~
	 */
	CTREXPORT char *safe_strtok(char **str_ptr, char const *delimiters);

	/** Safely determines the length of a string with the given capacity. */
	CTREXPORT constexpr size_t safe_strlen(char const *s, size_t capacity)
	{
		if (!s) return 0;
		size_t len = 0;
		/* count the letters, if max or null terminator is reached leave */
		for (; len < capacity && s[len]; ++len);
		return len;
	}

	/**
	 * \brief Converts string to number while informing caller if operation was successful.
	 *
	 * \tparam T    Type of number to convert to
	 * \param str   String to convert from
	 * \param value Value of Type T to capture numeric value
	 * \returns true iff operation was successful
	 */
	template <typename T>
	bool toNumber(std::string const &str, T &value)
	{
		std::istringstream iss{str};
		iss >> std::ws >> value >> std::ws;
		return iss.eof();
	}

} // namespace string_util
} // namespace phoenix
} // namespace ctre
