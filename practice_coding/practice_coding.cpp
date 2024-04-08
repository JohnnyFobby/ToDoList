#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    std::string name;
    char input;

    std::cout << "Let's create a todo list!!" << std::endl;

    while (true) {
        std::cout << "To start, let's get some basic information from you.\nCan I have your name? Y/N ";
        std::cin >> input;

        if (input == 'Y' || input == 'y') {
            std::cout << "Great!!\nPlease enter your name..." << std::endl;
            std::cin.ignore();  // Ignore newline character from previous input
            std::getline(std::cin, name);  // Read entire line for the name

            std::ofstream list("todo_list.txt");
            list << "Name: " << name << std::endl;
            std::cout << "Nice to meet you, " << name << "!\nYour name has been stored in a 'todo_list.txt' file." << std::endl;
            break;  // Exit loop if a valid input is given
        }
        else if (input == 'N' || input == 'n') {
            std::ofstream list("todo_list.txt");
            list << "Name: User answered No" << std::endl;
            std::cout << "Okay!" << std::endl;
            break;  // Exit loop if a valid input is given
        }
        else {
            std::cout << "Invalid input.\nPlease enter Y or N..." << std::endl;
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
        }
    }

    int list_amount;

    while (true) {
        std::cout << "How many todo items would you like? **Integers only** ";
        std::cin >> list_amount;

        if (list_amount <= 0) {
            std::cout << "Please enter a valid number" << std::endl;
            std::cin.clear();  // Clear flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalids
        }
        else {
            break;
        }
    }

    std::ofstream itemListFile("todo_list.txt", std::ios_base::app);  // Open file in append mode

    for (int i = 0; i < list_amount; ++i) {
        std::cin.ignore();  // Ignore newline character from previous input
        std::string listItem;
        std::cout << "Great! Now enter the thing you want to do for # " << (i + 1)  << ": ";
        std::getline(std::cin, listItem);  // Read entire line for the list item
        itemListFile << "Todo " << (i + 1) << ": " << listItem << std::endl;
    }

    std::cout << "Great! Your list amount and the things you want to do have been added to the 'todo_list.txt' file :)" << std::endl;

    return 0;
}
