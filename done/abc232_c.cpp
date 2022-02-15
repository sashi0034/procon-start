#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <map>
#include <numeric>

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











int main()
{
    int N, M;
    INPUT(N >> M);

    std::vector<std::vector<bool>> con_ab = std::vector<std::vector<bool>>(N);
    std::vector<std::vector<bool>> con_cd = std::vector<std::vector<bool>>(N);

    LOOP(i, N)
        con_ab[i] = std::vector<bool>(N);
        con_cd[i] = std::vector<bool>(N);
        LOOP(j, N)
            con_ab[i][j] = false;
            con_cd[i][j] = false;
        END
    END

    LOOP(i, M)
        int a, b;
        INPUT(a >> b);
        --a;
        --b;
        con_ab[a][b] = con_ab[b][a] = true;
    END

    LOOP(i, M)
        int c=0, d=0;
        INPUT(c >> d);
        --c; 
        --d;
        con_cd[c][d] = con_cd[d][c] = true;
    END

    auto perm = std::vector<int>(N);
    std::iota(std::begin(perm), std::end(perm), 0);

    do 
    {
        bool ok=true;
        LOOP(i, N)
        LOOP(j, N)
            int a2 = perm[i];
            int b2 = perm[j];

            if (con_ab[a2][b2] != con_cd[i][j])
            {
                ok=false;
                break;
            }
        END
        END
        if (ok) 
        {
            OUTPUT("Yes\n");
            return 0;
        }

    }while (std::next_permutation(std::begin(perm), std::end(perm)));
    
    
    OUTPUT("No\n");


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

