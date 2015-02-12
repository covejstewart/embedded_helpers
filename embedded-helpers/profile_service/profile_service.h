//
//  profile_service.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/31/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__profile_service__
#define __embedded_helpers__profile_service__

#include <assert.h>
#include <stdbool.h>

#define N_PROFILES 10

void profile_init (void);
int  profile_push ( int);
int  profile_pop  (void);

/*************************
*
*   Test Interface
*
**************************/
uint32_t profile_test_get_active_id(void);

#endif /* defined(__embedded_helpers__profile_service__) */
