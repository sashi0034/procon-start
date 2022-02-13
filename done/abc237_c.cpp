#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

#define PI  3.1415926535897931;
#define LOOP(i, max)    for (int i=0; i<max; i++){
#define END     }

using ll = long long;

namespace good
{
    int get_order(long long n);
    bool is_between(double n, double min, double max);
    int get_sign(double n);
    double get_distance(double x, double y);
    double to_rad(double deg);
    double to_deg(double rad);
}











int main()
{
    std::string S;

    std::cin >> S;
    
    ll len = S.length();

    ll a_length_front = 0;
    ll a_length_back = 0;

    LOOP(i, len)
        ll cusor = len - i - 1;
        
        if (S[cusor]=='a')
        {
            a_length_back = a_length_back + 1;
        }
        else
        {
            break;
        }
    END

    if (len == a_length_back | len == 1)
    {
        std::cout << "Yes\n";
        return 0;
    }

    LOOP(i, len)
        ll cusor = i;
        
        if (S[cusor]=='a')
        {
            a_length_front = a_length_front + 1;
        }
        else
        {
            break;
        }
    END

    if (a_length_front>a_length_back)
    {
        printf("No");
        return 0;
    }


    bool ok = true;
    for (int i=0; i<(len); i++)
    {
        ll s1 = i + a_length_front ;
        ll s2 = len - a_length_back - i - 1;
        if (S[s1]!=S[s2]) 
        {
            ok = false;
            break;
        }
        if (s1==s2 || s2-s1==1) break;
    }

    if (ok) printf("Yes"); else printf("No");

    return 0;    
}












namespace good
{
    int get_order(long long n)
    {
        return (int)std::log10(n) + 1;
    }
    bool is_between(double n, double min, double max)
    {
        return (min <= n && n <= max);
    }
    int get_sign(double n)
    {
        return (n > 0) - (n < 0);
    }
    double get_distance(double x, double y)
    {
        return std::sqrt(x * x + y * y);
    }
    double to_rad(double deg)
    {
        return (deg / 180.0) * PI;
    }
    double to_deg(double rad)
    {
        return (rad * 180) / PI;
    }
}

