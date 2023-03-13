#include <iostream>
#include <string>
#include <vector>
#include "/home/anurag/Documents/C++/MySqueel/MySqueel/include/databases.hpp"
#include "/home/anurag/Documents/C++/MySqueel/MySqueel/include/commands.hpp"
#include "/home/anurag/Documents/C++/MySqueel/MySqueel/include/helpers.hpp"

#define clearScreen() printf("\033[H\033[J");

void printLogo()
{
    clearScreen();
    std::cout << "\t\t\t\t.-----------------------------------------------------------------." << std::endl;
    std::cout << "\t\t\t\t| M\tY\t\tS\tQ\tU\tE\tE\tL |" << std::endl;
    std::cout << "\t\t\t\t-------------------------------------------------------------------" << std::endl;
}

int main(void)
{
    printLogo();
    // Database new_database("mydb");
    // Database newer;
    // newer.getName();
    // new_database.getName();
    std::string str;
    std::cout << "> ";
    std::getline(std::cin >> std::ws, str);

    std::vector<std::string> command = splitString(str, ' ');
    std::cout << findCommand(command) << std::endl;
    return 0;
}