// typedef int huge_int;
typedef unsigned int uint;

template <class T>
T FastPow(T base, uint exp)
{
    T result(1);
    while (exp)
    {
        if (exp & 1)
        {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}