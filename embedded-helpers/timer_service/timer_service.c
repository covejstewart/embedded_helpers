//
//  timer_service.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/22/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "timer_service.h"

static uint32_t m_spaces;

void timer_init(void)
{
    m_spaces = 0;
}

bool timer_add_callback_and_interval(void (*func)(void), uint32_t interval)
{
    if (N_SLOTS == m_spaces) {
        return false;
    }
    m_spaces++;
    return true;
}