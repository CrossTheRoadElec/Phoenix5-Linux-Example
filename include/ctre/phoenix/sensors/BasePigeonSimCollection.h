#pragma once

#include "ctre/phoenix/ErrorCode.h"
#include "ctre/phoenix/cci/Platform_CCI.h"

/* forward proto's */
namespace ctre {
	namespace phoenix {
		namespace sensors {
			class BasePigeon;
		}
	}
}

namespace ctre {
	namespace phoenix {
		namespace sensors {
			/**
			  * Collection of simulation functions available to a Pigeon IMU.
			  * Use the getSimCollection() function in your BasePigeon object to create the respective sim collection.
			  */
			class BasePigeonSimCollection {
			public:
				/** 
				  * @param pigeon Pigeon IMU to connect so sim collection
				  */
				BasePigeonSimCollection(ctre::phoenix::sensors::BasePigeon& pigeon, bool isRibbonCable);

				/**
				 * Sets the simulated input heading position of the Pigeon IMU.
				 *
				 * The Pigeon IMU integrates the delta between each new raw heading value and uses
				 * this to calculate the true reported yaw and fused heading.
				 *
				 * When using the WPI Sim GUI, you will notice a readonly 'yaw' and
				 * settable 'RawHeading'.  The readonly signal is the emulated yaw
				 * which will match self-test in Tuner and the hardware API.  Changes to
				 * 'RawHeading' will be integrated into the emulated yaw.  This way
				 * a simulator can modify the heading without overriding your
				 * hardware API calls for home-ing your sensor.
				 *
				 * Inputs to this function over time should be continuous,
				 * as user calls of setYaw() or setFusedHeading()
				 * will be accounted for in the calculation.
				 *
				 * @param newHeading the new input heading in degrees
				 *
				 * @return  error code
				 */
				ErrorCode SetRawHeading(double newHeading);

				/**
				 * Adds to the simulated heading of the Pigeon IMU
				 *
				 * @param dHeading the change in heading in degrees
				 *
				 * @return error code
				 */
				ErrorCode AddHeading(double dHeading);

			private:
				int _id;
				ctre::phoenix::platform::DeviceType _type;
			};
		}
	}
}