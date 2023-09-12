/* Опишите функцию void array2struct(int ar[], struct pack_array *ps), которая
упаковывает массив из 32-ух элементов, содержащий только 0 и 1, в структуру
вида 
struct pack_array {
uint32_t array; // массив из 0 и 1
uint32_t count0 : 8; // количество 0 в массиве
uint32_t count1 : 8; // количество 1 в массиве
}
void array2struct(int ar[], struct pack_array *ps);
*/

#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 32};

struct pack_array {
    uint32_t array[SIZE];
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int ar[], struct pack_array *ps);
void printStruct(struct pack_array *ps);

int main(void) {
    struct pack_array s;
    s.count0 = 0;
    s.count1 = 0;
    int ar[SIZE] = {0, 1, 0, 0, 1, 1, 0, 1, 
                    1, 1, 1, 0, 1, 1, 0, 0, 
                    0, 1, 0, 0, 1, 1, 0, 1, 
                    0, 1, 0, 0, 1, 1, 0, 1};
    array2struct(ar, &s);
    printStruct(&s);
    return 0;
}

void array2struct(int ar[], struct pack_array *ps) {
    for (int i=0; i < SIZE; i++) {
        ps->array[i] = ar[i];
        if (ar[i]) {
            ps->count1++;
        }
        else {
            ps->count0++;
        }
    }
}

void printStruct(struct pack_array *ps) {
    printf("Array:\n");
    for (int i=0; i < SIZE; i++) {
        printf("%d ", ps->array[i]);
    }
    printf("\n");
    printf("count0 = %d\n", ps->count0);
    printf("count1 = %d\n", ps->count1);
}
