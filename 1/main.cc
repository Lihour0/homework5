#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

void InputOnlyNum()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    double loanAmout, interestRatePerYear, yearsToCompletePayment;

    std::cout << "Enter the loan amount: ";
    std::cin >> loanAmout;
    std::cout << "Enter the interest rate per year (in percentage): ";
    std::cin >> interestRatePerYear;
    std::cout << "Enter the number of years to complete payment: ";
    std::cin >> yearsToCompletePayment;

    double monthlyInterestRate = (interestRatePerYear / 100) / 12;
    int numberOfMonths = yearsToCompletePayment * 12;

    double monthlyPayment = (loanAmout * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numberOfMonths));

    std::cout << "Month\tMonthly Payment\tInterest Paid\tRemaining Balance"
              << "\n";
    double remainingBalance = loanAmout;
    for (int i = 1; i <= numberOfMonths; i++)
    {
        double interestPaid = remainingBalance * monthlyInterestRate;
        remainingBalance -= (monthlyPayment - interestPaid);
        std::cout << i << "\t" << std::fixed << std::setprecision(2) << monthlyPayment << "\t\t" << interestPaid
                  << "\t\t" << remainingBalance << "\n";
    }
}
