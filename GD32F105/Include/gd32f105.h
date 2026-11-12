/**************************************************************************//**
 * @file     gd32f105.h
 * @brief    CMSIS-Core(M) Device Header File for Device GD32F105
 *
 * @version  V1.0.0
 * @date     18. July 2023
 ******************************************************************************/
/*
 * Copyright (c) 2009-2023 Arm Limited. All rights reserved.
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

#ifndef GD32F105_H
#define GD32F105_H

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn
{
/* ================     Cortex-M Core Exception Numbers     ================ */

  Reset_IRQn             = -15,  /*  1 Reset Vector
                                       invoked on Power up and warm reset */
  NonMaskableInt_IRQn    = -14,  /*  2 Non maskable Interrupt
                                       cannot be stopped or preempted */
  HardFault_IRQn         = -13,  /*  3 Hard Fault
                                       all classes of Fault */
  MemoryManagement_IRQn  = -12,  /*  4 Memory Management
                                       MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn          = -11,  /*  5 Bus Fault
                                       Pre-Fetch-, Memory Access, other address/memory Fault */
  UsageFault_IRQn        = -10,  /*  6 Usage Fault
                                       i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn       =  -9,  /*  7 Secure Fault Interrupt */
  SVCall_IRQn            =  -5,  /* 11 System Service Call via SVC instruction */
  DebugMonitor_IRQn      =  -4,  /* 12 Debug Monitor */
  PendSV_IRQn            =  -2,  /* 14 Pendable request for system service */
  SysTick_IRQn           =  -1,  /* 15 System Tick Timer */

