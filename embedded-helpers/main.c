//
//  main.c
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/9/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#include <stdio.h>
#include "compact_logs_test.h"
#include "timer_service_test.h"
#include "profile_service_test.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    compact_logs_test();
    timer_service_test();
    profile_service_test();
    
}
