#pragma once
#include <sstream>
#include <vector>
#include <algorithm>
#include "ctre/phoenix/string_util/string_util.h"
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			/**
			 * Describes the desired stator current limiting behavior.
			 */
			struct StatorCurrentLimitConfiguration
			{
				/**
				 * True/False to enable/disable limit feature.
				 */
				bool enable = false;
				/**
				 * The "holding" current (amperes) to limit to when feature is activated.
				 */
				double currentLimit = 0;

				/**
				 * Current must exceed this threshold (amperes) before limiting occurs.
				 * If this value is less than currentLimit, then currentLimit is used as the threshold.
				 */
				double triggerThresholdCurrent = 0;
				/**
				 * How long current must exceed threshold (seconds) before limiting occurs.
				 */
				double triggerThresholdTime = 0;

				/**
				 * Default c'tor.  Because currentLimit is zero, limiting id disabled.
				 */
				StatorCurrentLimitConfiguration() { /* already done - initializers above */ }

				StatorCurrentLimitConfiguration(const double* doubleArray, int doubleArraySz)
				{
					Deserialize(doubleArray, doubleArraySz);
				}

				StatorCurrentLimitConfiguration(bool enable, double currentLimit, double triggerThresholdCurrent, double triggerThresholdTime)
				{
					this->enable = enable;
					this->currentLimit = currentLimit;
					this->triggerThresholdCurrent = triggerThresholdCurrent;
					this->triggerThresholdTime = triggerThresholdTime;
				}
				/**
				 * @return string representation of current faults tripped
				 */
				std::string ToString() const
				{
					std::stringstream work;

					if (false == enable) {
						work << "Limiting is disabled.";
					}
					else {
						/* If current limit is greater than thresholdCurrent,
						 * the device will use current-limit as the threshold.
						 */
						double effectiveThresholdCurr = std::max<double>(currentLimit, triggerThresholdCurrent);

						work << "Current Limiting will activate if STATOR current exceeds " << effectiveThresholdCurr << " amps for " << triggerThresholdTime << " seconds." << "  Then current will hold at " << currentLimit << " amps";
					}
					return work.str();
				}
				std::vector<double> ToArray() const
				{
					std::vector<double>  retval;
					retval.push_back(enable ? 1 : 0);
					retval.push_back(currentLimit);
					retval.push_back(triggerThresholdCurrent);
					retval.push_back(triggerThresholdTime);
					return retval;
				}
				void Deserialize(const double* doubles, int doubleCnt)
				{
					if (doubleCnt <= 0) { return; }

					if (doubleCnt > 0) {
						enable = *doubles++;
						--doubleCnt;
					}
					if (doubleCnt > 0) {
						currentLimit = *doubles++;
						--doubleCnt;
					}
					if (doubleCnt > 0) {
						triggerThresholdCurrent = *doubles++;
						--doubleCnt;
					}
					if (doubleCnt > 0) {
						triggerThresholdTime = *doubles++;
						--doubleCnt;
					}
				}
				bool Equals(const StatorCurrentLimitConfiguration& rhs) const
				{
					bool retval = true;
					retval &= (enable == rhs.enable);
					retval &= (currentLimit == rhs.currentLimit);
					retval &= (triggerThresholdCurrent == rhs.triggerThresholdCurrent);
					retval &= (triggerThresholdTime == rhs.triggerThresholdTime);
					return retval;
				}
			};

		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
