//
//  compact_logs_test.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/15/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "compact_logs_test.h"
#include "compact_logs.h"

static uint32_t m_failures;


static void test_free_space_after_write(void)
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

static void test_fill_queue_and_overflow(void)
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

static void test_check_for_underflow(void)
{
    log_init();
    
    log_t log;
    
    ASSERT(true  == log_is_empty());
    ASSERT(false == log_read(&log));
    ASSERT(true  == log_is_empty());
}

static void test_incrementing_timestamp(void)
{
    log_init();
    
    log_t log;
    
    log_write(&log);
    log_read (&log);
    
    ASSERT(0 == log.tick);
    
    log_increment_time();
    
    log_write(&log);
    log_read (&log);
    
    ASSERT(1 == log.tick);
    
}

static void test_incrementing_order(void)
{
    log_init();
    
    log_t log;
    
    log_write(&log);
    log_read (&log);
    
    ASSERT(0 == log.order);
    
    log_write(&log);
    log_read (&log);
    
    ASSERT(1 == log.order);
    
    log_increment_time();
    
    log_write(&log);
    log_read (&log);
    
    ASSERT(0 == log.order);

}

uint32_t compact_logs_test(void) {
    
    m_failures = 0;
    
    printf("Running - %s\n", __func__);
    
    test_free_space_after_write();
    test_fill_queue_and_overflow();
    test_check_for_underflow();
    test_incrementing_timestamp();
    test_incrementing_order();
    

    return m_failures;
}