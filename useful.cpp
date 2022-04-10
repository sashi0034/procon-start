
#if 0
namespace useful
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
#endif
