#include <fstream>
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
    int choice;
    double balance;
    std::ifstream inFile("balance.txt");
    if (inFile)
    {
        inFile >> balance;
        inFile.close();
    }
    else
    {
        balance = 0;
    }
    std::cout << std::fixed << std::setprecision(2);

    do
    {
        std::cout << "ATM Menu\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: \n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Your balance is: $" << balance << "\n";
            break;
        case 2:
            double depositAmount;
            std::cout << "Enter the amount to deposit: $";
            std::cin >> depositAmount;
            if (depositAmount > 0)
            {
                balance += depositAmount;
                std::ofstream outFile("balance.txt");
                outFile << balance;
                outFile.close();

                time_t now = time(0);
                tm *ltm = localtime(&now);
                std::ofstream transactionsFile("transactions.txt", std::ios::app);
                transactionsFile << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " Deposit $"
                                 << depositAmount << "\n";
                transactionsFile.close();

                std::cout << "$" << depositAmount << " has been deposited to your account."
                          << "\n";
            }
            else
            {
                std::cout << "Invalid amount entered."
                          << "\n";
            }
            break;
        case 3:
            double withdrawAmount;
            std::cout << "Enter the amount to withdraw: $";
            std::cin >> withdrawAmount;
            if (withdrawAmount > 0 && withdrawAmount <= balance)
            {
                balance -= withdrawAmount;
                std::ofstream outFile("balance.txt");
                outFile << balance;

                time_t now = time(0);
                tm *ltm = localtime(&now);
                std::ofstream transactionsFile("transactions.txt", std::ios::app);
                transactionsFile << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
                                 << " Withdraw $" << withdrawAmount << "\n";
                transactionsFile.close();

                outFile.close();
                std::cout << "$" << withdrawAmount << " has been withdrawn from your account."
                          << "\n";
            }
            else
            {
                if (withdrawAmount > balance)
                {
                    std::cout << "Insufficient funds."
                              << "\n";
                }
                else
                {
                    std::cout << "Invalid amount entered.\n";
                }
                break;
            case 4:
                return 0;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 4);
}
