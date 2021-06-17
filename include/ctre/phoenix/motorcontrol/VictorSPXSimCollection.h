#pragma once

#include "ctre/phoenix/ErrorCode.h"

/* forward proto's */
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			namespace can {
				class BaseMotorController;
			}
		}
	}
}

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {

			/**
			  * Collection of simulation commands available to a VictorSPX motor controller.
			  *
			  * Use the getSimCollection() routine inside your motor controller to create a sim collection.
			  */
			class VictorSPXSimCollection {
			public:
				/**
				 * Constructor for VictorSPXSimCollection
				 * @param motorController VictorSPX Motor Controller to connect Collection to
				 */
				VictorSPXSimCollection(ctre::phoenix::motorcontrol::can::BaseMotorController& motorController);

				/**
				 * Sets the simulated bus voltage of the VictorSPX.
				 * 
				 * @param vbat the bus voltage
				 *
				 * @return  error code
				 */
				ErrorCode SetBusVoltage(double vbat);

			private:
				int _id;

			};

		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
