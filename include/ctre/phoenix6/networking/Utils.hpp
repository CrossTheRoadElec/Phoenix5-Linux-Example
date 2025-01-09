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
namespace utils {

    /**
     * \brief Get the current timestamp in seconds.
     *
     * This is the time source used for status signals.
     *
     * This time source is typically continuous and monotonic.
     * However, it may be overridden in simulation to use a
     * non-monotonic, non-continuous source.
     *
     * \returns Current time in seconds.
     */
    CTREXPORT double GetCurrentTimeSeconds();
    /**
     * \brief Get the system timestamp in seconds.
     *
     * This is NOT the time source used for status signals.
     * Use GetCurrentTimeSeconds instead when working with
     * status signal timing.
     *
     * This time source is guaranteed to be continuous and
     * monotonic, making it useful for measuring time deltas
     * in a robot program.
     *
     * \returns System time in seconds.
     */
    CTREXPORT double GetSystemTimeSeconds();
    /**
     * \brief Get whether the program is running in simulation.
     *
     * \returns `true` if in simulation
     */
    CTREXPORT bool IsSimulation();
    /**
     * \brief Get whether the program is running in replay mode.
     *
     * \returns `true` if in replay mode
     */
    CTREXPORT bool IsReplay();

}
}
}
