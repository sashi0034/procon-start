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





vector<pair<int,int>> fromTo{};
vector<int> ok{};

bool check2(int fromFirst, int from, int index)
{
    if (fromFirst==from) return true;
    if (ok[index]==0) false;
    ok[index]=1;
    if (fromTo[index].first!=from && fromTo[index].first!=-1)
    {
        check2(fromFirst, index, fromTo[index].first);
    }
    else if (fromTo[index].second!=-1)
    {        
        check2(fromFirst, index, fromTo[index].second);
    }
    return false;
}




int main()
{
    int M{}, N{};
    INPUT(M >> N);

    
    string ans = "Yes";
    vector<int> A(M);
    vector<int> B(M);
    
    fromTo.resize(N,pair<int,int>{-1,-1});

    REP(i,M)
    {
        INPUT(A[i] >> B[i]);
    }


    REP(i,M)
    {
        if (fromTo[A[i]].second!=-1||fromTo[B[i]].second!=-1)
        {
            ans="No";
            break;
        }
        if (fromTo[A[i]].first==-1)
        {
            fromTo[A[i]].first=B[i];
        }
        else
        {
            fromTo[A[i]].second=B[i];
        }
        
        if (fromTo[B[i]].first==-1)
        {
            fromTo[B[i]].first=A[i];
        }
        else
        {
            fromTo[B[i]].second=A[i];
        }
    }
    
    if (ans=="Yes")
    {
        
        ok.resize(M,0);


        REP(i,M)
        {
            if (ok[i]==1)continue;
            
            if (check2(i,-1, i)) 
            {
                ans="No";
                break;
            }
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

