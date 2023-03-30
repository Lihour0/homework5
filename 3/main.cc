#include <iostream>
#include <limits>
#include <map>
#include <string>

void InputOnlyNum()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    const int TOTAL_ASCII = 127;
    for (int i = 0; i < TOTAL_ASCII + 1; i++)
    {
        std::cout << i << ": " << char(i) << "\n";
    }
}
