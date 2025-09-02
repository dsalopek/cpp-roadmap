#include <iostream>
#include <string>

std::string getUserName(int userNumber) {
    std::string name{};
    std::cout << "Enter the name of person #" << userNumber << ": ";
    std::getline(std::cin >> std::ws, name);
    return name;
}

int getUserAge(std::string_view userName) {
    int age{};
    std::cout << "Enter the age of " << userName << ": ";
    std::cin >> age;
    return age;
}

void printAgeComparison(std::string_view olderName, int   olderAge,
                        std::string_view youngerName, int youngerAge) {
    std::cout << olderName << " (age " << olderAge << ") is older than " <<
            youngerName <<
            " (age" << youngerAge << ").\n";
}

int main() {
    const std::string name1{getUserName(1)};
    const int         age1{getUserAge(name1)};

    const std::string name2{getUserName(2)};
    const int         age2{getUserAge(name2)};

    if (age1 > age2) {
        printAgeComparison(name1, age1, name2, age2);
    } else {
        printAgeComparison(name2, age2, name1, age1);
    }

    // Enter the name of person #1: John Bacon
    // Enter the age of John Bacon: 37
    // Enter the name of person #2: David Jenkins
    // Enter the age of David Jenkins: 44
    // David Jenkins (age 44) is older than John Bacon (age 37).

    return 0;
}
