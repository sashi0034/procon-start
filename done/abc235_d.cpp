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



ll a_in, N;
ll res=INT_MAX;







int main()
{
    INPUT(a_in >> N);

    ll M = std::pow(10, good::get_order(N));

    auto que = std::queue<ll>();
    
    std::vector<ll> d_arr = std::vector<ll>();
    d_arr.resize(M, -1);

    d_arr[1]=0;
    que.push(1);
    
    while ( true)
    {
        if (que.size()==0) break;

        ll c = que.front();
        que.pop();
        ll d_c = d_arr[c];

        ll op1 = c*a_in;
        if (op1 < M && d_arr[op1]==-1)
        {
            d_arr[op1] = d_c+1;
            que.push(op1);
        }
        
        if (c >= 10 && c%10!=0)
        {
            std::stringstream ss;
            ss << c;
            std::string str = ss.str();
            ll op2 = std::stoi(str[str.length()-1]+str.substr(0, str.length()-1));
            //OUTPUT(c << " > " << op2 << "\n");
            
            if (op2<M && d_arr[op2]==-1)
            {
                d_arr[op2] = d_c+1;
                que.push(op2);
            }
        }
        
    }
    
    OUTPUT(d_arr[N]);
    

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

