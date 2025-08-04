#include <stdio.h>
#include "modular.h"

int main(void) {

    mpz_t a, b, c, n;
    mpz_inits(a, b, c, n, NULL);

    mpz_set_str(n, "7", 10);
    mpz_set_str(b, "4", 10);
    mpz_set_str(c, "5", 10);

    gmp_printf("Sum modulo %Zd:\n", n);
    madd(a, b, c, n);
    gmp_printf("%Zd + %Zd = %Zd\n", b, c, a);

    return 0;
}
