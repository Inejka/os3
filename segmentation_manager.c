//
// Created by DaNTe on 28.11.2021.
//

#include "segmentation_manager.h"
#include "page_manager.h"
#include "stdio.h"
#include "malloc.h"
#include "stdbool.h"
#include "virtual_address.h"
#include "math.h"

int size;
struct segment **segments;

void gen_segments() {
    int pages_count = get_count();
    void **pages = get_pages();
    int current_page = 0;
    size = (1 + sqrt(1 + 8 * pages_count - 1)) / 2;
    segments = malloc(sizeof(struct segment *) * size);
    for (int i = 0; i < size; i++) {
        segments[i] = malloc(sizeof(segments));
        segments[i]->pages_count = i + 1;
        if (segments[i]->pages_count > pages_count - current_page)
            segments[i]->pages_count = pages_count - current_page;
        segments[i]->page_free = malloc(sizeof(bool *) * segments[i]->pages_count);
        for (int j = 0; j < segments[i]->pages_count; j++) {
            segments[i]->page_free[j] = malloc(sizeof(bool));
            segments[i]->page_free[j] = true;
        }
        segments[i]->pages = malloc(sizeof(void *) * segments[i]->pages_count);
        for (int j = 0; j < segments[i]->pages_count; j++) {
            segments[i]->pages[j] = malloc(sizeof(void *));
            segments[i]->pages[j] = pages[current_page];
            current_page++;
        }
    }
}

struct virtual_address get_page() {
    struct virtual_address temp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < segments[i]->pages_count; j++)
            if (segments[i]->page_free[j] == true) {
                segments[i]->page_free[j] = false;
                temp.page_number = j;
                temp.segment_number = i;
                temp.shift = 0;
                return temp;
            }
    temp.page_number = -1;
    temp.segment_number = -1;
    temp.shift = 0;
    return temp;
}

void free_page(struct virtual_address address) {
    segments[address.segment_number]->page_free[address.page_number] = true;
}

void *get_real_address(struct virtual_address address) {
    return segments[address.segment_number]->pages[address.page_number];
}


