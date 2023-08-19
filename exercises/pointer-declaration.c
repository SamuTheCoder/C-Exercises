#include <stdio.h>

int main()
{
    int m = 10;
    int n, o;
    int *z;
    printf(" Here is m=%d, n and o are two integer variable and *z is an integer\n", m);
    z = &m;
    printf(" z stores the address of m  = %p\n", z); // z = &m makes z hold the address of m variable
    *z = 10;
    printf(" *z stores the value of m = %d\n", *z);
    printf(" &m is the address of m = %p\n", &m);
    printf(" &n stores the address of n = %p\n", &n);
    printf(" &o  stores the address of o = %p\n", &o);
    printf("&z stores the address of pointer z = %p\n", &z); //&z holds the address of the z pointer itself
}