#include "bigint.hpp"
#include <iostream>
#include <limits>
#include <string>

int main()
{
	// unsigned long long int aboba1 = std::numeric_limits<unsigned long long int>::max();
	// unsigned int aboba2 = std::numeric_limits<unsigned int>::max();
	// bigint kekw(aboba1);
	// bigint keky(0);

	// bigint res = kekw + keky;
	
	// unsigned long long int a = std::stoull(res.get_num());
	// unsigned long long int b = aboba1;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl;
	// if (a == b) {
	// 	std::cout << "yay!\n";
	// }

    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;

    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;
}