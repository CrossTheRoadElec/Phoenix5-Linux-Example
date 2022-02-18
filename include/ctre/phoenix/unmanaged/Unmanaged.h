#pragma once
namespace ctre {
namespace phoenix {
/** unmanaged namespace */
namespace unmanaged {

/**
 * Handles enabling when used in a non-FRC manner
 */
class Unmanaged {
public:
    /**
     * Feed the enable frame.
     * This function does nothing on a roborio during FRC use.
     * 
     * If running an application in simulation, creating a WPI_*
     * object automatically enables actuators.
     * Otherwise, call this to enable actuators.
     * 
     * @param timeoutMs Timeout before disabling
     */
    static void FeedEnable(int timeoutMs);
    /**
     * @return true if enabled
     */
    static bool GetEnableState();
    /**
     * @return Phoenix version
     */
    static int GetPhoenixVersion();
    /**
     * Calling this function will load and start
     * the Phoenix background tasks.
     * 
     * This can be useful if you need the
     * Enable/Disable functionality for CAN devices
     * but aren't using any of the CAN device classes.
     * 
     * This function does NOT need to be called if
     * you are using any of the Phoenix CAN device classes.
     */
    static void LoadPhoenix();

    /**
     * Sets the duration of the delay before starting 
     * the Phoenix diagnostics server.
     * 
     * @param startTime Magnitude of the delay (in seconds) before
     *                  starting the server.
     *                  A value of 0 will start the server immediately.
     *                  A negative value will signal the server 
     *                      to shutdown or never start.
     */
    static void SetPhoenixDiagnosticsStartTime(int startTimeSeconds);
};

}
}
}
