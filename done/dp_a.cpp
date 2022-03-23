#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>

#define PI  3.1415926535897931
#define LL_MAX   9223372036854775807
// LL_MAX ~= 10 ^ 18
#define INT_MAX   2147483647
// INT_MAX ~= 10 ^ 9
#define REP(i, end)    for (int i=0; i<(int)end; ++i)
#define INPUT(value)  std::cin >> value;
#define OUTPUT(value)  std::cout << value;

using ll = long long;
using std::string;
using std::vector;
using std::pair;
using std::tuple;

namespace my
{
    int get_order(long long n);
    bool is_between(double n, double min, double max);
    int get_sign(double n);
    double get_distance(double x, double y);
    double to_rad(double deg);
    double to_deg(double rad);
    std::string to_bin(long long num10);
}






int N;
std::vector<int> h_i{};
std::vector<int> min_cost{};


int cost_calc(int i)
{
    if (min_cost[i]!=-1)
    {
        return min_cost[i];
    }

    if (i==N-1)
    {
        min_cost[i]=0;
        return 0;
    }
    if (i==N-2)
    {
        min_cost[i]=std::abs(h_i[N-1]-h_i[N-2]);
        return min_cost[i];
    }


    int ret = std::min(
        cost_calc(i+1)+std::abs(h_i[i+1]-h_i[i]), 
        cost_calc(i+2)+std::abs(h_i[i+2]-h_i[i])
    );

    min_cost[i] = ret;
    return ret;
}




int main()
{
    INPUT(N);
    h_i.resize(N);
    REP(i,N)
    {
        INPUT(h_i[i]);
    }
    min_cost.resize(N, -1);
    

    std::cout << cost_calc(0) << std::endl;


    return 0;    
}












namespace my
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

