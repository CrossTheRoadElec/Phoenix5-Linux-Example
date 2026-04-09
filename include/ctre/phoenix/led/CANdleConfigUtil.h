/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/CANdleConfiguration.h"
#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/Utilities.h"

namespace ctre{ namespace phoenix{ namespace led{

/**
 * Util class to help with configuring CANdle
 *
 * @deprecated This device's Phoenix 5 API is deprecated for removal in the
 * 2027 season. Users should update to Phoenix 6 firmware and migrate to the
 * Phoenix 6 API. A migration guide is available at
 * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
 *
 * If the Phoenix 5 API must be used for this device, the device must have 22.X
 * firmware. This firmware is available in Tuner X after selecting Phoenix 5 in
 * the firmware year dropdown.
 */
class [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
			"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
			"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
CANdleConfigUtil : public CustomParamConfigUtil{
	static const CANdleConfiguration &_default();
public:

	[[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static bool StripTypeDifferent (CANdleConfiguration settings);
	[[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static bool BrightnessScalarDifferent (CANdleConfiguration settings);
	[[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static bool DisableWhenLOSDifferent (CANdleConfiguration settings);
	[[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static bool StatusLedOffWhenActiveDifferent (CANdleConfiguration settings);
	[[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static bool VBatOutputModeDifferent (CANdleConfiguration settings);
	[[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
				"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
				"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
	static bool V5EnabledDifferent (CANdleConfiguration settings);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
