//
//  profile_service.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/31/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__profile_service__
#define __embedded_helpers__profile_service__

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void profile_init(void);
void profile_start(void);
void profile_stop(void);


/*************************
*
*   Test Interface
*
**************************/
void profile_test_set_ticks(uint32_t);

#endif /* defined(__embedded_helpers__profile_service__) */
