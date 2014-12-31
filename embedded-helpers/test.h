//
//  test.h
//  embedded-helpers
//
//  Created by Jeffrey Stewart on 12/23/14.
//  Copyright (c) 2014 Cove Technology. All rights reserved.
//

#ifndef embedded_helpers_test_h
#define embedded_helpers_test_h

#define ASSERT(X)                                               \
do {                                                            \
    if(false == (X))                                            \
    {                                                           \
        m_failures++;                                           \
        printf("Test Failure in %s at %d\n",__func__,__LINE__); \
    }                                                           \
} while(0)



#endif
