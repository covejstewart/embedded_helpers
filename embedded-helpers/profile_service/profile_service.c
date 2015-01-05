//
//  profile_service.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/31/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "profile_service.h"

#ifdef TESTBENCH

static uint32_t m_ticks;

#else
#error "No Include - Add Target HW Include"
#endif

#define N_PROFILES 10

typedef struct {
    uint32_t start;
    uint32_t stop;
    bool     is_active;
}m_profile_t;

static void clear_profile(m_profile_t *);

static m_profile_t profiles[N_PROFILES];

void profile_init(void)
{
    for (int x = 0; x < N_PROFILES; x++)
    {
        clear_profile(&profiles[x]);
    }
    
}

void profile_start(void)
{
    
}

void profile_stop(void)
{
    
}

static void clear_profile(m_profile_t *profile)
{
    assert(NULL == profile);
    
    profile->is_active = false;
    profile->start     = 0;
    profile->stop      = 0;
}

/*************************
 *
 *   Test Interface
 *
 **************************/
void profile_test_set_ticks(uint32_t tick) {
#ifdef TESTBENCH
    m_ticks = tick;
#endif
}

