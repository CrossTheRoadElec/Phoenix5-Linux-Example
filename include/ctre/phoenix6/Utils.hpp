/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"

namespace ctre {
namespace phoenix6 {

    /**
     * \brief Get the current timestamp in seconds.
     *
     * \details This will return the current time in seconds, this is
     * the same time that is used in Timestamp.
     *
     * \returns Current time in seconds.
     */
    CTREXPORT double GetCurrentTimeSeconds();
    /**
     * \brief Get whether the program is running in simulation.
     *
     * \returns `true` if in simulation
     */
    CTREXPORT bool IsSimulation();

}
}
