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






const char WALL='#';
const char FLOOR='.';



int main()
{
    ll H, W;
    INPUT(H >> W);
    vector<vector<int>> mat{};
    mat.resize(H, vector<int>(W));

    REP(i,H)
    {
        string str;
        INPUT(str);
        REP(j,W)
        {
            if (str[j]==WALL)
            {
                mat[i][j]=-1;
            }
            else
            {
                mat[i][j]=0;
            }
        }
    }

    std::queue<std::tuple<int,int>> que{};
    que.push(std::tuple<int,int>{0,0});

    int ans=1;
    while (que.size()>0)
    {
        int i=std::get<0>(que.front());
        int j=std::get<1>(que.front());
        que.pop();
        ans=std::max(ans,mat[i][j]+1);
      
        if (i+1<H && mat[i+1][j]==0)
        {
            que.push(std::tuple<int,int>{i+1,j});
            mat[i+1][j]=mat[i][j]+1;


        }
        if (j+1<W && mat[i][j+1]==0)
        {
            que.push(std::tuple<int,int>{i,j+1});
            mat[i][j+1]=mat[i][j]+1;


        }
    }
    
    OUTPUT(ans << "\n");



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

