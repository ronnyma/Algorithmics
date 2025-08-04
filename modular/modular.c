#include "modular.h"


void madd(mpz_t r, mpz_t a, mpz_t b, mpz_t n)
{
    mpz_add(r, a, b);
    mpz_mod(r, r, n);
}