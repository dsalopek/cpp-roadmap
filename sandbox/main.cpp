#include <iostream>

double calculateDistanceTravelled(double initialHeight, int seconds);

int main() {
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;

    for (int i = 0; i <= 5; i++) {
        double heightAfterTime = calculateDistanceTravelled(height, i);
        std::cout << "At " << i << " seconds, the ball is at height: " << heightAfterTime << " meters.\n";
    }
}

double calculateDistanceTravelled(double initialHeight, int seconds) {
    const double GRAVITY_CONSTANT {9.8};
    double height {};

    height = initialHeight - (GRAVITY_CONSTANT * (seconds * seconds) / 2.0);
    if (height < 0.0) {
        height = 0.0;
    }

    return height;
}
