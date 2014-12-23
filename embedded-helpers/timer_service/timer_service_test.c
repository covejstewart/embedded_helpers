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

static uint32_t m_num_callbacks_called;

static void callback_target(void) {
    
    m_num_callbacks_called++;
}

static void test_init(void) {
    
    m_num_callbacks_called = 0;
    timer_init();
}

static void test_trigger_callbacks(void) {
    
    test_init();
    
    for (int x=0; x < N_SLOTS; x++) {
        timer_add_callback_and_interval(&callback_target, 2);
    }
    ASSERT(0 == m_num_callbacks_called);
    timer_increment_time();
    ASSERT(0 == m_num_callbacks_called);
    timer_increment_time();
    ASSERT(N_SLOTS == m_num_callbacks_called);
}

static void test_adding_null(void) {
    
    test_init();
    
    ASSERT(false == timer_add_callback_and_interval(NULL, 0));
}

static void test_add_callbacks(void) {
    
    test_init();
    
    uint32_t interval = 2;

    timer_init();
    
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

    test_adding_null();
    test_add_callbacks();
    test_trigger_callbacks();
    
    return m_failures;
}