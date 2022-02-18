#pragma once

#include "ctre/phoenix/ErrorCode.h"

/* forward proto's */
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			namespace can {
				class BaseTalon;
			}
		}
	}
}

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {

			/**
			  * Collection of sensors available to the Talon FX.
			  *
			  * For best performance and update-rate,
			  * we recommend using the configSelectedFeedbackSensor() and getSelectedSensor*() routines.
			  * However there are occasions where accessing raw sensor values may be useful or convenient.
			  * Particularly if you are seeding one sensor based on another, or need to circumvent sensor-phase.
			  *
			  * Use the GetTalonFXSensorCollection() routine inside your motor controller to create a sensor collection.
			  */
			class TalonFXSensorCollection {
			public:
				/**
				 * Constructor for TalonFXSensorCollection
				 * @param motorController Talon Motor Controller to connect Collection to
				 */
				TalonFXSensorCollection(ctre::phoenix::motorcontrol::can::BaseTalon& motorController);

				/**
				 * Get the IntegratedSensor position of the Talon FX, regardless of whether
				 *   it is actually being used for feedback.  The units are 2048 per rotation.
				 *	Note : Future versions of software may support scaling features (rotations, radians, degrees, etc) depending on the configuration.
				 * 
				 * This method relies on the Status 21 message, which has a default period of 240ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the IntegratedSensor position.
				 */

				double GetIntegratedSensorPosition();
				/**
				 * Get the IntegratedSensor absolute position of the Talon FX, regardless of whether
				 *   it is actually being used for feedback.  This will be within one rotation (2048 units).
				 *   The signage and range will depend on the configuration.
				 *	Note : Future versions of software may support scaling features (rotations, radians, degrees, etc) depending on the configuration.
				 * 
				 * This method relies on the Status 21 message, which has a default period of 240ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the IntegratedSensor absolute position.
				 */
				double GetIntegratedSensorAbsolutePosition();
				
				/**
				 * Get the IntegratedSensor velocity of the Talon FX, regardless of whether
				 *   it is actually being used for feedback.  
				 *   One unit represents one position unit per 100ms (2048 position units per 100ms).
				 *   The signage and range will depend on the configuration.
				 *	Note : Future versions of software may support scaling features (rotations, radians, degrees, etc) depending on the configuration.
				 * 
				 * This method relies on the Status 21 message, which has a default period of 240ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the IntegratedSensor velocity.
				 */
				double GetIntegratedSensorVelocity();

				/**
				 * Set the IntegratedSensor reported position.  Typically this is used to "zero" the
				 *   sensor. This only works with IntegratedSensor.  To set the selected sensor position
				 *   regardless of what type it is, see SetSelectedSensorPosition in the motor controller class.
				 *
				 * @param   newPosition The position value to apply to the sensor.  
				 * @param   timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 *
				 * @return  error code.
				 */
				ErrorCode SetIntegratedSensorPosition(double newPosition, int timeoutMs = 0);

				/**
				 * Set the IntegratedSensor reported position based on the absolute position.
				 * This can also be done automatically on power boot depending on configuration.
				 *
				 * @param   timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 *
				 * @return  error code.
				 */
				ErrorCode SetIntegratedSensorPositionToAbsolute(int timeoutMs = 0);

				/**
				 * Is forward limit switch closed.
			 	 * 
			 	 * This method relies on the Status 1 message, which has a default period of 10ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  '1' iff forward limit switch is closed, 0 iff switch is open. This function works
				 *          regardless if limit switch feature is enabled.  Remote limit features do not impact this routine.
				 */

				int IsFwdLimitSwitchClosed();

				/**
				 * Is reverse limit switch closed.
			 	 * 
			 	 * This method relies on the Status 1 message, which has a default period of 10ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  '1' iff reverse limit switch is closed, 0 iff switch is open. This function works
				 *          regardless if limit switch feature is enabled.  Remote limit features do not impact this routine.
				 */

				int IsRevLimitSwitchClosed();

			private:
				void* _handle;
			};

		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
