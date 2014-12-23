//
//  timer_service.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/22/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__timer_service__
#define __embedded_helpers__timer_service__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define N_SLOTS 5

void timer_init     (void);
bool timer_add_callback_and_interval(void (*func)(void), uint32_t);

/*------------------
 *  
 *  Test Interface
 *
 *------------------*/

void timer_increment_time(void);

#endif /* defined(__embedded_helpers__timer_service__) */
