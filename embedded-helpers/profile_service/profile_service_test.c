//
//  profile_service_test.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/31/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "profile_service_test.h"
#include "profile_service.h"


static uint32_t m_failures;



static void test_push_pop(void)
{
    uint32_t test = 12;
    
    profile_init();
    
    ASSERT(test == profile_push(test));
    ASSERT(test == profile_pop());
    
}

static void test_max_profiles(void)
{
    profile_init();
    
    for (int x = 0; x < N_PROFILES; x++) {
        ASSERT(x == profile_push(x));
    }
    ASSERT(-1 == profile_push(0));
}

static void test_active_id(void)
{
    profile_init();
    
    ASSERT(-1 == profile_test_get_active_id());
    
    for (int x = 0; x < N_PROFILES; x++) {
        profile_push(x);
        ASSERT(x == profile_test_get_active_id());
    }
}

static void test_push_pop_cycles(void)
{
    profile_init();
    
    for (int x = 0; x < 100; x++) {
        profile_push(x);
        ASSERT(x == profile_pop());
    }
}

uint32_t profile_service_test(void)
{
    ECHOTESTSUITE();
    
    m_failures = 0;

    test_push_pop();
    test_max_profiles();
    test_active_id();
    test_push_pop_cycles();

    return m_failures;
}