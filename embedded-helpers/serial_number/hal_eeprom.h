//
//  hal_eeprom.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 2/11/15.
//  Copyright (c) 2015 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__hal_eeprom__
#define __embedded_helpers__hal_eeprom__

#include <stdbool.h>
#include <stdint.h>

#define EEPROM_SIZE_BYTES 0x100

void eeprom_init(void);

bool eeprom_read (uint32_t address, uint8_t *buffer, uint32_t length);
bool eeprom_write(uint32_t address, uint8_t *buffer, uint32_t length);

/*------------------
 *
 *  Test Interface
 *
 *------------------*/

void test_eeprom_set_data(uint32_t address, uint8_t *buffer, uint32_t length);

#endif /* defined(__embedded_helpers__hal_eeprom__) */
