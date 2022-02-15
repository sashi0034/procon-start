#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>

#define PI  3.1415926535897931;
#define LOOP(i, max)    for (int i=0; i<max; i++){
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



std::vector<std::vector<ll>> a_ij = std::vector<std::vector<ll>>(0);
std::vector<ll> L_i = std::vector<ll>(0);
ll N, X;

ll res = 0;



void dfs(ll i, ll cur_val)
{
    //OUTPUT("i, cur_val= " << i << "," << cur_val);
    if (i==N) 
    {
        if (cur_val==X) res++;
        return;
    }

    LOOP(j, L_i[i])
        /*
        **** この行でオーバーフローが起きないようにする
        */
        if (cur_val>X/a_ij[i][j]) continue;

        dfs(i+1, cur_val*a_ij[i][j]);
    END


}



int main()
{

    INPUT(N >> X);
    L_i.resize(N);
    a_ij.resize(N);
    
    LOOP(i, N)
        INPUT(L_i[i]);

        a_ij[i].resize(L_i[i]);
        LOOP(j, L_i[i])
            INPUT(a_ij[i][j]);
        END
    END

    dfs(0, 1);
    OUTPUT(res << "\n");

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

