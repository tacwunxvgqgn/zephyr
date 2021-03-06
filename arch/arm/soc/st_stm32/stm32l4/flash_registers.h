/*
 * Copyright (c) 2016 Open-RnD Sp. z o.o.
 * Copyright (c) 2016 BayLibre, SAS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _STM32L4X_FLASH_REGISTERS_H_
#define _STM32L4X_FLASH_REGISTERS_H_

enum {
	STM32L4X_FLASH_LATENCY_0 = 0x0,
	STM32L4X_FLASH_LATENCY_1 = 0x1,
	STM32L4X_FLASH_LATENCY_2 = 0x2,
	STM32L4X_FLASH_LATENCY_3 = 0x3,
	STM32L4X_FLASH_LATENCY_4 = 0x4,
};

/* 3.7.1 FLASH_ACR */
union __ef_acr {
	u32_t val;
	struct {
		u32_t latency :3 __packed;
		u32_t rsvd__3_7 :5 __packed;
		u32_t prften :1 __packed;
		u32_t icen :1 __packed;
		u32_t dcen :1 __packed;
		u32_t icrst :1 __packed;
		u32_t dcrst :1 __packed;
		u32_t run_pd :1 __packed;
		u32_t sleep_pd :1 __packed;
		u32_t rsvd__16_31 :17 __packed;
	} bit;
};

/*  FLASH register map */
struct stm32l4x_flash {
	union __ef_acr acr;
	u32_t pdkeyr;
	u32_t keyr;
	u32_t optkeyr;
	u32_t sr;
	u32_t cr;
	u32_t eccr;
	u32_t rsvd_0;
	u32_t optr;
	u32_t pcrop1sr;
	u32_t pcrop1er;
	u32_t wrp1ar;
	u32_t wrp1br;
	u32_t rsvd_2[4];

	/*
	 * The registers below are only present on STM32L4x2, STM32L4x5,
	 * STM32L4x6.
	 */
	u32_t pcrop2sr;
	u32_t pcrop2er;
	u32_t wrp2ar;
	u32_t wrp2br;
};

#endif	/* _STM32L4X_FLASH_REGISTERS_H_ */
