//
//  serial_number.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 2/11/15.
//  Copyright (c) 2015 Cove Technology. All rights reserved.
//

#ifndef __embedded_helpers__serial_number__
#define __embedded_helpers__serial_number__

#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define SERIAL_NUM_SZ 16

bool  get_serial_number(uint8_t *, uint32_t);
bool  set_serial_number(uint8_t *, uint32_t);

#endif /* defined(__embedded_helpers__serial_number__) */
