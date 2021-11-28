//
// Created by DaNTe on 28.11.2021.
//

#include "tester.h"
#include "stdbool.h"
#include "malloc.h"
#include "meme_manager.h"
#include "virtual_address.h"

struct virtual_address temp;


bool check_init() {
    return init_memory(20, 2048);
}

bool check_get_page() {
    temp = get_page();
    return !(temp.segment_number == -1 || temp.page_number == -1);
}

bool check_free_page() {
    return free_memory(temp);
}

bool check_read_write() {
    int *ints = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        ints[i] = i + 50;
    write_memory(temp, ints, sizeof(int) * 5);
    int *ints_copy = malloc(sizeof(int) * 5);
    read_memory(temp, ints_copy, sizeof(ints) * 5);
    for (int i = 0; i < 5; i++)
        if (ints_copy[i] != ints[i])return false;
    return true;
}

bool check_meme_manager() {
    return check_init() && check_get_page() && check_read_write() && check_free_page();
}