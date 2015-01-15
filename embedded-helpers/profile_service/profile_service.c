//
//  profile_service.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/31/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "profile_service.h"


static int m_error = -1;

static uint8_t m_index;
static int m_active_id;

typedef struct {
    int id;
    bool     is_active;
} m_profile_t;

static void clear_profile(m_profile_t *);

static m_profile_t profiles[N_PROFILES];

void profile_init(void)
{
    m_active_id = m_error;
    m_index     = 0;
    
    for (int x = 0; x < N_PROFILES; x++)
    {
        clear_profile(&profiles[x]);
    }
    
}

int profile_push(int id)
{
    if (N_PROFILES == m_index)
    {
        return m_error;
    }
    
    if (0 > id)
    {
        return m_error;
    }
    
    
    profiles[m_index].id = id;
    m_index++;
    
    m_active_id = id;

    return m_active_id;
    
}

int profile_pop(void)
{
 
    if(0 == m_index)
    {
        return m_error;
    }
    
    m_index--;
    
    m_active_id = profiles[m_index].id;
    
    return m_active_id;
    
}

static void clear_profile(m_profile_t *profile)
{
    assert(NULL != profile);
    
    profile->is_active = false;
    profile->id = m_error;

}

/*************************
 *
 *   Test Interface
 *
 **************************/
uint32_t profile_test_get_active_id(void) {
    //the index is incremented immediately
    return m_active_id;
    
}

