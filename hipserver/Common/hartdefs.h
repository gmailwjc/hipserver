/*************************************************************************************************
 * Copyright 2020 FieldComm Group, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *****************************************************************/

/**********************************************************
 *
 * File Name:
 *   hartdefs.h
 * File Description:
 *   Header file containing common HART Protocol constants
 *   and definitions.
 *
 **********************************************************/
#ifndef _HARTDEFS_H
#define _HARTDEFS_H

#include "common.h"
#include "datatypes.h"

/***************
 * Definitions
 ***************/
/* HART Master Types */
#define HART_PRIMARY       1
#define HART_SECONDARY     0

/* Misc. Definitions */
#define HART_CMD_EXP_FLAG  31
#define HART_INVALID_CMD   5       // Illegal/Reserved
#define HART_LONGTAG_LEN   32
#ifndef HART_NAN
#define HART_NAN           ((float)0x7FA00000)
#endif
#define HART_PREAMBLE      0xFFu
#define HART_TIME_1MS      32      // 1 bit = 1/32ms
#define HART_TIME_1SEC     ((HART_TIME_1MS) * (MSEC_PER_SEC))

#define HART_DEFAULT_RETRIES     ((uint8_t)3)
#define HART_ENUM_EXPANSION      ((uint8_t)254)
#define HART_PROTOCOL_MAJ_REV    ((uint8_t)7)

/* Command Response Codes (Spec 307) */
#define RC_SUCCESS               ((uint8_t)0)
#define RC_INVALID               ((uint8_t)2) /*Invalid Selection */
#define RC_TOO_LRG               ((uint8_t)3) /* Passed parameter too large */
#define RC_TOO_SML               ((uint8_t)4) /* Passed parameter too small */
#define RC_TOO_FEW               ((uint8_t)5) /* too few data bytes */
#define RC_DEV_SPEC              ((uint8_t)6) /* Device Specific Command Error */
#define RC_WRT_PROT              ((uint8_t)7) /* in Write Protect Mode */
#define RC_WARN_8                ((uint8_t)8)	/* Multiple meanings WARN*/
#define RC_MULTIPLE_9            ((uint8_t)9)	/* Multiple meanings LRV too hi */
#define RC_MULTIPLE_10           ((uint8_t)10)	/* Multiple meanings LRV too lo*/
#define RC_MULTIPLE_11           ((uint8_t)11)	/* Multiple meanings URV too hi*/
#define RC_MULTIPLE_12           ((uint8_t)12)	/* Multiple meanings URV too lo*/
#define RC_MULTIPLE_13           ((uint8_t)13)	/* Multiple meanings Both Outa limits*/
#define RC_WARN_14               ((uint8_t)14)	/* Multiple meanings WARN*/
#define RC_ACC_RESTR             ((uint8_t)16) /* Access restricted */
#define RC_BAD_INDEX             ((uint8_t)17) /* Invalid deviceVar Index */
#define RC_BAD_UNITS             ((uint8_t)18) /* Invalid Units Code */
#define RC_INDEX_DISALLOWED      ((uint8_t)19) /* Device Variable Index not allowed????dup of 17 */
#define RC_BAD_EXT_CMD           ((uint8_t)20) /* Invalid extended command number */
#define RC_TRUNCATED             ((uint8_t)30) /* (Warning) ResponseTruncated */
#define RC_BUSY                  ((uint8_t)32)
#define RC_DR_INIT               ((uint8_t)33)
#define RC_DR_RUNNING            ((uint8_t)34)
#define RC_DR_DEAD               ((uint8_t)35)
#define RC_DR_CONFL              ((uint8_t)36)
#define RC_NOT_IMPLEM            ((uint8_t)64)

#define RC_UNDEFINED           ((uint8_t)255) /* Useful for init/err chking */


/* HART other defs */
#define HART_NOT_CLASFD			 ((uint8_t)0)
#define HART_UNITCODE_NOT_USED   ((uint8_t)250)
#define HART_NOT_USED            ((uint8_t)250)/* hart standard not-used value*/
#define HART_DEVICESTAT_NOT_USED ((uint8_t)48)


#endif /* _HARTDEFS_H */