/* ================        GD32F105 Interrupt Numbers       ================ */

  WWDGT_IRQn             =   0, /* WWDGT interrupt */
  LVD_IRQn               =   1, /* LVD from EXTI interrupt */
  Tamper_IRQn            =   2, /* Tamper interrupt */
  RTC_IRQn               =   3, /* RTC global interrupt */
  FMC_IRQn               =   4, /* FMC global interrupt */
  RCU_IRQn               =   5, /* RCU global interrupt */
  EXTI0_IRQn             =   6, /* EXTI Line0 interrupt */
  EXTI1_IRQn             =   7, /* EXTI Line1 interrupt */
  EXTI2_IRQn             =   8, /* EXTI Line2 interrupt */
  EXTI3_IRQn             =   9, /* EXTI Line3 interrupt */
  EXTI4_IRQn             =  10, /* EXTI Line4 interrupt */
  DMA0_Channel0_IRQn     =  11, /* DMA0 channel0 global interrupt */
  DMA0_Channel1_IRQn     =  12, /* DMA0 channel1 global interrupt */
  DMA0_Channel2_IRQn     =  13, /* DMA0 channel2 global interrupt */
  DMA0_Channel3_IRQn     =  14, /* DMA0 channel3 global interrupt */
  DMA0_Channel4_IRQn     =  15, /* DMA0 channel4 global interrupt */
  DMA0_Channel5_IRQn     =  16, /* DMA0 channel5 global interrupt */
  DMA0_Channel6_IRQn     =  17, /* DMA0 channel6 global interrupt */
  ADC0_1_IRQn            =  18, /* ADC0 and ADC1 global interrupt */
  CAN0_TX_IRQn           =  19, /* CAN0 TX interrupts */
  CAN0_RX0_IRQn          =  20, /* CAN0 RX0 interrupts */
  CAN0_RX1_IRQn          =  21, /* CAN0 RX1 interrupts */
  CAN0_EWMC_IRQn         =  22, /* CAN0 EWMC interrupts */
  EXTI9_5_IRQn           =  23, /* EXTI line[9:5] interrupts */
  TIMER0_BRK_IRQn        =  24, /* TIMER0 break interrupt */
  TIMER0_UP_IRQn         =  25, /* TIMER0 update interrupt */
  TIMER0_TRIG_COMM_IRQn  =  26, /* TIMER0 trigger and channel commutation interrupts */
  TIMER0_CHANNEL_CC_IRQn =  27, /* TIMER0 channel capture compare interrupt */
  TIMER1_IRQn            =  28, /* TIMER1 global interrupt */
  TIMER2_IRQn            =  29, /* TIMER2 global interrupt */
  TIMER3_IRQn            =  30, /* TIMER3 global interrupt */
  I2C0_EV_IRQn           =  31, /* I2C0 event interrupt */
  I2C0_ER_IRQn           =  32, /* I2C0 error interrupt */
  I2C1_EV_IRQn           =  33, /* I2C1 event interrupt */
  I2C1_ER_IRQn           =  34, /* I2C1 error interrupt */
  SPI0_IRQn              =  35, /* SPI0 global interrupt */
  SPI1_IRQn              =  36, /* SPI0 global interrupt */
  USART0_IRQn            =  37, /* USART0 global interrupt */
  USART1_IRQn            =  38, /* USART1 global interrupt */
  USART2_IRQn            =  39, /* USART2 global interrupt */
  EXTI15_10_IRQn         =  40, /* EXTI line[15:10] interrupts */
  RTC_Alarm_IRQn         =  41, /* RTC alarm from EXTI interrupt */
  USBFS_WKUP_IRQn        =  42, /* USBFS wakeup from EXTI interrupt */
  TIMER7_BRK_IRQn        =  43, /* TIMER0 break interrupt */
  TIMER7_UP_IRQn         =  44, /* TIMER0 update interrupt */
  TIMER7_TRIG_COMM_IRQn  =  45, /* TIMER0 trigger and channel commutation interrupts */
  TIMER7_CHANNEL_CC_IRQn =  46, /* TIMER0 channel capture compare interrupt */
  EXMC_IRQn              =  48, /* EXMC global interrupt */
  TIMER4_IRQn            =  50, /* TIMER4 global interrupt */
  SPI2_IRQn              =  51, /* SPI2 global interrupt */
  UART3_IRQn             =  52, /* UART3 global interrupt */
  UART4_IRQn             =  53, /* UART4 global interrupt */
  TIMER5_IRQn            =  54, /* TIMER5 global interrupt */
  TIMER6_IRQn            =  55, /* TIMER6 global interrupt */
  DMA1_Channel0_IRQn     =  56, /* DMA1 channel0 global interrupt */
  DMA1_Channel1_IRQn     =  57, /* DMA1 channel1 global interrupt */
  DMA1_Channel2_IRQn     =  58, /* DMA1 channel2 global interrupt */
  DMA1_Channel3_IRQn     =  59, /* DMA1 channel3 global interrupt */
  DMA1_Channel4_IRQn     =  60, /* DMA1 channel4 global interrupt */
  ENET_IRQn              =  61, /* ENET global interrupt */
  ENET_WKUP_IRQn         =  62, /* ENET wakeup from EXTI interrupt */
  CAN1_TX_IRQn           =  63, /* CAN0 TX interrupts */
  CAN1_RX0_IRQn          =  64, /* CAN0 RX0 interrupts */
  CAN1_RX1_IRQn          =  65, /* CAN0 RX1 interrupts */
  CAN1_EWMC_IRQn         =  66, /* CAN0 EWMC interrupts */
  USBFS_IRQn             =  67, /* USBFS global interrupt */
} IRQn_Type;


/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */

#define __CM3_REV               0x0201U  /* Core Revision r2p1 */

#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        4U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          1U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           0U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           0U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           0U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     0U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           0U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      8U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        0U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        0U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */

#include <core_cm3.h>                           /* Processor and core peripherals */
#include "system_gd32f105.h"                    /* System Header */



/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */

