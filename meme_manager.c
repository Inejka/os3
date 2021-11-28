//
// Created by DaNTe on 28.11.2021.
//

#include "meme_manager.h"
#include "page_manager.h"
#include "virtual_address.h"
#include "stdbool.h"

bool init_memory(int count, int size) {
    gen_pages(count, size);
    gen_segments();
    return true;
}

struct virtual_address get_memory() {
    return get_page();
}

bool free_memory(struct virtual_address address) {
    free_page(address);
    return true;
}

void write_memory(struct virtual_address address, void *copy_from, int size) {
    void *real_address = get_real_address(address);
    for (int i = 0; i < size; i++)
        *(unsigned char *) (real_address + i + address.shift) = *(unsigned char *) (copy_from + i);
}

void read_memory(struct virtual_address address, void *copy_to, int size) {
    void *real_address = get_real_address(address);
    for (int i = 0; i < size; i++)
        *(unsigned char *) (copy_to + i) = *(unsigned char *) (real_address + i + address.shift);
}

void get_memory_by_bytes(int size) {
    while (size > 0) {
        get_page();
        size -= get_size();
    }
}