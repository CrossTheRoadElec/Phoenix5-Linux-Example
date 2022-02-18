#pragma once

#include "ctre/phoenix/ErrorCode.h"
#include "ctre/phoenix/cci/Platform_CCI.h"

/* forward proto's */
namespace ctre {
	namespace phoenix {
		namespace sensors {
			class CANCoder;
		}
	}
}

namespace ctre {
	namespace phoenix {
		namespace sensors {
			/**
			 * Collection of simulation functions available to a CANCoder.
			 * 
			 * Use the getSimCollection() function in your CANCoder object to create the respective sim collection.
			 */
			class CANCoderSimCollection {
			public:
				/** 
				 * Constructor for CANCoderSimCollection
				 * 
				 * @param canCoder CANCoder to connect Collection to
				 */
				CANCoderSimCollection(ctre::phoenix::sensors::CANCoder& canCoder);

				/**
				 * Sets the simulated bus voltage of the CANCoder.
				 * 
				 * The minimum allowed bus voltage is 4 V - values
				 * below this will be promoted to 4 V.
				 * 
				 * @param vbat the bus voltage in volts
				 *
				 * @return  error code
				 */
				ErrorCode SetBusVoltage(double vbat);

				/**
				 * Sets the simulated raw position of the CANCoder.
				 * 
				 * The CANCoder integrates this to calculate the true reported position.
				 * 
				 * When using the WPI Sim GUI, you will notice a readonly 'position' and
				 * settable 'rawPositionInput'.  The readonly signal is the emulated position
				 * which will match self-test in Tuner and the hardware API.  Changes to
				 * 'rawPositionInput' will be integrated into the emulated position.  This way
				 * a simulator can modify the position without overriding your
				 * hardware API calls for home-ing your sensor.
				 * 
				 * Inputs to this function over time should be continuous, as user calls
				 * of setPosition() will be accounted for in the calculation.
				 * 
				 * @param newPos the new raw position in native units
				 *
				 * @return  error code
				 */
				ErrorCode SetRawPosition(int newPos);

				/**
				 * Adds to the simulated position of the CANCoder.
				 * 
				 * @param dPos the change in position in native units
				 *
				 * @return  error code
				 */
				ErrorCode AddPosition(int dPos);

				/**
				 * Sets the simulated velocity of the CANCoder.
				 * 
				 * @param newVel the new velocity in native units per 100ms
				 *
				 * @return  error code
				 */
				ErrorCode SetVelocity(int newVel);

			private:
				int _id;
				ctre::phoenix::platform::DeviceType _type;
			};
		}
	}
}