/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

namespace ctre {
namespace phoenix {

/**
 * Class to convert Hue, Saturation, Value to Red, Green, Blue
 */
class HsvToRgb {
public:
	/**
	 * Converts HSV to RGB
	 * @param hDegrees hue value
	 * @param S saturation value
	 * @param V value Lightness value
	 * @param r pointer to red value
	 * @param g pointer to green value
	 * @param b pointer to blue value
	 *
	 * @deprecated The CANdle Phoenix 5 API is deprecated for removal in the
	 * 2027 season. Users should update to Phoenix 6 firmware and migrate to the
	 * Phoenix 6 API. A migration guide is available at
	 * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
	 */
	[[deprecated("The CANdle Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static void Convert(double hDegrees, double S, double V, float* r, float* g,
			float* b);
};

}
}
