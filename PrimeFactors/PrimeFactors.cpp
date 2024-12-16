#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <intrin.h>
#include <Windows.h>

using u8  = unsigned __int8;
using u16 = unsigned __int16;
using u64 = unsigned __int64;

template <typename T, u64 N> 
constexpr u64 size (const T(&)[N]) { return N; }

#include "Arithmetic.h"

static constexpr u8 Periode1 = 2*3*5*7;
static constexpr u8 Tab1[] =
{
    // 48 out of 210
    1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101,103,107,109,113,121,127,131,137,139,143,149,151,157,163,167,169,173,179,181,187,191,193,197,199,209,
};

static constexpr u16 Periode2 = 2*3*5*7*11*13;
static constexpr u16 Tab2[] =
{
    // 5760 out of 30030
    #include "primefactors.h"
};

// Faktor extrahieren und ausdrucken
static void ExtractFactor (u128& no, u64 const n)
{
    static constexpr u128 one = { 1 };
    int i = 0;
    while (::mod_128 (no, n) == 0)
    {
        no = ::div (no, n);
        i++;
    } 

    ::fprintf (stdout, "%llu", n);
    if (i != 1)
        ::fprintf (stdout, "^%d", i);
    if (::notequal (no, one))  // Restzahl != 1
        ::fprintf (stdout, " * ");
}

// Ist no durch n teilbar? Wenn ja, diese Primfaktoren abtrennen und auf stdout ausgeben (Hi-Teil Dividend < Divisor)
static void Check_96 (u128 & no, u64 n)
{
    if (::mod_96 (no, n))
        return;
    ::ExtractFactor (no, n);
}

// Ist no durch n teilbar? Wenn ja, diese Primfaktoren abtrennen und auf stdout ausgeben
static void Check_128 (u128 & no, u64 n)
{
    if (::mod_128 (no, n))
        return;
    ::ExtractFactor (no, n);
}

static void PrimeTest_Internal (u128 & no)
{
    // Test durch 2
    ::Check_128(no, 2);

    // Test durch ungerade Zahlen 3...209 (50% der Zahlen)
    for (u64 x = 3; x < Periode1; x += 2)
        ::Check_128(no, x);

    // Test durch Zahlen 210...30030, die nicht durch 2, 3, 5 und 7 teilbar sind (22.857% der Zahlen)
    for (u64 x  = Periode1;
             x  < Periode2  &&  
                  ! greater(::mult(x + Tab1[0], x + Tab1[0]), no); 
             x += Periode1)
    {
        if (no.hi >= x) for (auto E : Tab1) ::Check_128(no, x + E);
        else            for (auto E : Tab1) ::Check_96 (no, x + E);
    }

    // Test durch Zahlen ab 30030, die nicht durch 2, 3, 5, 7, 11 und 13 teilbar sind (19.18% der Zahlen)
    for (u64 x  = Periode2; 
                  ! greater(::mult(x + Tab2[0], x + Tab2[0]), no); 
             x += Periode2)
    {
        if (no.hi >= x) for (auto E : Tab2) ::Check_128(no, x + E);
        else            for (auto E : Tab2) ::Check_96 (no, x + E);
    }
}

static void PrimeTest (u128 const TestNumber)
{
    u128 constexpr one = { 1 };

    ::Print (stdout, TestNumber, " = ");
    ::fflush(stdout);
    if (::equal(TestNumber, u128{}))
        return;

    u128 no = TestNumber;
    ::PrimeTest_Internal (no);

    if (notequal (no, one))
        ::Print (stdout, no, "", "");

    ::fprintf (stdout, "\n");
}

///////////////////////////////////////////////////////////////////////

static void InternalMain(int argc, char** argv)
{
    switch (argc)
    {
    case 0: // Ausgabe der größten Primzahlenlücke < 2^64 (ca. 7 Minuten)
    {
        u128 no = ::ReadNo("18361375334787046697");
        ::Print(stderr, no, "\n");
        for (int i = 0; i <= 1550; i++, no = add(no, 1))
            ::PrimeTest(no);
    }
    break;

    case 1: // Faktorisierung von argv[0]
    {
        u128 const no = ::ReadNo(argv[0]);
        ::Print(stderr, no, "\n");
        ::PrimeTest(no);
    }
    break;

    case 2: // Faktorisierung von argv[0]+0...argv[0]+argv[1]
    {
        u128 no = ::ReadNo(argv[0]);
        int  cnt = ::atoi(argv[1]);
        ::Print(stderr, no, "..."); ::Print(stderr, no, ""); ::fprintf(stderr, " +%d\n", cnt);

        for (int i = 0; i <= cnt; i++, no = ::add(no, 1))
            ::PrimeTest(no);
    }
    break;

    default: // Faktorisierung aller Argumente argv[0]...argv[argc-1]
        for (int i = 0; i < argc; i++)
        {
            u128 const no = ::ReadNo(argv[i]);
            ::PrimeTest(no);
        }
        break;
    }
}

int main (int argc, char** argv)
{
    if (argc > 1 && ::atoi(argv[1]) == 0)
    {
        argv++;
        argc--;
        ::freopen (argv[0], "wb", stdout);
    }

    LONGLONG const t1 = ::GetTickCount64();
    ::InternalMain (argc - 1, argv + 1);
    LONGLONG const t2 = ::GetTickCount64();

    double   const dT = 0.001*(t2-t1);
    ::fprintf (stdout, "\n%8.3f sec\n", dT);
    ::fprintf (stderr, "\n%8.3f sec\n", dT);
    ::Beep(100, 200);
    return 0;
}

