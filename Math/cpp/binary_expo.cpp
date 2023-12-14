#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll binExp(ll x, ll p)
{
    int res = 1;
    while (p)
    {
        if (p % 2) // if power is odd reduce it by 1 and multiply result with base
        {
            res *= x;
            p--;
        }
        else // else square the base and reduce the power by half
        {
            x *= x;
            p /= 2;
        }
    }
}

int main()
{
    return 0;
}