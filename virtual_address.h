//
// Created by DaNTe on 28.11.2021.
//

#ifndef OS3_VIRTUAL_ADDRESS_H
#define OS3_VIRTUAL_ADDRESS_H

struct virtual_address {
    int page_number;
    int segment_number;
    int shift;
};


#endif //OS3_VIRTUAL_ADDRESS_H
