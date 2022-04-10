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
#define DEG2RAD  PI / 180.0
#define RAD2DEG  180.0 / PI

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
using std::priority_queue;
using std::cin;
using std::cout;
using std::endl;

using int_pair = pair<int, int>;
 priority_queue<int_pair> p_1_3{};
 vector<int> ok;

int main()
{
    ll N, K;
   

    cin >> N >> K;

    for (int i=0; i<N; ++i)
    {
        ll p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        int psum = p1+p2+p3;
        p_1_3.push(pair<int, int>(psum, i));
    }
    ok.resize(N,0);

    int val_k=0;
    
    for (int i=0; i<K; ++i)
    {
        auto pr = p_1_3.top();
        //cout << pr.first << "," << pr.second << endl;

        p_1_3.pop();
        ok[pr.second]=1;
        if (i==K-1) val_k = pr.first;
    }
    //cout << "---\n";
    for (int i=K; i<N; ++i)
    {
        auto pr = p_1_3.top();
        p_1_3.pop();
        //cout << pr.first << "," << pr.second << endl;

        if (val_k-pr.first<=300)
        {
            ok[pr.second]=1;
        }
        else
        {
            break;
        }
    }
    for (int i=0; i<N; ++i)
    {
        if (ok[i]==0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    



    return 0;    
}


