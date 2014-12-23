//
//  timer_service_test.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/23/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "timer_service_test.h"
#include "timer_service.h"

static uint32_t m_failures = 0;

static void callback_target(void) {
    
}

static void test_add_callbacks(void) {
    
    uint32_t interval = 2;

    for (int x=0; x < N_SLOTS; x++)
    {
        //fill all of the timer slots
        ASSERT(timer_add_callback_and_interval(&callback_target, interval));
    }
    
    //add one too many
    ASSERT(false == timer_add_callback_and_interval(&callback_target, interval));
    
    
}


uint32_t timer_service_test(void) {
    
    m_failures = 0;
    
    printf("Running - %s\n", __func__);

    test_add_callbacks();
    
    return m_failures;
}