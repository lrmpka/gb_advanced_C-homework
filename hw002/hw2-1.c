/* Реализуйте функцию Swap, которая принимает два указателя и обменивает местами значения, 
на которые указывают эти указатели (нужно обменивать именно сами указатели, переменные должны оставаться в тех же адресах памяти).*/

#include <stdio.h>

void swap(int**, int**);

int main(void) {
    int a = 0;
    int b = 0;
    int* pa = &a;
    int* pb = &b;

    a = 255;
    b = 128;

    printf("Original:\n");
    printf("pa = %p; pb = %p;\n", pa, pb);
    printf("Value under pa address: %d\n", *pa);
    printf("Value under pb address: %d\n\n", *pb);

    swap(&pa, &pb);

    printf("After swap:\n");
    printf("pa = %p; pb = %p;\n", pa, pb);
    printf("Value under pa address: %d\n", *pa);
    printf("Value under pb address: %d\n\n", *pb);


    return 0;
}

void swap(int** p1, int** p2) {
    int* pbuf;

    pbuf = *p1;
    *p1 = *p2;
    *p2 = pbuf;
}