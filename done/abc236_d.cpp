#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>

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



int N;
std::vector<std::vector<int> > A = std::vector<std::vector<int> >();
std::vector<bool> used = std::vector<bool>();

std::vector<std::pair<int, int>> comb = {};
int ans=0;


void calc()
{
    if (comb.size()==N)
    {
        int r=0;
        // REP(i,N)
        // {
        //     r^=A[comb[i].first][comb[i].second];
        // }
        for (auto c : comb)
        {
            r^=A[c.first][c.second];
        }
        if (r>ans) ans=r;
        return;
    }




    int fir = 0;
    REP(i,2*N)
    {
        if (!used[i])
        {
            fir=i;
            used[i]=true;
            break;
        }
    }

    REP(i,2*N)
    {
        if (!used[i])
        {
            used[i]=true;
            comb.push_back(std::pair<int,int>{fir,i});
            calc();
            comb.pop_back();
            used[i]=false;
        }
    }

    used[fir]=false;



}






int main()
{
    INPUT(N);

    A.resize(2*N);
    REP(i, 2*N) {A[i].resize(2*N);}

    REP(i, 2*N-1)
    {
        for (int j=i+1; j<2*N; j++)
        {
            INPUT(A[i][j]);
            A[j][i] = A[i][j];
        }
    }

    used.resize(2*N);
    REP(i, 2*N) used[i]=false;

    calc();
    OUTPUT(ans << "\n");


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

