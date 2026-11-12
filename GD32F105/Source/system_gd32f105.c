/*************************************************************************//**
 * @file     system_gd32f105.c
 * @brief    CMSIS-Core(M) Device Peripheral Access Layer Source File for
 *           Device GD32F105
 * @version  V1.0.0
 * @date     20. January 2021
 *****************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include "gd32f105.h"

/* ToDo: Include partition header file if TZ is used */
#if defined (__ARM_FEATURE_CMSE) &&  (__ARM_FEATURE_CMSE == 3U)
  #include "partition_gd32f105.h"
#endif


/*---------------------------------------------------------------------------
  Define clocks
 *---------------------------------------------------------------------------*/

 #ifdef __HXTAL_VALUE
 #define HXTAL_VALUE __HXTAL_VALUE  // External high-speed oscilator
 #else
 #error HXTAL_VALUE not defined
 #endif // __HXTAL_VALUE

 #ifdef __LXTAL_VALUE
 #define LXTAL_VALUE __LXTAL_VALUE  // External low-speed clock oscilator
 #else
 #error LXTAL_VALUE not defined
 #endif // __LXTAL_VALUE

 #define IRC8M          8000000     // Internal 8MHz oscilator
 #define IRC40K         40000       // Internal 40KHz oscilator

 #define SYSTEM_CLOCK   IRC8M

/*---------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *---------------------------------------------------------------------------*/
extern const VECTOR_TABLE_Type __VECTOR_TABLE[496];


/*---------------------------------------------------------------------------
  System Core Clock Variable
 *---------------------------------------------------------------------------*/
/* ToDo: Initialize SystemCoreClock with the system core clock frequency value
         achieved after system intitialization.
         This means system core clock frequency after call to SystemInit() */
uint32_t SystemCoreClock = SYSTEM_CLOCK;  /* System Clock Frequency (Core Clock)*/


/*---------------------------------------------------------------------------
  System Core Clock function
 *---------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)
{
/* ToDo: Add code to calculate the system frequency based upon the current
         register settings.
         This function can be used to retrieve the system core clock frequeny
         after user changed register sittings. */
  SystemCoreClock = SYSTEM_CLOCK;
}


/*---------------------------------------------------------------------------
  System initialization function
 *---------------------------------------------------------------------------*/
void SystemInit (void)
{
/* ToDo: Add code to initialize the system.
         Do not use global variables because this function is called before
         reaching pre-main. RW section maybe overwritten afterwards. */

/* ToDo: Initialize VTOR if available */
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  SCB->VTOR = (uint32_t)(&__VECTOR_TABLE[0]);
#endif

  SystemCoreClock = SYSTEM_CLOCK;
}

/*---------------------------------------------------------------------------
  Решение проблеммы выхода приложения за исполняемый код при завершении 
  функции main
 *---------------------------------------------------------------------------*/
void main_venir(void) {
  extern int main(void);

  main();

  // Dead-loop цикл-ловушка по завершению основного тела программы
  while (1)
    __WFI();
}