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

CTREXPORT int32_t c_ctre_phoenix6_platform_replay_load_file(char const *filepath);
CTREXPORT void c_ctre_phoenix6_platform_replay_close_file(void);
CTREXPORT bool c_ctre_phoenix6_platform_replay_is_file_loaded(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_play(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_pause(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_stop(void);
CTREXPORT bool c_ctre_phoenix6_platform_replay_is_running(uint16_t timeoutMs);
CTREXPORT bool c_ctre_phoenix6_platform_replay_is_finished(void);
CTREXPORT void c_ctre_phoenix6_platform_replay_set_speed(double speed);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_step_timing(double stepTimeSeconds);

/* NOTE: For SchemaValue, Raw, String, and Arrays, caller must manually free the provided buffer, as well as the units buffer. */
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_schema_value(char const *name, uint16_t type, char **units, uint8_t **data, uint32_t *len, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_raw(char const *name, char **units, uint8_t **data, uint32_t *len, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_boolean(char const *name, char **units, bool *value, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_integer(char const *name, char **units, int64_t *value, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_float(char const *name, char **units, float *value, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_double(char const *name, char **units, double *value, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_string(char const *name, char **units, char **value, uint32_t *len, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_boolean_array(char const *name, char **units, bool **values, uint32_t *count, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_integer_array(char const *name, char **units, int64_t **values, uint32_t *count, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_float_array(char const *name, char **units, float **values, uint32_t *count, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_double_array(char const *name, char **units, double **values, uint32_t *count, double *timestampSeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_replay_get_string_array(char const *name, char **units, char ***values, uint32_t *count, double *timestampSeconds);

CTREXPORT int32_t c_ctre_phoenix6_platform_set_logger_path(char const *path);
CTREXPORT int32_t c_ctre_phoenix6_platform_start_logger(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_stop_logger(void);
CTREXPORT int32_t c_ctre_phoenix6_platform_enable_auto_logging(bool enable);
CTREXPORT int32_t c_ctre_phoenix6_platform_add_schema(char const *name, uint16_t type, uint8_t const *schema, uint32_t size);
CTREXPORT int32_t c_ctre_phoenix6_platform_add_schema_string(char const *name, uint16_t type, char const *schema, uint32_t size);
CTREXPORT bool c_ctre_phoenix6_platform_has_schema(char const *name, uint16_t type);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_schema_value(char const *name, char const *schema, uint16_t type, uint8_t const *data, uint32_t size, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_raw(char const *name, uint8_t const *data, uint32_t size, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_boolean(char const *name, bool value, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_integer(char const *name, int64_t value, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_float(char const *name, float value, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_double(char const *name, double value, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_string(char const *name, char const *value, uint32_t size, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_boolean_array(char const *name, bool const *values, uint32_t count, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_integer_array(char const *name, int64_t const *values, uint32_t count, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_float_array(char const *name, float const *values, uint32_t count, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_double_array(char const *name, double const *values, uint32_t count, char const *units, double latencySeconds);
CTREXPORT int32_t c_ctre_phoenix6_platform_write_string_array(char const *name, char const *const *values, uint32_t count, double latencySeconds);

#ifdef __cplusplus
}
#endif
