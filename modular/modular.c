#include "modular.h"


void madd(mpz_t r, const mpz_t a, const mpz_t b, const mpz_t n)
{
    mpz_add(r, a, b);
    mpz_mod(r, r, n);
}