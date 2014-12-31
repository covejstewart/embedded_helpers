//
//  profile_service_test.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/31/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "profile_service_test.h"

static uint32_t m_failures;

uint32_t profile_service_test(void)
{
    ECHOTESTSUITE();
    
    m_failures = 0;
    

    return m_failures;
}