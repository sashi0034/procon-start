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
    ll N, M;

    std::cin >> N >> M;

    std::vector<std::string> S = std::vector<std::string>(N);
    std::vector<std::string> T = std::vector<std::string>(M);

    LOOP(i, N)
        std::cin >> S[i];
    END
    LOOP(i, M)
        std::cin >> T[i];
    END

    ll t_cur=0;
    LOOP(i, N)
        if (S[i]==T[t_cur])
        {
            t_cur++;
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
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
}

