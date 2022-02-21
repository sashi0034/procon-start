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
#define REP(i, max)    for (int i=0; i<(int)max; ++i)
#define INPUT(value)  std::cin >> value;
#define OUTPUT(value)  std::cout << value << "\n";

using ll = long long;

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



int main()
{
    ll N{}, K{};
    INPUT(N >> K);
    
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq{};


    REP(i, K)
    {
        ll p;
        INPUT(p);

        pq.push(p);    
    }

    OUTPUT(pq.top());


    REP(i, N-K)
    {
        ll p;
        INPUT(p);
        if (p>pq.top())
        {
        pq.pop();
        pq.push(p);
        ll ans = pq.top();
        
        OUTPUT(ans);
        }
        else
        {
            OUTPUT(pq.top());
        }
    }



    // REP(i, N)
    // {
    //     ll p;
    //     INPUT(p);

    //     if ((i>=K-1 &&  p>pq.top()) || i==0)
    //     {
    //         pq.push(p);
    //         if(i>=K-1 &&  p>pq.top())
    //         {
            
    //         ll ans = pq.top();
    //         pq.pop();
    //         OUTPUT(ans);
    //         }
    //     }
    // }
    
}









// int main()
// {
//     ll N, K;
//     INPUT(N >> K);

//     std::vector<ll> arr{};


//     REP(i, N)
//     {

//         ll n{};
//         INPUT(n);
//         if (i==0) 
//         {
//             arr.push_back(n);
//         }
//         else
//         {
//             ll ok = i;
//             ll ng=-1;
//             while (ok - ng > 1)
//             {  
//                 ll cur = (ok+ng)/2;
//                 if (n>=arr[cur])
//                 {
//                     ok=cur;
//                 } 
//                 else
//                 {
//                     ng=cur;
//                 }
//             }
//             arr.insert(arr.begin()+ok, n);
//         }
//         if (i>=K-1)
//         {
//             OUTPUT(arr[K-1]);
//         }

//     }


//     return 0;    
// }












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

