//
//  compact_logs.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/11/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "compact_logs.h"

static bool     add_to_queue        (log_t *log);
static bool     remove_from_queue   (log_t *log);
static uint32_t spaces_remaining    (void);
static void     reset_entry_at_index(uint32_t);

static log_t    log_queue[LOG_QUEUE_DEPTH];
static uint32_t m_idx_head;
static uint32_t m_idx_tail;
static bool     m_is_empty;

void log_init(void) {

    log_clear();
}

bool log_write(log_t *log)
{
    
    assert(NULL != log);
    return (add_to_queue(log));
}

bool log_read(log_t *log) {

    return (remove_from_queue(log));
    
}

bool log_is_full(void)
{
    return (0 == spaces_remaining());
}

bool log_is_empty(void)
{
    return m_is_empty;
}

static uint32_t spaces_remaining(void)
{
    
    uint32_t spaces = 0;
    
    for (int x = 0; x < LOG_QUEUE_DEPTH; x++)
    {
        if (INIT == log_queue[x].state)
        {
            spaces++;
        }
    }
    return spaces;
}

void log_clear(void)
{
    
    m_idx_head = 0;
    m_idx_tail = 0;
    m_is_empty = true;
    
    for (int x = 0; x < LOG_QUEUE_DEPTH; x++)
    {
        reset_entry_at_index(x);
    }
}

static bool add_to_queue(log_t *log)
{
    
    assert(NULL != log);
    
    if (true == log_is_full())
    {
        return false;
    }
    
    log_queue[m_idx_head]       = *log;
    log_queue[m_idx_head].state = PENDING;
    
    m_is_empty = false;
    
    //handle incrementing the head pointer
    if ((LOG_QUEUE_DEPTH - 1) == m_idx_head )
    {
        m_idx_head  = 0;
    }
    else {
        m_idx_head  += 1;
    }
    
    return true;
}

static bool remove_from_queue(log_t *log)
{
    if (true == log_is_empty())
    {
        return false;
    }

    *log = log_queue[m_idx_tail];
    reset_entry_at_index(m_idx_tail);
    
    if ((LOG_QUEUE_DEPTH - 1) == m_idx_tail )
    {
        m_idx_tail  = 0;
    }
    else
    {
        m_idx_tail  += 1;
    }
    
    if (m_idx_tail == m_idx_head)
    {
        m_is_empty = true;
    }
    
    return true;
}

static void reset_entry_at_index(uint32_t index)
{
    log_queue[index].state  = INIT;
    log_queue[index].offset = 0;
    log_queue[index].tick   = 0;
    log_queue[index].type   = 0;
    
    for (int x=0; x < LOG_DATA_LENGTH; x++)
    {
        log_queue[index].data[x] = 0;
    }
}
