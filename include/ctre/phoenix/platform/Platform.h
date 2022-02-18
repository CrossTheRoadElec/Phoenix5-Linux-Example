#pragma once

#include "BasePlatform.h"
#include "SleepUs.h"
#include "ReportError.h"
#include "ctre/phoenix/export.h"
#include "ctre/phoenix/ErrorCode.h"

namespace ctre {
namespace phoenix {
namespace platform {
namespace can {

	//-------------- CANivore diagnostic interface, this is only implemented by the CANivore dispatchers ---------------//
	CTREXPORT int32_t CANivoreDiagTransaction(uint8_t *data, uint32_t txDataLen, uint32_t rxDataCapacity, uint32_t &rxDataLen, uint32_t timeoutMs, char const *canbus, bool printErr = true);

	//------------ CANBus registration interface, this is implemented when multiple CAN buses are possible -------------//
	CTREXPORT int32_t RegisterCANbus(char const *canbus);
	CTREXPORT std::string GetCANivoreDevName(char const *canbus);

	//-------------------------- Low Level CANBus interface, this is implemented by everyone ---------------------------//
	CTREXPORT std::vector<std::string> GetCANbusList(void);
	CTREXPORT void CANbus_GetStatus(float &busUtilPerc, uint32_t &busOffCount, uint32_t &txFullCount, uint32_t &rec, uint32_t &tec, int32_t &status, char const *canbus, bool printErr = true);
	CTREXPORT int32_t CANbus_SendFrame(uint32_t messageID, uint8_t const *data, uint8_t dataSize, char const *canbus, bool printErr = true);

	//------------ Mid Level CANBus interface, this is implemented by everyone (BusMgr for phoenix-canutil) ------------//
	CTREXPORT void CANComm_SendMessage(uint32_t messageID, uint8_t const *data, uint8_t dataSize, int32_t periodMs, int32_t *status, char const *canbus, bool printErr = true);
	CTREXPORT void CANComm_ReceiveMessage(uint32_t *messageID, uint32_t messageIDMask, uint8_t *data, uint8_t *dataSize, uint32_t *timeStamp, int32_t *status, char const *canbus, bool printErr = true);
	CTREXPORT void CANComm_OpenStreamSession(uint32_t *sessionHandle, uint32_t messageID, uint32_t messageIDMask, uint32_t maxMessages, int32_t *status, char const *canbus, bool printErr = true);
	CTREXPORT void CANComm_CloseStreamSession(uint32_t sessionHandle, char const *canbus, bool printErr = true);
	CTREXPORT void CANComm_ReadStreamSession(uint32_t sessionHandle, canframe_t *messages, uint32_t messagesToRead, uint32_t *messagesRead, int32_t *status, char const *canbus, bool printErr = true);
	CTREXPORT int32_t CANComm_GetTxSchedulerStatus(void *unusedControlWorld, char const *canbus, bool printErr = true); // used to be GetControlWord

} //namespace can
} //namespace platform
} //namespace phoenix
} //namespace ctre

namespace ctre {
namespace phoenix {
namespace platform {

	/**
	 * Get a stack trace, ignoring the first "offset" symbols.
	 *
	 * @param offset The number of symbols at the top of the stack to ignore
	 */
	CTREXPORT std::string GetStackTrace(int offset);

	CTREXPORT int32_t DisposePlatform();
	CTREXPORT int32_t StartPlatform();

	CTREXPORT int32_t SimCreate(DeviceType type, int id);

	CTREXPORT int32_t SimDestroy(DeviceType type, int id);
	CTREXPORT int32_t SimDestroyAll();

	CTREXPORT int32_t SimSetPhysicsInput(DeviceType type, int id, std::string const &physicsType, double value);
	CTREXPORT int32_t SimGetPhysicsValue(DeviceType type, int id, std::string const &physicsType, double &value);
	CTREXPORT int32_t SimGetLastError(DeviceType type, int id);

} // namespace platform
} // namespace phoenix
} // namespace ctre
