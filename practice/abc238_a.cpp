#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n * log(2) > 2 * log(n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;    
}




