#include <stdio.h>
#include "virtual_address.h"
#include "meme_manager.h"
#include "benchmark.h"
#include "tester.h"

int main() {
    printf("%i",check_meme_manager());
    /*
    void *test = get_real_address(temp);
    for (int i = 0; i < 10; i++) {
        unsigned char *tes = (unsigned char *) test + i;
        *tes = i;
    }
    for (int i = 0; i < 10; i++) {
        unsigned char *tes = (unsigned char *) test + i;
        printf("%i\n", *(unsigned char *) tes);
    }*/
    /*int *ints = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        ints[i] = i + 50;
    write_memory(temp, ints, sizeof(int) * 5);
    int *ints_copy = malloc(sizeof(int) * 5);
    read_memory(temp, ints_copy, sizeof(ints) * 5);
    for (int i = 0; i < 5; i++)
        printf("%i\n", ints_copy[i]);
    printf("Hello, World!\n");*/
    //for (int i = 1; i <= 9; i++)
    //    get_time(10000, 100, i * 100 * 1000);
    //printf("%f", );
    return 0;
}
