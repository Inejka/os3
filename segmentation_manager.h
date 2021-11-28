//
// Created by DaNTe on 28.11.2021.
//

#ifndef OS3_SEGMENTATION_MANAGER_H
#define OS3_SEGMENTATION_MANAGER_H

#include "stdbool.h"


struct segment {
    int pages_count;
    bool *page_free;
    void **pages;
};

void gen_segments();

struct virtual_address get_page();

void free_page(struct virtual_address address);

void *get_real_address(struct virtual_address address);

#endif //OS3_SEGMENTATION_MANAGER_H
