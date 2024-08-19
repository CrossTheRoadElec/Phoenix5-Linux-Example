/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

CTREXPORT bool c_ctre_phoenix6_platform_canbus_is_network_fd(char const *canbus);
CTREXPORT int32_t c_ctre_phoenix6_platform_canbus_get_status(float *busUtilPerc, uint32_t *busOffCount, uint32_t *txFullCount, uint32_t *rec, uint32_t *tec, char const *canbus, bool printErr);
CTREXPORT void c_ctre_phoenix6_platform_canbus_sendmessage(uint32_t messageId, uint8_t const *data, uint8_t dataSize, char const *canbus, bool printErr);
CTREXPORT int32_t c_ctre_phoenix6_platform_canbus_receivemessage(uint32_t messageId, uint8_t *data, uint8_t * dataSize, char const *canbus, bool printErr);
CTREXPORT int32_t c_ctre_phoenix6_platform_sim_create(int deviceType, int id);
CTREXPORT int32_t c_ctre_phoenix6_platform_sim_destroy(int deviceType, int id);
CTREXPORT int32_t c_ctre_phoenix6_platform_sim_destroy_all(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_sim_set_physics_input(int deviceType, int id, char const *physicsType, double value);
CTREXPORT int32_t c_ctre_phoenix6_platform_sim_get_physics_value(int deviceType, int id, char const *physicsType, double *value);
CTREXPORT int32_t c_ctre_phoenix6_platform_sim_get_last_error(int deviceType, int id);
CTREXPORT int32_t c_ctre_phoenix6_platform_set_logger_path(char const *path);
CTREXPORT int32_t c_ctre_phoenix6_platform_start_logger(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_stop_logger(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_enable_auto_logging(bool enable);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_raw(char const *name, uint8_t const *data, uint8_t size, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_boolean(char const *name, bool value, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_integer(char const *name, int64_t value, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_float(char const *name, float value, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_double(char const *name, double value, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_string(char const *name, char const *value, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_boolean_array(char const *name, bool const *values, uint8_t count, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_integer_array(char const *name, int64_t const *values, uint8_t count, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_float_array(char const *name, float const *values, uint8_t count, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_double_array(char const *name, double const *values, uint8_t count, char const *units, double latencySeconds);

#ifdef __cplusplus
}
#endif
