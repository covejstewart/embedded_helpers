//
//  hal_eeprom.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 2/11/15.
//  Copyright (c) 2015 Cove Technology. All rights reserved.
//

#include "hal_eeprom.h"
#include <assert.h>

static uint8_t m_data[EEPROM_SIZE_BYTES];

void eeprom_init(void)
{
    //EEPROM specific initialization
}

bool eeprom_read(uint32_t address, uint8_t *buffer, uint32_t length)
{
    if(EEPROM_SIZE_BYTES < (address + length))
    {
        //this read is attempting to access data outside of teh EEPROM space
        return false;
    }
    
    for(int x = 0; x < length; x++)
    {
        *(buffer + x) = m_data[address + x];
    }
    
    return true;
}


bool eeprom_write(uint32_t address, uint8_t *buffer, uint32_t length)
{
    return false;
}

void test_eeprom_set_data(uint32_t address, uint8_t *buffer, uint32_t length)
{
    //check to make sure that total length is less than the available size
    assert(EEPROM_SIZE_BYTES > (address + length));
    
    for (int x = 0; x < length; x++)
    {
        m_data[address + x] = *(buffer + x);
    }

}