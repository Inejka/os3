//
// Created by DaNTe on 28.11.2021.
//

#include "benchmark.h"
#include "meme_manager.h"
#include "time.h"
#include "stdio.h"

double get_time(int page_count, int page_size, int bytes) {
    init_memory(page_count, page_size);
    clock_t start = clock();
    get_memory_by_bytes(bytes);
    clock_t stop = clock();
    //printf("%li\n", start);
    //printf("%li\n", stop);
    printf("%li\n", stop - start);
    return (double) ((stop - start) / CLOCKS_PER_SEC);
}