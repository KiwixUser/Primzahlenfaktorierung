#include <stdio.h>

using u64 = unsigned __int64;

#define BASE   10
#define MAX_P  36
#define MAX_D  28

void main1 ()
{
    ::printf ("\t");
    for (u64 d = 0; d <= MAX_D; d++)
        ::printf ("  d_%llu\t", d);
    ::printf ("\n");

    for (u64 p = 2; p <= MAX_P; p++)
    {
        bool r[MAX_P+1] = {};
        u64 rr = 1;
        ::printf ("p=%llu\t", p);
        for (u64 d = 0; d <= MAX_D; d++)
        {
            int const q = rr <= p/2 ? rr : rr-p;
            if    (rr == 0) ::printf ("\t");
            else if (r[rr]) ::printf (".%3d\t", q);
            else            ::printf ("%3d\t", q);
            r[rr] = true;
            rr *= BASE;
            rr %= p;
        }
        ::printf ("\n");
    }
}

void main2 ()
{
    ::printf ("! p ");
    for (u64 d = 0; d <= MAX_D; d++)
        ::printf ("|| d<sub>%llu</sub>", d);
    ::printf ("\n|-\n");

    for (u64 p = 2; p <= MAX_P; p++)
    {
        bool r[MAX_P+1] = {};
        u64 rr = 1;
        ::printf ("| %2llu", p);
        for (u64 d = 0; d <= MAX_D; d++)
        {
            //int const q = rr <= p/2 ? rr : rr-p;
            int const q = rr;
            if    (rr == 0) ::printf ("|| ");
            else if (r[rr]) ::printf ("||style=\"color:#BBBBFF\"|%3d", q);
            else            ::printf ("||%3d", q);
            r[rr] = true;
            rr *= BASE;
            rr %= p;
        }
        ::printf ("\n|-\n");
    }
}

int main ()
{
    ::main2();
    return 0;
}