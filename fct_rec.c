#include "main.h"
#include <unistd.h>
/**
 * fct_rec - convert to binary
 * @a: deciaml to convert
 *
 * Return: none
 */
void fct_rec(unsigned int a)
{
    unsigned int reste;

    if(a > 0)
    {
        reste = a % 2;
        fct_rec(a / 2);
        write(1, &reste, 1);
    }
}
