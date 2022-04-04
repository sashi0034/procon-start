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





int Q;
const int N = 1048576;
ll A[N];
vector<int> t_i{};
vector<ll> x_i{};
vector<int> A_root{};


int find_root(int index)
{
    if (A_root[index]==index)
    {
        return index;
    }

    int root = find_root(A_root[index]);

    A_root[index]=root;
    return root;

}





int main()
{
    REP(i,N)
    {
        A[i]=-1;
    }

    INPUT(Q);
    t_i.resize(Q+1);
    x_i.resize(Q+1);
    for (int i=1; i<Q+1; ++i)
    {
        INPUT(t_i[i]);
        INPUT(x_i[i]);
        //x_i[i] = x_i[i]%N;
    }

    A_root.resize(N);
    for (int i=0; i<N; ++i)
    {
        A_root[i] = i;
    }

    for (int i=1; i<Q+1; ++i)
    {
        if (t_i[i]==1)
        {
            ll h=x_i[i];
            int root = find_root(h%N);
            A_root[root] = find_root((root+1)%N);

            A[root]=x_i[i];
        }
        else
        {
            OUTPUT(A[x_i[i]%N] << std::endl);
        }
    }


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

