//
//  serial_number_test.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 2/11/15.
//  Copyright (c) 2015 Cove Technology. All rights reserved.
//

#include "serial_number_test.h"
#include "serial_number.h"

static uint32_t m_failures;

static void test_read_serial_number(void)
{
    uint8_t buffer[SERIAL_NUM_SZ];
    
    ASSERT(true == get_serial_number(buffer, sizeof(buffer)));
}

uint32_t serial_number_test(void)
{
    m_failures = 0;
    
    ECHOTESTSUITE();
    
    test_read_serial_number();
    
    return m_failures;
}