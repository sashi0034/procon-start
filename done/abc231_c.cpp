#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>

#define PI  3.1415926535897931;
#define LOOP(i, max)    for (int i=0; i<max; ++i){
#define END     }
#define INPUT(value)  std::cin >> value;
#define OUTPUT(value)  std::cout << value << "\n";

using ll = long long;

namespace good
{
    int get_order(long long n);
    bool is_between(double n, double min, double max);
    int get_sign(double n);
    double get_distance(double x, double y);
    double to_rad(double deg);
    double to_deg(double rad);
    std::string to_bin(long long num10);
}






int main()
{
    ll N, Q;
    INPUT(N >> Q);
    auto A = std::vector<ll>(N);
    auto x_i = std::vector<ll>(Q);

    LOOP(i, N)
        INPUT(A[i]);    
    END
    LOOP(i, Q)
        INPUT(x_i[i]);
    END
    std::sort(A.begin(), A.end());

    LOOP(i, Q)
        ll x = x_i[i];

        ll ok = N;
        ll ng = -1;

        while (ok - ng > 1)
        {
            int cur = (ok+ng)/2;
            if (x<=A[cur]) ok = cur;
            else ng = cur;
        }

        OUTPUT(N - ok << "\n");
        

    END




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
    std::string to_bin(long long num10)
    {
        std::string ret = "";
        while(num10 != 0)
        {
            ret = (num10 % 2 == 0 ? "0" : "1") + ret;
            num10 /= 2;
        }
        return ret;
    }
}

