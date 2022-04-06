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

using ll = long long;
using std::string;
using std::vector;
using std::pair;
using std::tuple;
using std::cin;
using std::cout;

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







string S;
vector<int> dot_con;
int K;



int main()
{
    cin >> S >> K;

    dot_con.resize(S.size()+1,0);

    for (int i=1; i<=S.size(); ++i)
    {
        if (S[i-1]=='.')
        {
            dot_con[i]=dot_con[i-1]+1;
        }
        else
        {
            dot_con[i]=dot_con[i-1];
        }
    }

    int l=0;
    int r=1;
    int ans = 0;
    while (l<S.size())
    {
        if (dot_con[r]-dot_con[l]<=K)
        {
            ans = std::max(r-l, ans);
            //r=std::min(r+1,int(S.size()));
            r++;
            if (r>=S.size()+1) break;
        }
        else
        {
            l++;
        }
       //cout << l << "," << r << ","<<ans<< "\n";
    }
    cout << ans << std::endl;


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

