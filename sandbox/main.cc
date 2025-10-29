#include <iostream>

void reduce(int ii);

int main() {
    reduce(10);
    return 0;
}


void reduce(int ii) {
    std::cout << ii << '\n';
    if (ii > 0) {
        reduce(ii - 1);
    }
}
