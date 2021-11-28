//
// Created by DaNTe on 28.11.2021.
//

#include "page_manager.h"
#include "malloc.h"

void **pages;
int count_r;
int size_r;

void gen_pages(int count, int size) {
    count_r = count;
    size_r = size;
    pages = malloc(count * sizeof(pages));
    for (int i = 0; i < count; i++)
        pages[i] = malloc(size);
}

int get_count() {
    return count_r;
}

void **get_pages() {
    return pages;
}

int get_size() {
    return size_r;
}
