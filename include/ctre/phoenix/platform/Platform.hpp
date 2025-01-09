 /*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/StatusCodes.h"
#include "ctre/phoenix/export.h"
#include "ctre/phoenix/platform/DeviceType.hpp"
#include "ctre/phoenix/platform/canframe.hpp"
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <vector>

namespace ctre
{
    namespace phoenix
    {
        namespace platform
        {
            namespace can
            {

                CTREXPORT int32_t RegisterCANbus(char const *canbus, bool printErr = true);
                CTREXPORT std::string GetCANivoreDevName(char const *canbus);

                CTREXPORT std::vector<std::string> GetCANbusList(void);
                CTREXPORT void CANbus_GetStatus(float &busUtilPerc, uint32_t &busOffCount, uint32_t &txFullCount, uint32_t &rec, uint32_t &tec, int32_t &status, char const *canbus, bool printErr = true);
                CTREXPORT int32_t CANbus_SendFrame(uint32_t messageID, uint8_t const *data, uint8_t dataSize, char const *canbus, bool printErr = true);

                // Tx
                CTREXPORT void CANComm_SendMessage(uint32_t messageID, uint8_t const *data, uint8_t dataSize, int32_t *status, char const *canbus, bool printErr = true);
                CTREXPORT void CANComm_SendPeriodicMessage(uint32_t messageID, uint8_t const *data, uint8_t dataSize, int32_t periodMs, int32_t *status, char const *canbus, bool printErr = true);
                CTREXPORT void CANComm_StopPeriodicMessage(uint32_t messageID, uint8_t const *data, uint8_t dataSize, int32_t *status, char const *canbus, bool printErr = true);
                // Rx
                CTREXPORT void CANComm_ReceiveMessage(uint32_t messageID, canframe_t &frame, int32_t *status, char const *canbus, bool printErr = true);
                CTREXPORT void CANComm_WaitForMessages(std::set<uint32_t> const &messageIDs, uint16_t timeoutMs, int32_t *status, char const *canbus, bool printErr = true);
                // Streams
                CTREXPORT void CANComm_OpenStreamSession(uint32_t *sessionHandle, uint32_t messageID, uint32_t messageIDMask, uint32_t maxMessages, int32_t *status, char const *canbus, bool printErr = true);
                CTREXPORT void CANComm_CloseStreamSession(uint32_t sessionHandle, char const *canbus, bool printErr = true);
                // Scheduler
                CTREXPORT void CANComm_ReadStreamSession(uint32_t sessionHandle, canframe_t *messages, uint32_t messagesToRead, uint32_t *messagesRead, int32_t *status, char const *canbus, bool printErr = true);
                CTREXPORT int32_t CANComm_GetTxSchedulerStatus(void *unusedControlWorld, char const *canbus, bool printErr = true); // used to be GetControlWord
                // Thread priorities
                CTREXPORT int32_t CANComm_SetRxSchedPriority(int priority, bool useRoundRobin, char const *canbus, bool printErr = true);
                CTREXPORT int32_t CANComm_SetTxSchedPriority(int priority, bool useRoundRobin, char const *canbus, bool printErr = true);

            } // namespace can
        } // namespace platform
    } // namespace phoenix
} // namespace ctre

namespace ctre
{
    namespace phoenix
    {
        namespace platform
        {

            /**
             * Get a stack trace, ignoring the first "offset" symbols.
             *
             * \param offset The number of symbols at the top of the stack to ignore
             */
            CTREXPORT std::string GetStackTrace(int offset);

            CTREXPORT int32_t SimCreate(DeviceType type, int id);

            CTREXPORT int32_t SimDestroy(DeviceType type, int id);
            CTREXPORT int32_t SimDestroyAll();

            CTREXPORT int32_t SimSetPhysicsInput(DeviceType type, int id, std::string_view physicsType, double value);
            CTREXPORT int32_t SimGetPhysicsValue(DeviceType type, int id, std::string_view physicsType, double &value);
            CTREXPORT int32_t SimGetLastError(DeviceType type, int id);

            CTREXPORT int32_t ReplayLoadFile(char const *filepath);
            CTREXPORT void ReplayCloseFile();
            CTREXPORT bool ReplayIsFileLoaded();

            CTREXPORT int32_t ReplayPlay();
            CTREXPORT int32_t ReplayPause();
            CTREXPORT int32_t ReplayStop();
            CTREXPORT bool ReplayIsRunning(uint16_t timeoutMs);

            CTREXPORT void ReplaySetSpeed(double speed);
            CTREXPORT int32_t ReplayStepTiming(double stepTimeSeconds);

        } // namespace platform
    } // namespace phoenix
} // namespace ctre
