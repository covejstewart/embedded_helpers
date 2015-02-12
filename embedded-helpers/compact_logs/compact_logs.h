//
//  compact_logs.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/11/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__compact_logs__
#define __embedded_helpers__compact_logs__

#include <stdbool.h>
#include <assert.h>

#define LOG_QUEUE_DEPTH 4
#define LOG_DATA_LENGTH 8

typedef enum {
    INIT = 0,
    PENDING,
    SENT
}log_state;


typedef struct log_struct {
    log_state   state;
    uint32_t    tick;
    uint8_t     order;
    uint8_t     type;
    uint8_t     data[LOG_DATA_LENGTH];
} log_t;


void  log_init    (void);
void  log_clear   (void);
bool  log_write   (log_t *log);
bool  log_read    (log_t *log);

bool  log_is_full (void);
bool  log_is_empty(void);

void  log_increment_time(void);

#endif /* defined(__embedded_helpers__compact_logs__) */
