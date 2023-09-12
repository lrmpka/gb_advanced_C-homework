/*Опишите функцию void struct2array(int ar[], struct pack_array *ps), которая
распаковывает структуру в массив из 32-ух элементов. Структура вида:
struct pack_array {
uint32_t array; // массив из 0 и 1
uint32_t count0 : 8; // количество 0 в массиве
uint32_t count1 : 8; // количество 1 в массиве
}
*/

#include <stdio.h>
#include <inttypes.h>

enum {SIZE = 32};

struct pack_array {
    uint32_t array[SIZE];
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void printArray(int ar[]);
void struct2array(int ar[], struct pack_array *ps);
void array2struct(int ar[], struct pack_array *ps);

int main(void) {
    struct pack_array s;
    s.count0 = 0;
    s.count1 = 0;
    int arout[SIZE] = {0};
    int arin[SIZE] = {0, 1, 0, 0, 1, 1, 0, 1, 
                    1, 1, 1, 0, 1, 1, 0, 0, 
                    0, 1, 0, 0, 1, 1, 0, 1, 
                    0, 1, 0, 0, 1, 1, 0, 1};

    array2struct(arin, &s);
    struct2array(arout, &s);
    printArray(arout);

    return 0;
}

void struct2array(int ar[], struct pack_array *ps) {
    for (int i=0; i < SIZE; i++) {
        ar[i] = ps->array[i];
    }
}

void printArray(int ar[]) {
    printf("arout[32] = ");
    for (int i=0; i < SIZE; i++) {
        printf("%d ", ar[i]);
    }
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