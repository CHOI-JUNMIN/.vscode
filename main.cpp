/*
#include <iostream>
int main()
{
    double num1, num2;

    std::cout << "ù ��° ���ڸ� �Է��ϼ���: ";
    std::cin >> num1;

    std::cout << "�� ��° ���ڸ� �Է��ϼ���: ";
    std::cin >> num2;

    double sum = num1 + num2;

    std::cout << "�� ������ ��: " << sum << std::endl;

    return 0;
}*/
#include <spdlog/spdlog.h>

int main(int argc, const char **argv)
{
    SPDLOG_INFO("Hello, world!");
    return 0;
}