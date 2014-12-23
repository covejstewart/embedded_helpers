//
//  timer_service.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/22/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "timer_service.h"

static void not_null(void);

typedef struct callback{
    uint32_t interval;
    uint32_t count;
    void     (*callback)(void);
}callback_t;

static callback_t   m_callbacks[N_SLOTS];
static uint32_t     m_spaces;

void timer_init(void)
{
    m_spaces = 0;
    
    for (int x = 0; x < N_SLOTS; x++)
    {
        m_callbacks[x].interval  = 0;
        m_callbacks[x].count     = 0;
        m_callbacks[x].callback  = not_null;
    }
    
}

bool timer_add_callback_and_interval(void (*func)(void), uint32_t interval)
{
    if (N_SLOTS == m_spaces) {
        return false;
    }
    
    if (NULL == func) {
        return false;
    }
    m_callbacks[m_spaces].count     = 0;
    m_callbacks[m_spaces].interval  = interval;
    m_callbacks[m_spaces].callback  = func;
    
    m_spaces++;
    return true;
}

void timer_increment_time(void) {
    
    for (int x = 0; x < N_SLOTS; x++)
    {
        if (0 == m_callbacks[x].interval)
        {
            continue;
        }
        else
        {
            m_callbacks[x].count++;
            
            if ( m_callbacks[x].interval == m_callbacks[x].count)
            {
                //call to update and reset the count.
                m_callbacks[x].callback();
                m_callbacks[x].count = 0;
            }
        }
    }
}

static void not_null(void)
{
    //a safe 'not NULL' landing place.  Still an error, but
    //doesn't tear the wheels off.
    assert(true==false);
}