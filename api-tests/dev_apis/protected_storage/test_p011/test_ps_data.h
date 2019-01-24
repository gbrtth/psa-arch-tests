/** @file
 * Copyright (c) 2019, Arm Limited or ps affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/
#ifndef _TEST_P011_PS_DATA_TESTS_H_
#define _TEST_P011_PS_DATA_TESTS_H_

#include "val_protected_storage.h"

#define SST_FUNCTION val->ps_function

typedef struct {
    char                   test_desc[100];
    enum ps_function_code  api;
    psa_ps_status_t        status;
} test_data;

static test_data p011_data[] = {
{
 "Check if optional PS api supported", VAL_PS_GET_SUPPORT, PSA_PS_SUPPORT_SET_EXTENDED
},
{
 "Create valid storage", VAL_PS_CREATE, PSA_PS_SUCCESS
},
{
 "Set data using set_extended api", VAL_PS_SET_EXTENDED, PSA_PS_SUCCESS
},
{
 "Set_extended call with invalid offset + length", VAL_PS_SET_EXTENDED, PSA_PS_ERROR_OFFSET_INVALID
},
{
 "Set_extended call with invalid offset", VAL_PS_SET_EXTENDED, PSA_PS_ERROR_OFFSET_INVALID
},
{
 "Set_extended call with valid offset and zero length", VAL_PS_SET_EXTENDED, PSA_PS_SUCCESS
},
{
 "Set_extended call with invalid offset + length", VAL_PS_SET_EXTENDED, PSA_PS_ERROR_OFFSET_INVALID
},
{
 "Set_extended call with invalid length", VAL_PS_SET_EXTENDED, PSA_PS_ERROR_OFFSET_INVALID
},
{
 "Write data using set api", VAL_PS_SET, PSA_PS_SUCCESS
},
{
 "Check data validity using get api", VAL_PS_GET, PSA_PS_SUCCESS
},
{
 "This is dummy for index10", 0, 0
},
{
 "Set_extended call with NULL write buffer", VAL_PS_SET_EXTENDED, PSA_PS_ERROR_BAD_POINTER
},
{
 "Overwrite data using set_extended", VAL_PS_SET_EXTENDED, PSA_PS_SUCCESS
},
{
 "Check data validity using get api", VAL_PS_GET, PSA_PS_SUCCESS
},
{
 "This is dummy for index14", 0, 0
},
{
 "Remove the uid", VAL_PS_REMOVE, PSA_PS_SUCCESS
},
};
#endif /* _TEST_P011_PS_DATA_TESTS_H_ */
