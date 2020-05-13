#pragma once

#include <string>
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			/**
			 * Choose the type of motor commutation.  This is for products that support selectable commutation strategies.
			 */
			enum class MotorCommutation {
				Trapezoidal = 0, //!< Trapezoidal Commutation
			};
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
