#include <iostream>

int main()
{
    const int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}