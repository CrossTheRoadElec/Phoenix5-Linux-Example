#pragma once

#include "Platform-pack.h"
#include "canframe.h"
#include <string>
#include <vector>

/* forward prototype, defined in platform implementation */
class CANivoreSocket;

namespace ctre {
namespace phoenix {
namespace platform {
namespace can {

	/* interface for CAN Platforms */
	class BaseCANbusDispatcher {
	public:
		/* the CANbusDispatcher implementation will define this */
		static BaseCANbusDispatcher &GetInstance(void);

		virtual void Dispose(void);

		//-------------- CANivore diagnostic interface, this is required only for the CANivore dispatchers ---------------//
		virtual int32_t CANivoreDiagTransaction(uint8_t *data, uint32_t txDataLen, uint32_t rxDataCapacity, uint32_t &rxDataLen, uint32_t timeoutMs, char const *canbus, bool printErr);

		//------------ CANBus registration interface, this is required when multiple CAN buses are possible -------------//
		virtual int32_t RegisterCANbus(char const *canbus);
		virtual std::string GetCANivoreDevName(char const *canbus);

		//-------------------------- Low Level CANBus interface, this is required for everyone --------------------------//
		virtual std::vector<std::string> GetCANbusList(void) = 0;
		virtual void GetStatus(float &busUtilPerc, uint32_t &busOffCount, uint32_t &txFullCount, uint32_t &rec, uint32_t &tec, int32_t &status, char const *canbus, bool printErr) = 0;
		virtual int32_t SendFrame(uint32_t messageID, uint8_t const *data, uint8_t dataSize, char const *canbus, bool printErr) = 0;

		//----------- Mid Level CANBus interface, this is required for everyone (BusMgr for phoenix-canutil) ------------//
		virtual void CANComm_SendMessage(uint32_t messageID, uint8_t const *data, uint8_t dataSize, int32_t periodMs, int32_t *status, char const *canbus, bool printErr) = 0;
		virtual void CANComm_ReceiveMessage(uint32_t *messageID, uint32_t messageIDMask, uint8_t *data, uint8_t *dataSize, uint32_t *timeStamp, int32_t *status, char const *canbus, bool printErr) = 0;
		virtual void CANComm_OpenStreamSession(uint32_t *sessionHandle, uint32_t messageID, uint32_t messageIDMask, uint32_t maxMessages, int32_t *status, char const *canbus, bool printErr) = 0;
		virtual void CANComm_CloseStreamSession(uint32_t sessionHandle, char const *canbus, bool printErr) = 0;
		virtual void CANComm_ReadStreamSession(uint32_t sessionHandle, canframe_t *messages, uint32_t messagesToRead, uint32_t *messagesRead, int32_t *status, char const *canbus, bool printErr) = 0;
		virtual int32_t CANComm_GetTxSchedulerStatus(void *unusedControlWorld, char const *canbus, bool printErr) = 0; // used to be GetControlWord
	};

	/* interface for CAN Platforms using BusMgr */
	class BaseCANDriver {
	public:
		/* the CANDriver implementation will define this */
		static BaseCANDriver &GetInstance(void);

		virtual void GetStatus(float &busUtilPerc, uint32_t &busOffCount, uint32_t &txFullCount, uint32_t &rec, uint32_t &tec, int32_t &status, CANivoreSocket const *socket) = 0;
		/* When possible, implementations should NOT make this blocking */
		virtual int32_t SendFrame(uint32_t messageID, uint8_t const *data, uint8_t dataSize, CANivoreSocket const *socket) = 0;
		virtual uint16_t GetMinRxBufferSz(void) = 0;
		/* Windows: This routine will block up to a fixed timeout (10ms).  This is necessary for good performance.
		 * Linux: This routine is non-blocking to prevent mutex-blocks. Caller should have a yield to prevent high-cpu spinning. */
		virtual int32_t ReceiveFrame(canframe_t *toFill, uint32_t frameCap, uint32_t &numFilled, CANivoreSocket const *socket) = 0;
	};

} //namespace can
} //namespace platform
} //namespace phoenix
} //namespace ctre

namespace ctre {
namespace phoenix {
namespace platform {

	/** list of all supporte device types */
	#define kDeviceTypeListInitializer	TalonSRXType, VictorSPXType, PigeonIMUType, RibbonPigeonIMUType, TalonFXType, CANCoderType

	enum DeviceType {kDeviceTypeListInitializer};

	/* interface for Platforms */
	class BaseSimPlatform {
	public:
		/* the Platform implementation will define this */
		static BaseSimPlatform &GetInstance(void);

		virtual int32_t SimCreate(DeviceType type, int id);

		virtual int32_t SimDestroy(DeviceType type, int id);
		virtual int32_t SimDestroyAll();

		virtual int32_t SimSetPhysicsInput(DeviceType type, int id, std::string const &physicsType, double value);
		virtual int32_t SimGetPhysicsValue(DeviceType type, int id, std::string const &physicsType, double &value);
		virtual int32_t SimGetLastError(DeviceType type, int id);
	};

} // namespace platform
} // namespace phoenix
} // namespace ctre