/*--------------------------------------------------------------------------------------------------------*/
/*---Memory density information---------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
typedef struct {
  __IM uint16_t FLASH_DENSITY;  // The value indicates the Flash memory density of the device in Kbytes.
  __IM uint16_t SRAM_DENSITY;   // The value indicates the on-chip SRAM density of the device in Kbytes.
} MEMORY_DENSITY_INFO_TypeDef;


/*--------------------------------------------------------------------------------------------------------*/
/*---Unique device ID (96 bits)---------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
typedef struct {
  __IM uint32_t U_ID31_0;
  __IM uint32_t U_ID63_32;
  __IM uint32_t U_ID95_64;
} UniqueDeviceID_TypeDef;

/*--------------------------------------------------------------------------------------------------------*/
/*---Flash memory controller (FMC)------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
typedef struct {
  __IOM uint32_t WS;        // Wait state register (FMC_WS)
  __OM  uint32_t KEY0;      // Unlock key register 0 (FMC_KEY0)
  __OM  uint32_t OBKEY;     // Option byte unlock key register (FMC_OBKEY)
  __IOM uint32_t STAT0;     // Status register 0 (FMC_STAT0)

  __IOM uint32_t CTL0;      // Control register 0 (FMC_CTL0)
  __OM  uint32_t ADDR0;     // Address register 0 (FMC_ADDR0)
  __IM  uint32_t __UNUSED0;
  __IM  uint32_t OBSTAT;    // Option byte status register (FMC_OBSTAT)
  
  __IM  uint32_t WP;        // Erase/Program Protection register (FMC_WP)
  __IM  uint32_t __UNUSED1[(0x44-0x24)/4];
  __OM  uint32_t KEY1;      // Unlock key register 1(FMC_KEY1)
  __IM  uint32_t __UNUSED2;
  __IOM uint32_t STAT1;     // Status register 1 (FMC_STAT1)
  __IOM uint32_t CTL1;      // Control register 1 (FMC_CTL1)
  __OM  uint32_t ADDR1;     // Address register 000FMC_ADDR1)
  __IM  uint32_t __UNUSED3[41];
  __IOM uint32_t WSEN;      // Wait state enable register (FMC_WSEN)
  __IM  uint32_t PID;       // Product ID register (FMC_PID)
} FMC_TypeDef;

// Wait state register (FMC_WS)
#define FMC_WS_WSCNT_Msk          (7UL)
#define FMC_WS_WSCNT_0            (0UL)   // 0 wait state added
#define FMC_WS_WSCNT_1            (1UL)   // 1 wait state added
#define FMC_WS_WSCNT_2            (2UL)   // 2 wait state added

// Status register 0,1 (FMC_STAT0, FMC_STAT1)
#define FMC_STAT0_ENDF            (1<<5)  // End of operation flag bit
#define FMC_STAT0_WPERR           (1<<4)  // Erase/Program protection error flag bit
#define FMC_STAT0_PGERR           (1<<2)  // Program error flag bit
#define FMC_STAT0_BUSY            (1<<0)  // The flash busy bit
#define FMC_STAT1_ENDF            (1<<5)  // End of operation flag bit
#define FMC_STAT1_WPERR           (1<<4)  // Erase/Program protection error flag bit
#define FMC_STAT1_PGERR           (1<<2)  // Program error flag bit
#define FMC_STAT1_BUSY            (1<<0)  // The flash busy bit


// Control register 0,1 (FMC_CTL0, FMC_CTL1)
#define FMC_CTL0_ENDIE            (1<<12) // End of operation interrupt enable bit
#define FMC_CTL1_ENDIE            (1<<12) // End of operation interrupt enable bit
#define FMC_CTL0_ERRIE            (1<<10) // Error interrupt enable bit
#define FMC_CTL1_ERRIE            (1<<10) // Error interrupt enable bit
#define FMC_CTL0_OBWEN            (1<<9)  // Option byte erase/program enable bit
#define FMC_CTL0_LK               (1<<7)  // FMC_CTL0 lock bit
#define FMC_CTL1_LK               (1<<7)  // FMC_CTL1 lock bit
#define FMC_CTL0_START            (1<<6)  // Send erase command to FMC bit
#define FMC_CTL1_START            (1<<6)  // Send erase command to FMC bit
#define FMC_CTL0_OBER             (1<<5)  // Option bytes erase command bit
#define FMC_CTL0_OBPG             (1<<4)  // Option bytes program command bit
#define FMC_CTL0_MER              (1<<2)  // Main flash mass erase for bank0 command bit
#define FMC_CTL1_MER              (1<<2)  // Main flash mass erase for bank1 command bit
#define FMC_CTL0_PER              (1<<1)  // Main flash page erase for bank0 command bit
#define FMC_CTL1_PER              (1<<1)  // Main flash page erase for bank1 command bit
#define FMC_CTL0_PG               (1<<0)  // Main flash program for bank0 command bit
#define FMC_CTL1_PG               (1<<0)  // Main flash program for bank1 command bit

// Option byte status register (FMC_OBSTAT)
#define FMC_OBSTAT_DATA           (0xFFFFUL<<10)  // Store DATA of option bytes block after system reset.
#define FMC_OBSTAT_USER           (0xFFUL<<2)     // Store USER of option bytes block after system reset.
#define FMC_OBSTAT_SPC            (1<<1)          // Option bytes security protection code
#define FMC_OBSTAT_OBERR          (1<<0)          // Option bytes read error bit.

// Wait state enable register (FMC_WSEN)
#define FMC_WSEN_WSEN             (1UL)           // FMC wait state enable register

/* ToDo: add here your device specific peripheral access structure typedefs
         including bit definitions for Pos/Msk macros
         following is an example for a timer */

