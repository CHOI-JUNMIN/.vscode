/*
#include <iostream>
int main()
{
    double num1, num2;

    std::cout << "첫 번째 숫자: ";
    std::cin >> num1;

    std::cout << "두 번째 숫자: ";
    std::cin >> num2;

    double sum = num1 + num2;

    std::cout << "숫자 합: " << sum << std::endl;

    return 0;
}*/

#include <spdlog/spdlog.h>

int main(int argc, const char **argv)
{
    SPDLOG_INFO("Hello, world!");
    return 0;
}
