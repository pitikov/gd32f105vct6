/******************************************************************************
 * @file     startup_gd32f105.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device GD32F105
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
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

#include "gd32f105.h"

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler                  (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void HardFault_Handler            (void) __attribute__ ((weak, noreturn));
void MemManage_Handler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void BusFault_Handler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void UsageFault_Handler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SecureFault_Handler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SVC_Handler                  (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DebugMon_Handler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void PendSV_Handler               (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SysTick_Handler              (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));

/* GD32F105xx device specific interrupt handlers */
void WWDGT_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void LVD_IRQHandler               (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void Tamper_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void RTC_IRQHandler               (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void FMC_IRQHandler               (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void RCU_IRQHandler               (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI0_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI1_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI2_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI3_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI4_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel0_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel1_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel2_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel3_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel4_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel5_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA0_Channel6_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void ADC0_1_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN0_TX_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN0_RX0_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN0_RX1_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN0_EWMC_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI9_5_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER0_BRK_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER0_UP_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER0_TRIG_COMM_IRQHandler  (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER0_CHANNEL_CC_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER1_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER2_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER3_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C0_EV_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C0_ER_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C1_EV_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C1_ER_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SPI0_IRQHandler              (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SPI1_IRQHandler              (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USART0_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USART1_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USART2_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI15_10_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void RTC_Alarm_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USBFS_WKUP_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER7_BRK_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER7_UP_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER7_TRIG_COMM_IRQHandler  (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER7_CHANNEL_CC_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXMC_IRQHandler              (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER4_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SPI2_IRQHandler              (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void UART3_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void UART4_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER5_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIMER6_IRQHandler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel0_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void ENET_IRQHandler              (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void ENET_WKUP_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN1_TX_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN1_RX0_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN1_RX1_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN1_EWMC_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USBFS_IRQHandler             (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[84];
       const VECTOR_TABLE_Type __VECTOR_TABLE[84] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /*     Initial Stack Pointer */
  Reset_Handler,                       /*     Reset Handler */
  NMI_Handler,                         /* -14 NMI Handler */
  HardFault_Handler,                   /* -13 Hard Fault Handler */
  MemManage_Handler,                   /* -12 MPU Fault Handler */
  BusFault_Handler,                    /* -11 Bus Fault Handler */
  UsageFault_Handler,                  /* -10 Usage Fault Handler */
  SecureFault_Handler,                 /*  -9 Secure Fault Handler */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  SVC_Handler,                         /*  -5 SVCall Handler */
  DebugMon_Handler,                    /*  -4 Debug Monitor Handler */
  0,                                   /*     Reserved */
  PendSV_Handler,                      /*  -2 PendSV Handler */
  SysTick_Handler,                     /*  -1 SysTick Handler */

/* ToDo: Add your device specific interrupt vectors */
  WWDGT_IRQHandler,                    /*   0 WWDGT interrupt */
  LVD_IRQHandler,                      /*   1 LVD from EXTI interrupt */
  Tamper_IRQHandler,                   /*   2 Tamper interrupt */
  RTC_IRQHandler,                      /*   3 RTC global interrupt */
  FMC_IRQHandler,                      /*   4 FMC global interrupt */
  RCU_IRQHandler,                      /*   5 RCU global interrupt */
  EXTI0_IRQHandler,                    /*   6 EXTI Line0 interrupt */
  EXTI1_IRQHandler,                    /*   7 EXTI Line1 interrupt */
  EXTI2_IRQHandler,                    /*   8 EXTI Line2 interrupt */
  EXTI3_IRQHandler,                    /*   9 EXTI Line3 interrupt */
  EXTI4_IRQHandler,                    /*  10 EXTI Line4 interrupt */
  DMA0_Channel0_IRQHandler,            /*  11 DMA0 channel0 global interrupt */
  DMA0_Channel1_IRQHandler,            /*  12 DMA0 channel1 global interrupt */
  DMA0_Channel2_IRQHandler,            /*  13 DMA0 channel2 global interrupt */
  DMA0_Channel3_IRQHandler,            /*  14 DMA0 channel3 global interrupt */
  DMA0_Channel4_IRQHandler,            /*  15 DMA0 channel4 global interrupt */
  DMA0_Channel5_IRQHandler,            /*  16 DMA0 channel5 global interrupt */
  DMA0_Channel6_IRQHandler,            /*  17 DMA0 channel6 global interrupt */
  ADC0_1_IRQHandler,                   /*  18 ADC0 and ADC1 global interrupt */
  CAN0_TX_IRQHandler,                  /*  19 CAN0 TX interrupts */
  CAN0_RX0_IRQHandler,                 /*  20 CAN0 RX0 interrupts */
  CAN0_RX1_IRQHandler,                 /*  21 CAN0 RX1 interrupts */
  CAN0_EWMC_IRQHandler,                /*  22 CAN0 EWMC interrupts */
  EXTI9_5_IRQHandler,                  /*  23 EXTI line[9:5] interrupts */
  TIMER0_BRK_IRQHandler,               /*  24 TIMER0 break interrupt */
  TIMER0_UP_IRQHandler,                /*  25 TIMER0 update interrupt */
  TIMER0_TRIG_COMM_IRQHandler,         /*  26 TIMER0 trigger and channel commutation interrupts */
  TIMER0_CHANNEL_CC_IRQHandler,        /*  27 TIMER0 channel capture compare interrupt */
  TIMER1_IRQHandler,                   /*  28 TIMER1 global interrupt */
  TIMER2_IRQHandler,                   /*  29 TIMER2 global interrupt */
  TIMER3_IRQHandler,                   /*  30 TIMER3 global interrupt */
  I2C0_EV_IRQHandler,                  /*  31 I2C0 event interrupt */
  I2C0_ER_IRQHandler,                  /*  32 I2C0 error interrupt */
  I2C1_EV_IRQHandler,                  /*  33 I2C1 event interrupt */
  I2C1_ER_IRQHandler,                  /*  34 I2C1 error interrupt */
  SPI0_IRQHandler,                     /*  35 SPI0 global interrupt */
  SPI1_IRQHandler,                     /*  36 SPI0 global interrupt */
  USART0_IRQHandler,                   /*  37 USART0 global interrupt */
  USART1_IRQHandler,                   /*  38 USART1 global interrupt */
  USART2_IRQHandler,                   /*  39 USART2 global interrupt */
  EXTI15_10_IRQHandler,                /*  40 EXTI line[15:10] interrupts */
  RTC_Alarm_IRQHandler,                /*  41 RTC alarm from EXTI interrupt */
  USBFS_WKUP_IRQHandler,               /*  42 USBFS wakeup from EXTI interrupt */
  TIMER7_BRK_IRQHandler,               /*  43 TIMER0 break interrupt */
  TIMER7_UP_IRQHandler,                /*  44 TIMER0 update interrupt */
  TIMER7_TRIG_COMM_IRQHandler,         /*  45 TIMER0 trigger and channel commutation interrupts */
  TIMER7_CHANNEL_CC_IRQHandler,        /*  46 TIMER0 channel capture compare interrupt */
  0x00000000UL,
  EXMC_IRQHandler,                     /*  48 EXMC global interrupt */
  0x00000000UL,
  TIMER4_IRQHandler,                   /*  50 TIMER4 global interrupt */
  SPI2_IRQHandler,                     /*  51 SPI2 global interrupt */
  UART3_IRQHandler,                    /*  52 UART3 global interrupt */
  UART4_IRQHandler,                    /*  53 UART4 global interrupt */
  TIMER5_IRQHandler,                   /*  54 TIMER5 global interrupt */
  TIMER6_IRQHandler,                   /*  55 TIMER6 global interrupt */
  DMA1_Channel0_IRQHandler,            /*  56 DMA1 channel0 global interrupt */
  DMA1_Channel1_IRQHandler,            /*  57 DMA1 channel1 global interrupt */
  DMA1_Channel2_IRQHandler,            /*  58 DMA1 channel2 global interrupt */
  DMA1_Channel3_IRQHandler,            /*  59 DMA1 channel3 global interrupt */
  DMA1_Channel4_IRQHandler,            /*  60 DMA1 channel4 global interrupt */
  ENET_IRQHandler,                     /*  61 ENET global interrupt */
  ENET_WKUP_IRQHandler,                /*  62 ENET wakeup from EXTI interrupt */
  CAN1_TX_IRQHandler,                  /*  63 CAN0 TX interrupts */
  CAN1_RX0_IRQHandler,                 /*  64 CAN0 RX0 interrupts */
  CAN1_RX1_IRQHandler,                 /*  65 CAN0 RX1 interrupts */
  CAN1_EWMC_IRQHandler,                /*  66 CAN0 EWMC interrupts */
  USBFS_IRQHandler,                    /*  67 USBFS global interrupt */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  __set_PSP((uint32_t)(&__INITIAL_SP));

  SystemInit();                    /* CMSIS System Initialization */
  __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
