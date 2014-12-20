//
//  compact_logs.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/11/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "compact_logs.h"

/********************
*
*  Static Functions
*
*********************/

static bool     add_to_queue        (log_t *);
static bool     remove_from_queue   (log_t *);
static uint32_t spaces_remaining    (void);
static void     reset_entry_at_index(uint32_t);
static uint32_t serialize_log       (log_t *, uint8_t *, uint32_t);

/********************
*
*  Static Variables
*
*********************/

static log_t    log_queue[LOG_QUEUE_DEPTH];
static uint32_t m_idx_head;
static uint32_t m_idx_tail;
static bool     m_is_empty;
static uint32_t m_ticks;
static uint8_t  m_logs_this_tick;


void log_init(void)
{
    m_ticks = 0;
    m_logs_this_tick = 0;
    log_clear();
}

bool log_write(log_t *log)
{
    assert(NULL != log);
    return (add_to_queue(log));
}

bool log_read(log_t *log)
{
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

void log_increment_time(void)
{
    m_ticks++;
    m_logs_this_tick = 0;
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


static uint32_t serialize_log(log_t *log, uint8_t *buffer, uint32_t size) {
    
    assert(sizeof(log_t) <= size);
    
    int idx = 0;
    
    uint32_t tick     = log->tick;
    *(buffer + idx++) = (tick >>  0) & 0xff;
    *(buffer + idx++) = (tick >>  8) & 0xff;
    *(buffer + idx++) = (tick >> 16) & 0xff;
    *(buffer + idx++) = (tick >> 24) & 0xff;
    
    uint32_t order    = log->order;
    *(buffer + idx++) = order;

    
    uint8_t type      = log->type;
    *(buffer + idx++) = type;
    
    uint8_t *data     = log->data;
    for (int x = 0; x < LOG_DATA_LENGTH; x++)
    {
        *(buffer + idx++) = *(data + x);
    }
    
    return idx;
    
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
    log_queue[m_idx_head].tick  = m_ticks;
    log_queue[m_idx_head].order = m_logs_this_tick++;
    
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
    log_queue[index].order = 0;
    log_queue[index].tick   = 0;
    log_queue[index].type   = 0;
    
    for (int x=0; x < LOG_DATA_LENGTH; x++)
    {
        log_queue[index].data[x] = 0;
    }
}
