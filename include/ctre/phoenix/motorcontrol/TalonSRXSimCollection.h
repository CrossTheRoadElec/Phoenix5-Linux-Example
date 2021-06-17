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
			  * Collection of simulation commands available to a TalonSRX motor controller.
			  *
			  * Use the getSimCollection() routine inside your motor controller to create a sim collection.
			  */
			class TalonSRXSimCollection {
			public:
				/**
				 * Constructor for TalonSRXSimCollection
				 * @param motorController TalonSRX Motor Controller to connect Collection to
				 */
				TalonSRXSimCollection(ctre::phoenix::motorcontrol::can::BaseTalon& motorController);

				/**
				 * Sets the simulated bus voltage of the TalonSRX.
				 * 
				 * @param vbat the bus voltage
				 *
				 * @return  error code
				 */
				ErrorCode SetBusVoltage(double vbat);

				/**
				 * Sets the simulated supply current of the TalonSRX.
				 * 
				 * @param currA the supply current in amps
				 *
				 * @return  error code
				 */
				ErrorCode SetSupplyCurrent(double currA);

				/**
				 * Sets the simulated stator current of the TalonSRX.
				 * 
				 * @param currA the stator current in amps
				 *
				 * @return  error code
				 */
				ErrorCode SetStatorCurrent(double currA);

				/**
				 * Sets the simulated forward limit switch of the TalonSRX.
				 * 
				 * @param isClosed true if the limit switch is closed
				 *
				 * @return  error code
				 */
				ErrorCode SetLimitFwd(bool isClosed);

				/**
				 * Sets the simulated reverse limit switch of the TalonSRX.
				 * 
				 * @param isClosed true if the limit switch is closed
				 *
				 * @return  error code
				 */
				ErrorCode SetLimitRev(bool isClosed);

				/**
				 * Sets the simulated analog position of the TalonSRX.
				 * 
				 * @param newPos the new position in native units
				 *
				 * @return  error code
				 */
				ErrorCode SetAnalogPosition(int newPos);

				/**
				 * Adds to the simulated analog position of the TalonSRX.
				 * 
				 * @param dPos the change in position in native units
				 *
				 * @return  error code
				 */
				ErrorCode AddAnalogPosition(int dPos);

				/**
				 * Sets the simulated analog velocity of the TalonSRX.
				 * 
				 * @param newVel the new velocity in native units per 100ms
				 *
				 * @return  error code
				 */
				ErrorCode SetAnalogVelocity(int newVel);

				/**
				 * Sets if the simulated pulse width sensor is connected to the TalonSRX.
				 * 
				 * @param isConnected true if the pulse width sensor is connected
				 * 
				 * @return  error code
				 */
				ErrorCode SetPulseWidthConnected(bool isConnected);

				/**
				 * Sets the simulated pulse width rise to rise time of the TalonSRX.
				 * 
				 * @param periodUs the pulse width rise to rise time in microseconds
				 * 
				 * @return  error code
				 */
				ErrorCode SetPulseWidthRiseToRiseUs(double periodUs);

				/**
				 * Sets the simulated pulse width position of the TalonSRX.
				 * 
				 * @param newPos the new position in native units
				 *
				 * @return  error code
				 */
				ErrorCode SetPulseWidthPosition(int newPos);

				/**
				 * Adds to the simulated pulse width position of the TalonSRX.
				 * 
				 * @param dPos the change in position in native units
				 *
				 * @return  error code
				 */
				ErrorCode AddPulseWidthPosition(int dPos);

				/**
				 * Sets the simulated pulse width velocity of the TalonSRX.
				 * 
				 * @param newVel the new velocity in native units per 100ms
				 *
				 * @return  error code
				 */
				ErrorCode SetPulseWidthVelocity(int newVel);

				/**
				 * Sets the simulated raw quadrature position of the TalonSRX. 
				 *
				 * The TalonSRX integrates this to calculate the true reported quadrature 
				 * position. 
				 *
				 * When using the WPI Sim GUI, you will notice a readonly 'position' and 
				 * settable 'rawPositionInput'.  The readonly signal is the emulated position 
				 * which will match self-test in Tuner and the hardware API.  Changes to 
				 * 'rawPositionInput' will be integrated into the emulated position.  This way 
				 * a simulator can modify the position without overriding your 
				 * hardware API calls for home-ing your sensor. 
				 *
				 * Inputs to this function over time should be continuous, 
				 * as user calls of setSelectedSensorPosition() and setQuadraturePosition() 
				 * will be accounted for in the calculation.
				 * 
				 * @param newPos the new raw position in native units
				 *
				 * @return  error code
				 */
				ErrorCode SetQuadratureRawPosition(int newPos);

				/**
				 * Adds to the simulated quadrature position of the TalonSRX.
				 * 
				 * @param dPos the change in position in native units
				 *
				 * @return  error code
				 */
				ErrorCode AddQuadraturePosition(int dPos);

				/**
				 * Sets the simulated quadrature velocity of the TalonSRX.
				 * 
				 * @param newVel the new velocity in native units per 100ms
				 *
				 * @return  error code
				 */
				ErrorCode SetQuadratureVelocity(int newVel);

			private:
				int _id;

			};

		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
