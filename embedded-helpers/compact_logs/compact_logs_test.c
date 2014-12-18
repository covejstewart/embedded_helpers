//
//  compact_logs_test.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/15/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "compact_logs_test.h"
#include "compact_logs.h"

#define FAILURE 1
#define SUCCESS 0

static uint32_t m_failures;

#define ASSERT(X) \
do { \
if(false == (X)) { \
    m_failures++; \
    printf("Test Failure in %s at %d\n",__func__,__LINE__); \
}\
} while(0)


static void free_space_after_write(void)
{
    
    log_init();

    log_t log;
    
    ASSERT(false == log_is_full());
    ASSERT(true  == log_is_empty());
    ASSERT(true  == log_write(&log));
    ASSERT(false == log_is_empty());
    
    log_clear();
    
    ASSERT(true  == log_is_empty());
    
    
}

static void fill_queue_and_overflow(void)
{
    log_init();
    
    log_t log;
    
    for (int x = 0; x < LOG_QUEUE_DEPTH; x++)
    {
        ASSERT(true == log_write(&log));
    }
    
    ASSERT(true  == log_is_full());
    ASSERT(false == log_write(&log));
    ASSERT(true  == log_is_full());
}

static void check_for_underflow(void)
{
    log_init();
    
    log_t log;
    
    ASSERT(true  == log_is_empty());
    ASSERT(false == log_read(&log));
    ASSERT(true  == log_is_empty());
}

uint32_t compact_logs_test(void) {
    
    m_failures = 0;
    
    printf("Running - %s\n", __func__);
    
    free_space_after_write();
    fill_queue_and_overflow();
    check_for_underflow();
    
    return m_failures;
}