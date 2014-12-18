//
//  block.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/9/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__block__
#define __embedded_helpers__block__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define X_DIM 5
#define Y_DIM 5

#define PIXELS X_DIM * Y_DIM
#define PIXEL_BYTES PIXELS * 2

typedef struct block_struct{
    uint32_t id;
    uint16_t base;
    uint16_t data[PIXELS];
    uint16_t length;
    uint8_t  compressed[PIXEL_BYTES];
}block_struct_t;

void block_initialize(block_struct_t *);
void block_compress  (block_struct_t *);


#endif /* defined(__embedded_helpers__block__) */