/* ========================================================================= */
/* ============                       TMR                       ============ */
/* ========================================================================= */

// typedef struct
// {
//   __IOM uint32_t  LOAD;                 /* Offset: 0x000 (R/W) Load Register */
//   __IM  uint32_t  VALUE;                /* Offset: 0x004 (R/ ) Value Register */
//   __IOM uint32_t  CONTROL;              /* Offset: 0x008 (R/W) Control Register */
//   __OM  uint32_t  INTCLR;               /* Offset: 0x00C ( /W) Clear Interrupt Register */
//   __IM  uint32_t  RIS;                  /* Offset: 0x010 (R/ ) Raw Interrupt Status Register */
//   __IM  uint32_t  MIS;                  /* Offset: 0x014 (R/ ) Interrupt Status Register */
//   __IOM uint32_t  BGLOAD;               /* Offset: 0x018 (R/W) Background Load Register */
// } <DeviceAbbreviation>_TMR_TypeDef;

// /* <DeviceAbbreviation>_TMR LOAD Register Definitions */
// #define <DeviceAbbreviation>_TMR_LOAD_Pos              0
// #define <DeviceAbbreviation>_TMR_LOAD_Msk             (0xFFFFFFFFUL /*<< <DeviceAbbreviation>_TMR_LOAD_Pos*/)

// /* <DeviceAbbreviation>_TMR VALUE Register Definitions */
// #define <DeviceAbbreviation>_TMR_VALUE_Pos             0
// #define <DeviceAbbreviation>_TMR_VALUE_Msk            (0xFFFFFFFFUL /*<< <DeviceAbbreviation>_TMR_VALUE_Pos*/)

// /* <DeviceAbbreviation>_TMR CONTROL Register Definitions */
// #define <DeviceAbbreviation>_TMR_CONTROL_SIZE_Pos      1
// #define <DeviceAbbreviation>_TMR_CONTROL_SIZE_Msk     (1UL << <DeviceAbbreviation>_TMR_CONTROL_SIZE_Pos)

// #define <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Pos   0
// #define <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Msk  (1UL /*<< <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Pos*/)



/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */

#define EXMC_SWREG_BASE                         (0xA0000000UL)                                /* EXMC - SWREG base address */
#define EXMC_PC_CARD_BASE                       (0x90000000UL)                                /* EXMC - PC CARD base address */
#define EXMC_NAND_BASE                          (0x70000000UL)                                /* EXMC - NAND base address */
#define EXMC_NOR_BASE                           (0x60000000UL)                                /* EXMC - NOR base address */
#define EXMC_PSRAM_BAS                          (0x60000000UL)                                /* EXMC - PSRAM base address */
#define EXMC_SRAM_BASE                          (0x60000000UL)                                /* EXMC - SRAM base address */

#define SRAM_BASE                               (0x20000000UL)
#define MAIN_FLASH_BASE                         (0x08000000UL)

#define BOOT_LOADER_BASE                        (0x1FFFB000UL)
#define OPTION_BYTES_BASE                       (0x1FFFF800UL)

#define USBFS_BASE                              (0x50000000UL)
#define ENET_BASE                               (0x40028000UL)
#define CRC_BASE                                (0x40023000UL)
#define FMC_BASE                                (0x40022000UL)
#define RCU_BASE                                (0x40021000UL)
#define DMA1_BASE                               (0x40020400UL)
#define DMA0_BASE                               (0x40020000UL)
#define SDIO_BASE                               (0x40018000UL)

