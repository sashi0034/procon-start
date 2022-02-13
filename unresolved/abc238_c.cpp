
// mod の逆元を調べる

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

#define LOOP(i, max)    for (int i=0; i<max; i++){
#define END     }

using ll = long long;

int get_order(long long n)
{
    return (int)std::log10(n) + 1;
}


int main()
{
    long long n;
    std::cin >> n;

    long long sum = 0;
    int order = get_order(n);
    
    LOOP(i, order-1)
        ll nine = (ll(9 * std::pow(10, i))) % 998244353;
        ll nine2 = (nine+1)% 998244353;
        ll temp = (nine)*(nine2)/2;
        sum = (sum + temp)% 998244353;
        printf("%d\n", sum);
    END
    
    {
        long long a = ll(n-std::pow(10, order-1)+1) % 998244353 ;
        ll a2 = (a+1) % 998244353;
        sum += a * a2 /2;
    }
    std::cout << sum % 998244353 ;
    return 0;    
}




