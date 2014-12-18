//
//  block.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/9/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include "block.h"


#define MAX_SHIFT 6
#define TOTAL_BLOCKS

//#define USE_VECTOR_MATH
#ifdef USE_VECTOR_MATH
    error("Vector math not implemented");
#endif

static uint32_t m_bits_to_shift = 0;

void block_initialize(block_struct_t *block)
{
    block->id       = 0;
    block->base     = 0;
    block->length   = 0;

    for (int x = 0; x < PIXELS; x++)
    {
        block->data[x] = 0;
    }
    
    for (int x = 0; x < PIXEL_BYTES; x++)
    {
        block->compressed[x] = 0;
    }
}

/**
 *  Compress the block based on the following steps
 *    1. Find the 'floor' in the data
 *    2. Subtract the minimum value from each sample
 *    3. Calculate how many bits are required to represent the remaining data in the samples
 *    4.  Pack all of the remaining bits together
 *  @param block <#block description#>
 */
void block_compress(block_struct_t *block) {
    
    uint16_t smallest = 0xFFFF;
    uint16_t largest = 0x0000;
    
    for (int x = 0; x < PIXELS; x++ ) {
        uint16_t sample = block->data[x];
        
        if (sample > largest) {
            sample = largest;
        }
        
        if (sample < smallest) {
            sample = smallest;
        }
    }
    
}

void block_set_bits_to_shift(uint32_t bits) {
    m_bits_to_shift = bits;
}



