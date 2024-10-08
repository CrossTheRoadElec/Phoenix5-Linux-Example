/* Copyright (C) Cross The Road Electronics 2024 */
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
			  * Collection of sensors available to a motor controller.
			  *
			  * For best performance and update-rate,
			  * we recommend using the configSelectedFeedbackSensor() and getSelectedSensor*() routines.
			  * However there are occasions where accessing raw sensor values may be useful or convenient.
			  * Particularly if you are seeding one sensor based on another, or need to circumvent sensor-phase.
			  *
			  * Use the getSensorCollection() routine inside your motor controller to create a sensor collection.
			  */
			class SensorCollection {
			public:
				/**
				 * Constructor for SensorCollection
				 * @param motorController Talon Motor Controller to connect Collection to
				 */
				SensorCollection(ctre::phoenix::motorcontrol::can::BaseTalon& motorController);

				/**
				 * Get the position of whatever is in the analog pin of the Talon, regardless of
				 *   whether it is actually being used for feedback.
				 * 
				 * This method relies on the Status 4 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the 24bit analog value.  The bottom ten bits is the ADC (0 - 1023)
				 *          on the analog pin of the Talon. The upper 14 bits tracks the overflows and underflows
				 *          (continuous sensor).
				 */

				int GetAnalogIn();

				/**
				 * Sets analog position.
				 *
				 * @param   newPosition The new position.
				 * @param   timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 *
				 * @return  an ErrorCode.
				 */

				ErrorCode SetAnalogPosition(int newPosition, int timeoutMs = 0);

				/**
				 * Get the position of whatever is in the analog pin of the Talon, regardless of whether
				 *   it is actually being used for feedback.
				 * 
				 * This method relies on the Status 4 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the ADC (0 - 1023) on analog pin of the Talon.
				 */

				int GetAnalogInRaw();

				/**
				 * Get the velocity of whatever is in the analog pin of the Talon, regardless of
				 *   whether it is actually being used for feedback.
				 * 
				 * This method relies on the Status 4 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the speed in units per 100ms where 1024 units is one rotation.
				 */

				int GetAnalogInVel();

				/**
				 * Get the quadrature position of the Talon, regardless of whether
				 *   it is actually being used for feedback.
				 * 
				 * This method relies on the Status 3 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the quadrature position.
				 */

				int GetQuadraturePosition();

				/**
				 * Change the quadrature reported position.  Typically this is used to "zero" the
				 *   sensor. This only works with Quadrature sensor.  To set the selected sensor position
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

				ErrorCode SetQuadraturePosition(int newPosition, int timeoutMs = 0);

				/**
				 * Change the quadrature reported position based on pulse width. This can be used to
				 * effectively make quadrature absolute. For rotary mechanisms with >360 movement (such
				 * as typical swerve modules) bookend0 and bookend1 can be both set to 0 and
				 * bCrossZeroOnInterval can be set to true. For mechanisms with less than 360 travel (such
				 * as arms), bookend0 and bookend1 should be set to the pulse width values at the two
				 * extremes. If the interval crosses over the pulse width value of 0 (or any multiple of
				 * 4096), bCrossZeroOnInterval should be true and otherwise should be false. An offset can
				 * also be set.
				 *
				 * @param   bookend0    value at extreme 0
				 * @param   bookend1    value at extreme 1
				 * @param   bCrossZeroOnInterval    value at extreme 1
				 * @param   offset      (Optional) Value to add to pulse width
				 * @param   timeoutMs   (Optional) How long to wait for confirmation.  Pass zero so that call
				 *                      does not block.
				 *
				 * @return  error code.
				 */

				ErrorCode SyncQuadratureWithPulseWidth(int bookend0, int bookend1, bool bCrossZeroOnInterval, int offset = 0, int timeoutMs = 0);

				/**
				 * Get the quadrature velocity, regardless of whether
				 *   it is actually being used for feedback.
				 * 
				 * This method relies on the Status 3 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the quadrature velocity in units per 100ms.
				 */

				int GetQuadratureVelocity();

				/**
				 * Gets pulse width position, regardless of whether
				 *   it is actually being used for feedback.
				 * 
				 * This method relies on the Status 8 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the pulse width position.
				 */

				int GetPulseWidthPosition();

				/**
				 * Sets pulse width position.
				 *
				 * @param   newPosition The position value to apply to the sensor.
				 * @param   timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 *
				 * @return  an ErrErrorCode
				 */
				ErrorCode SetPulseWidthPosition(int newPosition, int timeoutMs = 0);

				/**
				 * Gets pulse width velocity, regardless of whether
				 *   it is actually being used for feedback.
				 * 
				 * This method relies on the Status 8 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the pulse width velocity in units per 100ms (where 4096 units is 1 rotation).
				 */

				int GetPulseWidthVelocity();

				/**
				 * Gets pulse width rise to fall time.
				 * 
				 * This method relies on the Status 8 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the pulse width rise to fall time in microseconds.
				 */

				int GetPulseWidthRiseToFallUs();

				/**
				 * Gets pulse width rise to rise time.
				 * 
				 * This method relies on the Status 8 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the pulse width rise to rise time in microseconds.
				 */

				int GetPulseWidthRiseToRiseUs();

				/**
				 * Gets pin state quad a.
				 * 
				 * This method relies on the Status 3 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  the pin state of quad a (1 if asserted, 0 if not asserted).
				 */

				int GetPinStateQuadA();

				/**
				 * Gets pin state quad b.
				 * 
				 * This method relies on the Status 3 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  Digital level of QUADB pin (1 if asserted, 0 if not asserted).
				 */

				int GetPinStateQuadB();

				/**
				 * Gets pin state quad index.
				 * 
				 * This method relies on the Status 3 message, which has a default period of 150ms. For more
				 * information, see: https://phoenix-documentation.readthedocs.io/en/latest/ch18_CommonAPI.html
				 *
				 * @return  Digital level of QUAD Index pin (1 if asserted, 0 if not asserted).
				 */

				int GetPinStateQuadIdx();

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
				SensorCollection(void* handle);
				friend class ctre::phoenix::motorcontrol::can::BaseTalon;
				void* _handle;

			};

		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
