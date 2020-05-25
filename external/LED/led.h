/*
********************************************************************************
* Copyright of anhgiau (nguyenanhgiau1008@gmail.com)
* Follow this coding style used at:
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* - Development or contribute must follow this coding style.
*
* @file:      led.h
* @author:    HaiDang, anhgiau (nguyenanhgiau1008@gmail.com)
* @version:   1.0.1
* @date:      7/31/2018
* @brief:     Header file of LED Driver
********************************************************************************
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LED_H_
#define LED_H_
 
#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "chip_selection.h"
#include "prj_options.h"
#include <stdbool.h>
/* Exported Define -----------------------------------------------------------*/

/* Exported Typedefs ---------------------------------------------------------*/

/* state of led */
typedef enum {
  E_LED_STATE_OFF   = 0,
  E_LED_STATE_ON,
  E_LED_STATE_TOGGLE,
  E_LED_STATE_EFFECT_STOP,
  E_LED_STATE_EFFECT_BLINK,
  E_LED_STATE_EFFECT_FLASH,
  E_LED_STATE_EFFECT_BREATH,
  E_LED_STATE_EFFECT_UNKNOWN = 0xFF
}LED_teState;

/* error code */
typedef enum
{
  E_LED_OK,
  E_LED_FAIL
}LED_teStatus;

typedef void (*LED_tpfOpen)(void);
typedef void (*LED_tpfClose)(void);
typedef void (*LED_tpfSetOnOff)(bool);

typedef struct
{
  bool            bActiveHight;
  bool            bState;
  LED_tpfOpen     pfOpen;
  LED_tpfClose    pfClose;
  LED_tpfSetOnOff pfSetOnOff;
}LED_tsLed;

/* Exported Structure Declarations -------------------------------------------*/

/* Exported Functions Declarations -------------------------------------------*/
LED_teStatus LED_eInit(LED_tsLed *psLeds, uint8 u8NumLeds);
LED_teStatus LED_eOpen(uint8          *pu8LedIndex,
                        LED_tsLed     *psLed);
LED_teStatus LED_eClose(uint8 u8LedIndex);
LED_teStatus LED_eSetOnOff(uint8 u8LedIndex, bool bState);

/* advance feature */
LED_teStatus LED_eSetLevel(uint8 u8LedIndex, uint8 u8Level);
LED_teStatus LED_eSetColor(uint8 u8Red, uint8 u8Green, uint8 u8Blue);

/* External Variable Declarations --------------------------------------------*/
#ifdef LED_TOTAL_NUMBER
extern uint8 u8TimerTaskLED;
#endif
#ifdef __cplusplus
}
#endif
#endif /*LED_H_*/
/************************ (C) COPYRIGHT anhgiau ****************END OF FILE****/
