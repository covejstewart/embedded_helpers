//
//  serial_number.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 2/11/15.
//  Copyright (c) 2015 Cove Technology. All rights reserved.
//

#include "serial_number.h"
#include "hal_eeprom.h"

#define SERIAL_NUMBER_EEPROM_ADDRESS 0


bool get_serial_number(uint8_t *buffer, uint32_t length)
{
    assert(SERIAL_NUM_SZ == length);
    assert(NULL != buffer);
    
    return eeprom_read(SERIAL_NUMBER_EEPROM_ADDRESS, buffer, length);
}

bool set_serial_number(uint8_t *buffer, uint32_t length)
{
    assert(SERIAL_NUM_SZ == length);
    assert(NULL != buffer);
    
    return eeprom_write(SERIAL_NUMBER_EEPROM_ADDRESS, buffer, length);
}