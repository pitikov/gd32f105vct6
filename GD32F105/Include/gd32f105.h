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

/*--------------------------------------------------------------------------------------------------------*/
/*---Power management unit (PMU)--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
typedef struct {
  __IOM   uint32_t  CTL;    // Control register (PMU_CTL)
  __IOM   uint32_t  CS;     // Control and status register (PMU_CS)
} PMU_TypeDef;

// Control register (PMU_CTL)
#define PMU_CTL_BKPWEN      (1<<8)  // Backup Domain Write Enable
#define PMU_CTL_LVDT_Msk    (7<<5)  // Low Voltage Detector Threshold
#define PMU_CTL_LVDEN       (1<<4)  // Low Voltage Detector Enable
#define PMU_CTL_STBRST      (1<<3)  // Standby Flag Reset
#define PMU_CTL_WURST       (1<<2)  // Wakeup Flag Reset
#define PMU_CTL_STBMOD      (1<<1)  // Standby Mode
#define PMU_CTL_LDOLP       (1<<0)  // LDO Low Power Mode

#define PMU_CTL_LVDT_2v2    (0<<5)  // Low Voltage Detector Threshold 2.2V
#define PMU_CTL_LVDT_2v3    (1<<5)  // Low Voltage Detector Threshold 2.3V
#define PMU_CTL_LVDT_2v4    (2<<5)  // Low Voltage Detector Threshold 2.4V
#define PMU_CTL_LVDT_2v5    (3<<5)  // Low Voltage Detector Threshold 2.5V
#define PMU_CTL_LVDT_2v6    (4<<5)  // Low Voltage Detector Threshold 2.6V
#define PMU_CTL_LVDT_2v7    (5<<5)  // Low Voltage Detector Threshold 2.7V
#define PMU_CTL_LVDT_2v8    (6<<5)  // Low Voltage Detector Threshold 2.8V
#define PMU_CTL_LVDT_2v9    (7<<5)  // Low Voltage Detector Threshold 2.9V

// Control and status register (PMU_CS)
#define PMU_CS_WUPEN        (1<<8)  // WKUP Pin Enable
#define PMU_CS_LVDF         (1<<2)  // Low Voltage Detector Status Flag
#define PMU_CS_STBF         (1<<1)  // Standby Flag
#define PMU_CS_WUF          (1<<0)  // Wakeup Flag

/*--------------------------------------------------------------------------------------------------------*/
/*---Backup registers (BKP)-------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
typedef struct {
  __IM  uint32_t __unused_0;
  __IOM uint16_t DATA0;
  __IM  uint16_t __unused0;
  __IOM uint16_t DATA1;
  __IM  uint16_t __unused1;
  __IOM uint16_t DATA2;
  __IM  uint16_t __unused2;
  __IOM uint16_t DATA3;
  __IM  uint16_t __unused3;
  __IOM uint16_t DATA4;
  __IM  uint16_t __unused4;
  __IOM uint16_t DATA5;
  __IM  uint16_t __unused5;
  __IOM uint16_t DATA6;
  __IM  uint16_t __unused6;
  __IOM uint16_t DATA7;
  __IM  uint16_t __unused7;
  __IOM uint16_t DATA8;
  __IM  uint16_t __unused8;
  __IOM uint16_t DATA9;
  __IM  uint16_t __unused9;
  __IOM uint16_t OCTL;    // RTC signal output control register (BKP_OCTL)
  __IM  uint16_t __unused_octl;
  __IOM uint16_t TPCTL;   // Tamper pin control register (BKP_TPCTL)
  __IM  uint16_t __unused_tpctl;
  __IOM uint16_t TPCS;    // Tamper control and status register (BKP_TPCS)
  __IM  uint16_t __unused_tpcs;
  __IM  uint32_t __unused_1[2];
  __IOM uint16_t DATA10;
  __IM  uint16_t __unused10;
  __IOM uint16_t DATA11;
  __IM  uint16_t __unused11;
  __IOM uint16_t DATA12;
  __IM  uint16_t __unused12;
  __IOM uint16_t DATA13;
  __IM  uint16_t __unused13;
  __IOM uint16_t DATA14;
  __IM  uint16_t __unused14;
  __IOM uint16_t DATA15;
  __IM  uint16_t __unused15;
  __IOM uint16_t DATA16;
  __IM  uint16_t __unused16;
  __IOM uint16_t DATA17;
  __IM  uint16_t __unused17;
  __IOM uint16_t DATA18;
  __IM  uint16_t __unused18;
  __IOM uint16_t DATA19;
  __IM  uint16_t __unused19;
  __IOM uint16_t DATA20;
  __IM  uint16_t __unused20;
  __IOM uint16_t DATA21;
  __IM  uint16_t __unused21;
  __IOM uint16_t DATA22;
  __IM  uint16_t __unused22;
  __IOM uint16_t DATA23;
  __IM  uint16_t __unused23;
  __IOM uint16_t DATA24;
  __IM  uint16_t __unused24;
  __IOM uint16_t DATA25;
  __IM  uint16_t __unused25;
  __IOM uint16_t DATA26;
  __IM  uint16_t __unused26;
  __IOM uint16_t DATA27;
  __IM  uint16_t __unused27;
  __IOM uint16_t DATA28;
  __IM  uint16_t __unused28;
  __IOM uint16_t DATA29;
  __IM  uint16_t __unused29;
  __IOM uint16_t DATA30;
  __IM  uint16_t __unused30;
  __IOM uint16_t DATA31;
  __IM  uint16_t __unused31;
  __IOM uint16_t DATA32;
  __IM  uint16_t __unused32;
  __IOM uint16_t DATA33;
  __IM  uint16_t __unused33;
  __IOM uint16_t DATA34;
  __IM  uint16_t __unused34;
  __IOM uint16_t DATA35;
  __IM  uint16_t __unused35;
  __IOM uint16_t DATA36;
  __IM  uint16_t __unused36;
  __IOM uint16_t DATA37;
  __IM  uint16_t __unused37;
  __IOM uint16_t DATA38;
  __IM  uint16_t __unused38;
  __IOM uint16_t DATA39;
  __IM  uint16_t __unused39;
  __IOM uint16_t DATA40;
  __IM  uint16_t __unused40;
  __IOM uint16_t DATA41;
  __IM  uint16_t __unused41;
} BKP_TypeDef;

// RTC signal output control register (BKP_OCTL)
#define BKP_OCTL_ROSEL      (1<<9)    // RTC output selection
#define BKP_OCTL_ASOEN      (1<<8)    // RTC alarm or second signal output enable
#define BKP_OCTL_COEN       (1<<7)    // RTC clock calibration output enable
#define BKP_OCTL_RCCV       (0x7FUL)  // RTC clock calibration value

// Tamper pin control register (BKP_TPCTL)
#define BKP_TPCTL_TPAL      (1<<1)    // TAMPER pin active level
#define BKP_TPCTL_TPEN      (1<<0)    // TAMPER detection enable

// Tamper control and status register (BKP_TPCS)
#define BKP_TPCS_TIF        (1<<9)    // Tamper interrupt flag
#define BKP_TPCS_TEF        (1<<8)    // Tamper event flag
#define BKP_TPCS_TPIE       (1<<2)    // Tamper interrupt enable
#define BKP_TPCS_TIR        (1<<1)    // Tamper interrupt reset
#define BKP_TPCS_TER        (1<<0)    // Tamper event reset

/*--------------------------------------------------------------------------------------------------------*/
/*---Connectivity line devices: Reset and clock control unit (RCU)----------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/
typedef struct {
  __IOM   uint32_t    CTL;      // Control register (RCU_CTL)
  __IOM   uint32_t    CFG0;     // Clock configuration register 0 (RCU_CFG0)
  __IOM   uint32_t    INT;      // Clock interrupt register (RCU_INT)
  __IOM   uint32_t    APB2RST;  // APB2 reset register (RCU_APB2RST)
  __IOM   uint32_t    APB1RST;  // APB1 reset register (RCU_APB1RST)
  __IOM   uint32_t    AHBEN;    // AHB enable register (RCU_AHBEN)
  __IOM   uint32_t    APB2ENR;  // APB2 enable register (RCU_APB2EN)
  __IOM   uint32_t    APB1ENR;  // APB1 enable register (RCU_APB1EN)
  __IOM   uint32_t    BDCTL;    // Backup domain control register (RCU_BDCTL)
  __IOM   uint32_t    RSTSCK;   // Reset source/clock register (RCU_RSTSCK)
  __IOM   uint32_t    AHBRST;   // AHB reset register (RCU_AHBRST)
  __IOM   uint32_t    CFG1;     // Clock configuration register 1 (RCU_CFG1)
  __IOM   uint32_t    DSV;      // Deep-sleep mode voltage register (RCU_DSV)
} RCU_TypeDef;

// Control register (RCU_CTL)
#define RCU_CTL_PLL2STB         (1<<29)   // PLL2 clock stabilization flag
#define RCU_CTL_PLL2EN          (1<<28)   // PLL2 enable
#define RCU_CTL_PLL1STB         (1<<27)   // PLL1 clock stabilization flag
#define RCU_CTL_PLL1EN          (1<<26)   // PLL1 enable
#define RCU_CTL_PLLSTB          (1<<25)   // PLL clock stabilization flag
#define RCU_CTL_PLLEN           (1<<24)   // PLL clock enable 
#define RCU_CTL_CKMEN           (1<<19)   // HXTAL clock monitor enable
#define RCU_CTL_HXTALBPS        (1<<18)   // High speed crystal oscillator (HXTAL) clock bypass mode enable
#define RCU_CTL_HXTALSTB        (1<<17)   // High speed crystal oscillator (HXTAL) clock stabilization flag
#define RCU_CTL_HXTALEN         (1<<16)   // High speed crystal oscillator (HXTAL) enable
#define RCU_CTL_IRC8MCALIB_Msk  (0xFF<<8) // Internal 8MHz RC oscillator calibration value register
#define RCU_CTL_IRC8MADJ_Msk    (0x1F<<3) // Internal 8MHz RC oscillator clock trim adjust value
#define RCU_CTL_IRC8MSTB        (1<<1)    // Internal 8MHz RC oscillator stabilization flag
#define RCU_CTL_IRC8MEN         (1<<0)    // Internal 8MHz RC oscillator enable

// Clock configuration register 0 (RCU_CFG0)
#define RCU_CFG0_PLLMF_Msk      (0x203C0000UL)    // The PLL clock multiplication factor mask
#define RCU_CFG0_ADCPSC_Msk     (0x1000C000UL)    // ADC clock prescaler selection
#define RCU_CFG0_CKOUT0SEL_Msk  (0xF<<24)         // CKOUT0 clock source selection
#define RCU_CFG0_USBFSPSC_Msk   (3<<22)           // USBFS clock prescaler selection
#define RCU_CFG0_PREDV0_LSB     (1<<17)           // The LSB of PREDV0 division factor
#define RCU_CFG0_PLLSEL         (1<<16)           // PLL clock source selection
#define RCU_CFG0_APB2PSC_Msk    (7<<11)           // APB2 prescaler selection
#define RCU_CFG0_APB1PSC_Msk    (7<<8)            // APB1 prescaler selection
#define RCU_CFG0_AHBPSC_Msk     (0xF<<4)          // AHB prescaler selection
#define RCU_CFG0_SCSS_Msk       (3<<2)            // System clock switch status
#define RCU_CFG0_SCS_Msk        (3<<0)            // System clock switch

#define RCU_CFG0_CKOUT0SEL_None     0         // Clock not selected
#define RCU_CFG0_CKOUT0SEL_SysClk   (4<<24)   // System clock selected
#define RCU_CFG0_CKOUT0SEL_IRC2M    (5<<24)   // Internel 8MHz RC Oscillator clock selected
#define RCU_CFG0_CKOUT0SEL_HXTAL    (6<<24)   // External high speed oscillator clock selected
#define RCU_CFG0_CKOUT0SEL_CKPLL_2  (7<<24)   // (CK_PLL / 2) clock selected
#define RCU_CFG0_CKOUT0SEL_CKPLL1   (8<<24)   // CK_PLL1 clock selected
#define RCU_CFG0_CKOUT0SEL_CKPLL2_2 (9<<24)   // CK_PLL2 clock divided by 2 selected
#define RCU_CFG0_CKOUT0SEL_EXT1     (10<<24)  // EXT1 selected, to provide the external clock for ENET
#define RCU_CFG0_CKOUT0SEL_CKPLL2   (11<<24)  // CK_PLL2 clock selected

#define RCU_CFG0_USBFSPSC_PLL_1_5   (0<<22)   // CK_USBFS = CK_PLL / 1.5
#define RCU_CFG0_USBFSPSC_PLL       (1<<22)   // CK_USBFS = CK_PLL
#define RCU_CFG0_USBFSPSC_PLL_2_5   (2<<22)   // CK_USBFS = CK_PLL / 2.5
#define RCU_CFG0_USBFSPSC_PLL_2     (3<<22)   // CK_USBFS = CK_PLL / 2

#define RCU_CFG0_PLLMF_PLLx2    ((0<<29)|( 0<<18))    // PLL source clock x 2
#define RCU_CFG0_PLLMF_PLLx3    ((0<<29)|( 1<<18))    // PLL source clock x 3
#define RCU_CFG0_PLLMF_PLLx4    ((0<<29)|( 2<<18))    // PLL source clock x 4
#define RCU_CFG0_PLLMF_PLLx5    ((0<<29)|( 3<<18))    // PLL source clock x 5
#define RCU_CFG0_PLLMF_PLLx6    ((0<<29)|( 4<<18))    // PLL source clock x 6
#define RCU_CFG0_PLLMF_PLLx7    ((0<<29)|( 5<<18))    // PLL source clock x 7
#define RCU_CFG0_PLLMF_PLLx8    ((0<<29)|( 6<<18))    // PLL source clock x 8
#define RCU_CFG0_PLLMF_PLLx9    ((0<<29)|( 7<<18))    // PLL source clock x 9
#define RCU_CFG0_PLLMF_PLLx10   ((0<<29)|( 8<<18))    // PLL source clock x 10
#define RCU_CFG0_PLLMF_PLLx11   ((0<<29)|( 9<<18))    // PLL source clock x 11
#define RCU_CFG0_PLLMF_PLLx12   ((0<<29)|(10<<18))    // PLL source clock x 12
#define RCU_CFG0_PLLMF_PLLx13   ((0<<29)|(11<<18))    // PLL source clock x 13
#define RCU_CFG0_PLLMF_PLLx14   ((0<<29)|(12<<18))    // PLL source clock x 14
#define RCU_CFG0_PLLMF_PLLx6_5  ((0<<29)|(13<<18))    // PLL source clock x 6.5
#define RCU_CFG0_PLLMF_PLLx16   ((0<<29)|(14<<18))    // PLL source clock x 16
#define RCU_CFG0_PLLMF_PLLx16_  ((0<<29)|(15<<18))    // PLL source clock x 16
#define RCU_CFG0_PLLMF_PLLx17   ((1<<29)|( 0<<18))    // PLL source clock x 17
#define RCU_CFG0_PLLMF_PLLx18   ((1<<29)|( 1<<18))    // PLL source clock x 18
#define RCU_CFG0_PLLMF_PLLx19   ((1<<29)|( 2<<18))    // PLL source clock x 19
#define RCU_CFG0_PLLMF_PLLx20   ((1<<29)|( 3<<18))    // PLL source clock x 20
#define RCU_CFG0_PLLMF_PLLx21   ((1<<29)|( 4<<18))    // PLL source clock x 21
#define RCU_CFG0_PLLMF_PLLx22   ((1<<29)|( 5<<18))    // PLL source clock x 22
#define RCU_CFG0_PLLMF_PLLx23   ((1<<29)|( 6<<18))    // PLL source clock x 23
#define RCU_CFG0_PLLMF_PLLx24   ((1<<29)|( 7<<18))    // PLL source clock x 24
#define RCU_CFG0_PLLMF_PLLx25   ((1<<29)|( 8<<18))    // PLL source clock x 25
#define RCU_CFG0_PLLMF_PLLx26   ((1<<29)|( 9<<18))    // PLL source clock x 26
#define RCU_CFG0_PLLMF_PLLx27   ((1<<29)|(10<<18))    // PLL source clock x 27
#define RCU_CFG0_PLLMF_PLLx28   ((1<<29)|(11<<18))    // PLL source clock x 28
#define RCU_CFG0_PLLMF_PLLx29   ((1<<29)|(12<<18))    // PLL source clock x 29
#define RCU_CFG0_PLLMF_PLLx30   ((1<<29)|(13<<18))    // PLL source clock x 30
#define RCU_CFG0_PLLMF_PLLx31   ((1<<29)|(14<<18))    // PLL source clock x 31
#define RCU_CFG0_PLLMF_PLLx32   ((1<<29)|(15<<18))    // PLL source clock x 32

#define RCU_CFG0_ADCPSC_APB2_2  ((0<<28)|(0<<14))     // (CK_APB2 / 2) selected
#define RCU_CFG0_ADCPSC_APB2_4  ((0<<28)|(1<<14))     // (CK_APB2 / 4) selected
#define RCU_CFG0_ADCPSC_APB2_6  ((0<<28)|(2<<14))     // (CK_APB2 / 6) selected
#define RCU_CFG0_ADCPSC_APB2_8  ((0<<28)|(3<<14))     // (CK_APB2 / 8) selected
#define RCU_CFG0_ADCPSC_APB2_2_ ((1<<28)|(0<<14))     // (CK_APB2 / 2) selected
#define RCU_CFG0_ADCPSC_APB2_12 ((1<<28)|(1<<14))     // (CK_APB2 / 12) selected
#define RCU_CFG0_ADCPSC_APB2_8_ ((1<<28)|(2<<14))     // (CK_APB2 / 8) selected
#define RCU_CFG0_ADCPSC_APB2_16 ((1<<28)|(3<<14))     // (CK_APB2 / 16) selected

#define RCU_CFG0_PREDV0_LSB_PREDV0    0
#define RCU_CFG0_PREDV0_LSB_PREDV0_2  RCU_CFG0_PREDV0_LSB

#define RCU_CFG0_PLLSEL_IRC8M_2       0               // (IRC8M / 2) clock selected as source clock of PLL
#define RCU_CFG0_PLLSEL_HXTAL         RCU_CFG0_PLLSEL // HXTAL selected as source clock of PLL

#define RCU_CFG0_APB2PSC_AHB          (0)           // CK_AHB selected
#define RCU_CFG0_APB2PSC_AHB_2        (4<<11)       // (CK_AHB / 2) selected
#define RCU_CFG0_APB2PSC_AHB_4        (5<<11)       // (CK_AHB / 4) selected
#define RCU_CFG0_APB2PSC_AHB_8        (6<<11)       // (CK_AHB / 8) selected
#define RCU_CFG0_APB2PSC_AHB_16       (7<<11)       // (CK_AHB / 16) selected

#define RCU_CFG0_APB1PSC_AHB          (0)           // CK_AHB selected
#define RCU_CFG0_APB1PSC_AHB_2        (4<<8)        // (CK_AHB / 2) selected
#define RCU_CFG0_APB1PSC_AHB_4        (5<<8)        // (CK_AHB / 4) selected
#define RCU_CFG0_APB1PSC_AHB_8        (6<<8)        // (CK_AHB / 8) selected
#define RCU_CFG0_APB1PSC_AHB_16       (7<<8)        // (CK_AHB / 16) selected

#define RCU_CFG0_AHBPSC_SYS           (0)     // CK_SYS selected
#define RCU_CFG0_AHBPSC_SYS_2         (8<<4)  // (CK_SYS / 2) selected
#define RCU_CFG0_AHBPSC_SYS_4         (9<<4)  // (CK_SYS / 4) selected
#define RCU_CFG0_AHBPSC_SYS_8         (10<<4) // (CK_SYS / 8) selected
#define RCU_CFG0_AHBPSC_SYS_16        (11<<4) // (CK_SYS / 16) selected
#define RCU_CFG0_AHBPSC_SYS_648       (12<<4) // (CK_SYS / 64) selected
#define RCU_CFG0_AHBPSC_SYS_128       (13<<4) // (CK_SYS / 128) selected
#define RCU_CFG0_AHBPSC_SYS_256       (14<<4) // (CK_SYS / 256) selected
#define RCU_CFG0_AHBPSC_SYS_512       (15<<4) // (CK_SYS / 512) selected

#define RCU_CFG0_SCSS_IRC8M           (0)     // Select CK_IRC8M as the CK_SYS source
#define RCU_CFG0_SCSS_HXTAL           (1<<2)  // Select CK_HXTAL as the CK_SYS source
#define RCU_CFG0_SCSS_PLL             (2<<2)  // Select CK_PLL as the CK_SYS source

#define RCU_CFG0_SCS_IRC8M            (0)     // Select CK_IRC8M as the CK_SYS source
#define RCU_CFG0_SCS_HXTAl            (1)     // Select CK_HXTAL as the CK_SYS source
#define RCU_CFG0_SCS_PLL              (2)     // Select CK_PLL as the CK_SYS source

// Clock interrupt register (RCU_INT)
#define RCU_INT_CKMIC                 (1<<23)   // HXTAL clock stuck interrupt clear
#define RCU_INT_PLL2STBIC             (1<<22)   // PLL2 stabilization interrupt clear
#define RCU_INT_PLL1STBIC             (1<<21)   // PLL1 stabilization interrupt clear
#define RCU_INT_PLLSTBIC              (1<<20)   // PLL stabilization interrupt clear
#define RCU_INT_HXTALSTBIC            (1<<19)   // HXTAL stabilization interrupt clear
#define RCU_INT_IRC8MSTBIC            (1<<18)   // IRC8M stabilization interrupt clear
#define RCU_INT_LXTALSTBIC            (1<<17)   // LXTAL stabilization interrupt clear
#define RCU_INT_IRC40KSTBIC           (1<<16)   // IRC40K stabilization interrupt clear
#define RCU_INT_PLL2STBIE             (1<<14)   // PLL2 stabilization interrupt enable
#define RCU_INT_PLL1STBIE             (1<<13)   // PLL1 stabilization interrupt enable
#define RCU_INT_PLLSTBIE              (1<<12)   // PLL stabilization interrupt enable
#define RCU_INT_HXTALSTBIE            (1<<11)   // HXTAL stabilization interrupt enable
#define RCU_INT_IRC8MSTBIE            (1<<10)   // IRC8M Stabilization Interrupt Enable
#define RCU_INT_LXTALSTBIE            (1<<9)    // LXTAL stabilization interrupt enable
#define RCU_INT_IRC40KSTBIE           (1<<8)    // IRC40K stabilization interrupt enable
#define RCU_INT_CKMIF                 (1<<7)    // HXTAL clock stuck interrupt flag
#define RCU_INT_PLL2STBIF             (1<<6)    // PLL2 stabilization interrupt flag
#define RCU_INT_PLL1STBIF             (1<<5)    // PLL1 stabilization interrupt flag
#define RCU_INT_PLLSTBIF              (1<<4)    // PLL stabilization interrupt flag
#define RCU_INT_HXTALSTBIF            (1<<3)    // HXTAL stabilization interrupt flag
#define RCU_INT_IRC8MSTBIF            (1<<2)    // IRC8M stabilization interrupt flag
#define RCU_INT_LXTALSTBIF            (1<<1)    // LXTAL stabilization interrupt flag
#define RCU_INT_IRC40KSTBIF           (1<<0)    // IRC40K stabilization interrupt flag

// APB2 reset register (RCU_APB2RST)
#define RCU_APB2RST_USART0RST         (1<<14)   // USART0 reset
#define RCU_APB2RST_TIMER7RST         (1<<13)   // Timer 7 reset
#define RCU_APB2RST_SPI0RST           (1<<12)   // SPI0 reset
#define RCU_APB2RST_TIMER0RST         (1<<11)   // Timer 0 reset
#define RCU_APB2RST_ADC1RST           (1<<10)   // ADC1 reset
#define RCU_APB2RST_ADC0RST           (1<<9)    // ADC0 reset
#define RCU_APB2RST_PGRST             (1<<8)    // GPIO port G reset
#define RCU_APB2RST_PFRST             (1<<7)    // GPIO port F reset
#define RCU_APB2RST_PERST             (1<<6)    // GPIO port E reset
#define RCU_APB2RST_PDRST             (1<<5)    // GPIO port D reset
#define RCU_APB2RST_PCRST             (1<<4)    // GPIO port C reset
#define RCU_APB2RST_PBRST             (1<<3)    // GPIO port B reset
#define RCU_APB2RST_PARST             (1<<2)    // GPIO port A reset
#define RCU_APB2RST_AFRST             (1<<0)    // Alternate function I/O reset

// APB1 reset register (RCU_APB1RST)
#define RCU_APB1RST_DACRST            (1<<29)   // DAC reset
#define RCU_APB1RST_PMURST            (1<<28)   // Power control reset
#define RCU_APB1RST_BKPIRST           (1<<27)   // Backup interface reset
#define RCU_APB1RST_CAN1RST           (1<<26)   // CAN1 reset
#define RCU_APB1RST_CAN0RST           (1<<25)   // CAN0 reset
#define RCU_APB1RST_I2C1RST           (1<<22)   // I2C1 reset
#define RCU_APB1RST_I2C0RST           (1<<21)   // I2C0 reset
#define RCU_APB1RST_UART4RST          (1<<20)   // UART4 reset
#define RCU_APB1RST_UART3RST          (1<<19)   // UART3 reset
#define RCU_APB1RST_USART2RST         (1<<18)   // USART2 reset
#define RCU_APB1RST_USART1RST         (1<<17)   // USART1 reset
#define RCU_APB1RST_SPI2RST           (1<<15)   // SPI2 reset
#define RCU_APB1RST_SPI1RST           (1<<14)   // SPI1 reset
#define RCU_APB1RST_WWDGTRST          (1<<11)   // WWDGT reset
#define RCU_APB1RST_TIMER6RST         (1<<5)    // TIMER6 reset
#define RCU_APB1RST_TIMER5RST         (1<<4)    // TIMER5 reset
#define RCU_APB1RST_TIMER4RST         (1<<3)    // TIMER4 reset
#define RCU_APB1RST_TIMER3RST         (1<<2)    // TIMER3 reset
#define RCU_APB1RST_TIMER2RST         (1<<1)    // TIMER2 reset
#define RCU_APB1RST_TIMER1RST         (1<<0)    // TIMER1 reset

// AHB enable register (RCU_AHBEN)
#define RCU_AHBEN_ENETRXEN            (1<<16)   // Ethernet RX clock enable
#define RCU_AHBEN_ENETTXEN            (1<<15)   // Ethernet TX clock enable
#define RCU_AHBEN_ENETEN              (1<<14)   // Ethernet clock enable
#define RCU_AHBEN_USBFSEN             (1<<12)   // USBFS clock enable
#define RCU_AHBEN_EXMCEN              (1<<8)    // EXMC clock enable
#define RCU_AHBEN_CRCEN               (1<<6)    // CRC clock enable
#define RCU_AHBEN_FMCSPEN             (1<<4)    // FMC clock enable when sleep mode
#define RCU_AHBEN_SRAMSPEN            (1<<2)    // SRAM interface clock enable when sleep mode
#define RCU_AHBEN_DMA1EN              (1<<1)    // DMA1 clock enable
#define RCU_AHBEN_DMA0EN              (1<<0)    // DMA0 clock enable

// APB2 enable register (RCU_APB2EN)
#define RCU_APB2EN_USART0EN         (1<<14)   // USART0 enable
#define RCU_APB2EN_TIMER7EN         (1<<13)   // Timer 7 enable
#define RCU_APB2EN_SPI0EN           (1<<12)   // SPI0 enable
#define RCU_APB2EN_TIMER0EN         (1<<11)   // Timer 0 enable
#define RCU_APB2EN_ADC1EN           (1<<10)   // ADC1 enable
#define RCU_APB2EN_ADC0EN           (1<<9)    // ADC0 enable
#define RCU_APB2EN_PGEN             (1<<8)    // GPIO port G enable
#define RCU_APB2EN_PFEN             (1<<7)    // GPIO port F enable
#define RCU_APB2EN_PEEN             (1<<6)    // GPIO port E enable
#define RCU_APB2EN_PDEN             (1<<5)    // GPIO port D enable
#define RCU_APB2EN_PCEN             (1<<4)    // GPIO port C enable
#define RCU_APB2EN_PBEN             (1<<3)    // GPIO port B enable
#define RCU_APB2EN_PAEN             (1<<2)    // GPIO port A enable
#define RCU_APB2EN_AFEN             (1<<0)    // Alternate function I/O enable

// APB1 enable register (RCU_APB1EN)
#define RCU_APB1EN_DACEN            (1<<29)   // DAC enable
#define RCU_APB1EN_PMUEN            (1<<28)   // Power control enable
#define RCU_APB1EN_BKPIEN           (1<<27)   // Backup interface enable
#define RCU_APB1EN_CAN1EN           (1<<26)   // CAN1 enable
#define RCU_APB1EN_CAN0EN           (1<<25)   // CAN0 enable
#define RCU_APB1EN_I2C1EN           (1<<22)   // I2C1 enable
#define RCU_APB1EN_I2C0EN           (1<<21)   // I2C0 enable
#define RCU_APB1EN_UART4EN          (1<<20)   // UART4 enable
#define RCU_APB1EN_UART3EN          (1<<19)   // UART3 enable
#define RCU_APB1EN_USART2EN         (1<<18)   // USART2 enable
#define RCU_APB1EN_USART1EN         (1<<17)   // USART1 enable
#define RCU_APB1EN_SPI2EN           (1<<15)   // SPI2 enable
#define RCU_APB1EN_SPI1EN           (1<<14)   // SPI1 enable
#define RCU_APB1EN_WWDGTEN          (1<<11)   // WWDGT enable
#define RCU_APB1EN_TIMER6EN         (1<<5)    // TIMER6 enable
#define RCU_APB1EN_TIMER5EN         (1<<4)    // TIMER5 enable
#define RCU_APB1EN_TIMER4EN         (1<<3)    // TIMER4 enable
#define RCU_APB1EN_TIMER3EN         (1<<2)    // TIMER3 enable
#define RCU_APB1EN_TIMER2EN         (1<<1)    // TIMER2 enable
#define RCU_APB1EN_TIMER1EN         (1<<0)    // TIMER1 enable

// Backup domain control register (RCU_BDCTL)
#define RCU_BDCTL_BKPRST            (1<<16)   // Backup domain reset
#define RCU_BDCTL_RTCEN             (1<<15)   // RTC clock enable
#define RCU_BDCTL_RTCSRC_Msk        (3<<8)    // RTC clock entry selection
#define RCU_BDCTL_LXTALBPS          (1<<2)    // LXTAL bypass mode enable
#define RCU_BDCTL_LXTALSTB          (1<<1)    // Low speed crystal oscillator stabilization flag
#define RCU_BDCTL_LXTALEN           (1<<0)    // LXTAL enable

#define RCU_BDCTL_RTCSRC_NoClk      (0<<8)    // No clock selected
#define RCU_BDCTL_RTCSRC_LXTAL      (1<<8)    // CK_LXTAL selected as RTC source clock
#define RCU_BDCTL_RTCSRC_IRC40K     (2<<8)    // CK_IRC40K selected as RTC source clock
#define RCU_BDCTL_RTCSRC_HXTAL_128  (3<<8)    // (CK_HXTAL / 128) selected as RTC source clock

// Reset source/clock register (RCU_RSTSCK)
#define RCU_RSTSCK_LPRSTF           (1<<31)   // Low-power reset flag
#define RCU_RSTSCK_WWDGTRSTF        (1<<30)   // Window watchdog timer reset flag
#define RCU_RSTSCK_FWDGTRSTF        (1<<29)   // Free watchdog timer reset flag
#define RCU_RSTSCK_SWRSTF           (1<<28)   // Software reset flag
#define RCU_RSTSCK_PORRSTF          (1<<27)   // Power reset flag
#define RCU_RSTSCK_EPRSTF           (1<<26)   // External pin reset flag
#define RCU_RSTSCK_RSTFC            (1<<24)   // Reset flag clear
#define RCU_RSTSCK_IRC40KSTB        (1<<1)    // IRC40K stabilization flag
#define RCU_RSTSCK_IRC40KEN         (1<<0)    // IRC40K enable

// AHB reset register (RCU_AHBRST)
#define RCU_AHBRST_ENETRST        (1<<14)   // ENET reset
#define RCU_AHBRST_USBFSRST       (1<<12)   // USBFS reset

// Clock configuration register 1 (RCU_CFG1)
#define RCU_CFG1_I2S2SEL        (1<<18)   // I2S2 clock source selection
#define RCU_CFG1_I2S1SEL        (1<<17)   // I2S1 clock source selection
#define RCU_CFG1_PREDV0SEL      (1<<16)   // PREDV0 input clock source selection
#define RCU_CFG1_PLL2MF_Msk     (0xF<<12) // The PLL2 clock multiplication factor
#define RCU_CFG1_PLL1MF_Msk     (0xF<<8)  // The PLL1 clock multiplication factor
#define RCU_CFG1_PREDV1_Msk     (0xF<<4)  // PREDV1 division factor
#define RCU_CFG1_PREDV0_Msk     (0xF<<0)  // PREDV0 division factor

#define RCU_CFG1_PLL2MF_PLL2x8    (6<<12)
#define RCU_CFG1_PLL2MF_PLL2x9    (7<<12)
#define RCU_CFG1_PLL2MF_PLL2x10   (8<<12)
#define RCU_CFG1_PLL2MF_PLL2x11   (9<<12)
#define RCU_CFG1_PLL2MF_PLL2x12   (10<<12)
#define RCU_CFG1_PLL2MF_PLL2x13   (11<<12)
#define RCU_CFG1_PLL2MF_PLL2x14   (12<<12)
#define RCU_CFG1_PLL2MF_PLL2x15   (13<<12)
#define RCU_CFG1_PLL2MF_PLL2x16   (14<<12)
#define RCU_CFG1_PLL2MF_PLL2x20   (15<<12)

#define RCU_CFG1_PLL1MF_PLL1x8    (6<<8)
#define RCU_CFG1_PLL1MF_PLL1x9    (7<<8)
#define RCU_CFG1_PLL1MF_PLL1x10   (8<<8)
#define RCU_CFG1_PLL1MF_PLL1x11   (9<<8)
#define RCU_CFG1_PLL1MF_PLL1x12   (10<<8)
#define RCU_CFG1_PLL1MF_PLL1x13   (11<<8)
#define RCU_CFG1_PLL1MF_PLL1x14   (12<<8)
#define RCU_CFG1_PLL1MF_PLL1x15   (13<<8)
#define RCU_CFG1_PLL1MF_PLL1x16   (14<<8)
#define RCU_CFG1_PLL1MF_PLL1x20   (15<<8)

#define RCU_CFG1_PREDV1_1         (0<<4)
#define RCU_CFG1_PREDV1_2         (1<<4)
#define RCU_CFG1_PREDV1_3         (2<<4)
#define RCU_CFG1_PREDV1_4         (3<<4)
#define RCU_CFG1_PREDV1_5         (4<<4)
#define RCU_CFG1_PREDV1_6         (5<<4)
#define RCU_CFG1_PREDV1_7         (6<<4)
#define RCU_CFG1_PREDV1_8         (7<<4)
#define RCU_CFG1_PREDV1_9         (8<<4)
#define RCU_CFG1_PREDV1_10        (9<<4)
#define RCU_CFG1_PREDV1_11        (10<<4)
#define RCU_CFG1_PREDV1_12        (11<<4)
#define RCU_CFG1_PREDV1_13        (12<<4)
#define RCU_CFG1_PREDV1_14        (13<<4)
#define RCU_CFG1_PREDV1_15        (14<<4)
#define RCU_CFG1_PREDV1_16        (15<<4)

#define RCU_CFG1_PREDV0_1         (0)
#define RCU_CFG1_PREDV0_2         (1)
#define RCU_CFG1_PREDV0_3         (2)
#define RCU_CFG1_PREDV0_4         (3)
#define RCU_CFG1_PREDV0_5         (4)
#define RCU_CFG1_PREDV0_6         (5)
#define RCU_CFG1_PREDV0_7         (6)
#define RCU_CFG1_PREDV0_8         (7)
#define RCU_CFG1_PREDV0_9         (8)
#define RCU_CFG1_PREDV0_10        (9)
#define RCU_CFG1_PREDV0_11        (10)
#define RCU_CFG1_PREDV0_12        (11)
#define RCU_CFG1_PREDV0_13        (12)
#define RCU_CFG1_PREDV0_14        (13)
#define RCU_CFG1_PREDV0_15        (14)
#define RCU_CFG1_PREDV0_16        (15)

// Deep-sleep mode voltage register (RCU_DSV)
#define RCU_DSV_DSLPVS_Msk    (7) // Deep-sleep mode voltage select

#define RCU_DSV_DSLPVS_1p2    (0) // The core voltage is 1.2V in Deep-sleep mode
#define RCU_DSV_DSLPVS_1p1    (1) // The core voltage is 1.1V in Deep-sleep mode
#define RCU_DSV_DSLPVS_1p0    (2) // The core voltage is 1.0V in Deep-sleep mode
#define RCU_DSV_DSLPVS_0p9    (3) // The core voltage is 0.9V in Deep-sleep mode


/* ToDo: add here your device specific peripheral access structure typedefs
         including bit definitions for Pos/Msk macros
         following is an example for a timer */



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

#define MEMORY_DENSITY_INFO     ((MEMORY_DENSITY_INFO_TypeDef*) 0x1FFFF7E0UL)
#define U_DEV_ID                ((UniqueDeviceID_TypeDef*)      0x1FFFF7E8UL)

#define FMC                     ((FMC_TypeDef*)                     FMC_BASE)
#define PMU                     ((PMU_TypeDef*)                     PMU_BASE)
#define BKP                     ((BKP_TypeDef*)                     BKP_BASE)
#define RCU                     ((RCU_TypeDef*)                     RCU_BASE)

#ifdef __cplusplus
}
#endif

#endif  /* GD32F105_H */
