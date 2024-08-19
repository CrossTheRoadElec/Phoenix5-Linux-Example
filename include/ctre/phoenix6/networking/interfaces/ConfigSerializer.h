/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    /* Note: This returns a malloc'd char array that caller needs to free */
    CTREXPORT int c_ctre_phoenix6_serialize_double(int spn, double value, char **str);
    CTREXPORT int c_ctre_phoenix6_serialize_double_no_malloc(int spn, double value, char *str, uint32_t max_len);
    /* Note: This returns a malloc'd char array that caller needs to free */
    CTREXPORT int c_ctre_phoenix6_serialize_int(int spn, int value, char **str);
    CTREXPORT int c_ctre_phoenix6_serialize_int_no_malloc(int spn, int value, char *str, uint32_t max_len);
    /* Note: This returns a malloc'd char array that caller needs to free */
    CTREXPORT int c_ctre_phoenix6_serialize_bool(int spn, bool value, char **str);
    CTREXPORT int c_ctre_phoenix6_serialize_bool_no_malloc(int spn, bool value, char *str, uint32_t max_len);
    /* Note: This returns a malloc'd char array that caller needs to free */
    CTREXPORT int c_ctre_phoenix6_serialize_pgn(int spn, uint16_t frame_index, uint16_t framePeriodMs, char **str);
    CTREXPORT int c_ctre_phoenix6_serialize_pgn_no_malloc(int spn, uint16_t frame_index, uint16_t framePeriodMs, char *str, uint32_t max_len);

    CTREXPORT int c_ctre_phoenix6_deserialize_double(int spn, const char *str, uint32_t strlen, double *val);
    CTREXPORT int c_ctre_phoenix6_deserialize_int(int spn, const char *str, uint32_t strlen, int *val);
    CTREXPORT int c_ctre_phoenix6_deserialize_bool(int spn, const char *str, uint32_t strlen, bool *val);
    CTREXPORT int c_ctre_phoenix6_deserialize_pgn(int spn, const char *str, uint32_t strlen, uint16_t *frame_index, uint16_t *framePeriodMs);

    CTREXPORT void c_ctre_phoenix6_free_memory(char **str);
#ifdef __cplusplus
}
#endif