#define APB1_BASE                               (0x40000000UL)
#define APB2_BASE                               (0x40010000UL)

#define AFIO_BASE                               (APB2_BASE + 0x0000UL)
#define EXTI_BASE                               (APB2_BASE + 0x0400UL)
#define GPIOA_BASE                              (APB2_BASE + 0x0800UL)
#define GPIOB_BASE                              (APB2_BASE + 0x0C00UL)
#define GPIOC_BASE                              (APB2_BASE + 0x1000UL)
#define GPIOD_BASE                              (APB2_BASE + 0x1400UL)
#define GPIOE_BASE                              (APB2_BASE + 0x1800UL)
#define GPIOF_BASE                              (APB2_BASE + 0x1C00UL)
#define GPIOG_BASE                              (APB2_BASE + 0x2000UL)
#define ADC0_BASE                               (APB2_BASE + 0x2400UL)
#define ADC1_BASE                               (APB2_BASE + 0x2800UL)
#define TIMER0_BASE                             (APB2_BASE + 0x2C00UL)
#define SPI0_BASE                               (APB2_BASE + 0x3000UL)
#define TIMER7_BASE                             (APB2_BASE + 0x3400UL)
#define USART0_BASE                             (APB2_BASE + 0x3800UL)
#define ADC2_BASE                               (APB2_BASE + 0x3C00UL)
#define TIMER8_BASE                             (APB2_BASE + 0x4C00UL)
#define TIMER9_BASE                             (APB2_BASE + 0x5000UL)
#define TIMER10_BASE                            (APB2_BASE + 0x5400UL)

#define TIMER1_BASE                             (APB1_BASE + 0x0000UL)
#define TIMER2_BASE                             (APB1_BASE + 0x0400UL)
#define TIMER3_BASE                             (APB1_BASE + 0x0800UL)
#define TIMER4_BASE                             (APB1_BASE + 0x0C00UL)
#define TIMER5_BASE                             (APB1_BASE + 0x1000UL)
#define TIMER6_BASE                             (APB1_BASE + 0x1400UL)
#define TIMER11_BASE                            (APB1_BASE + 0x1800UL)
#define TIMER12_BASE                            (APB1_BASE + 0x1C00UL)
#define TIMER13_BASE                            (APB1_BASE + 0x2000UL)
#define RTC_BASE                                (APB1_BASE + 0x2800UL)
#define WWDGT_BASE                              (APB1_BASE + 0x2C00UL)
#define FWDGT_BASE                              (APB1_BASE + 0x3000UL)
#define SPI1_BASE                               (APB1_BASE + 0x3800UL)
#define SPI2_BASE                               (APB1_BASE + 0x3C00UL)
#define USART1_BASE                             (APB1_BASE + 0x4400UL)
#define USART2_BASE                             (APB1_BASE + 0x4800UL)
#define UART3_BASE                              (APB1_BASE + 0x4C00UL)
#define UART4_BASE                              (APB1_BASE + 0x5000UL)
#define I2C0_BASE                               (APB1_BASE + 0x5400UL)
#define I2C1_BASE                               (APB1_BASE + 0x5800UL)
#define USBD_BASE                               (APB1_BASE + 0x5C00UL)
#define CAN0_BASE                               (APB1_BASE + 0x6400UL)
#define CAN1_BASE                               (APB1_BASE + 0x6800UL)
#define BKP_BASE                                (APB1_BASE + 0x6C00UL)
#define PMU_BASE                                (APB1_BASE + 0x7000UL)
#define DAC_BASE                                (APB1_BASE + 0x7400UL)





/* ========================================================================= */
/* ============             Peripheral declaration              ============ */
/* ========================================================================= */


/* ToDo: Add here your device peripherals pointer definitions
         following is an example for timer */

// #define <DeviceAbbreviation>_TIM0        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM1        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM2        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)

#define MEMORY_DENSITY_INFO     ((MEMORY_DENSITY_INFO_TypeDef*) 0x1FFFF7E0UL)
#define U_DEV_ID                ((UniqueDeviceID_TypeDef*)      0x1FFFF7E8UL)

#define FMC                     ((FMC_TypeDef*)                     FMC_BASE)

#ifdef __cplusplus
}
#endif

#endif  /* GD32F105_H */
