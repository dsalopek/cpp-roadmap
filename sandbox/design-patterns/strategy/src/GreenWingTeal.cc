#include "../include/GreenWingTeal.hh"
#include <memory>
#include <iostream>

GreenWingTeal::GreenWingTeal(std::shared_ptr<QuackBehavior> quackBehavior, std::shared_ptr<FlyBehavior> flyBehavior) : Duck(quackBehavior, flyBehavior) {}

void GreenWingTeal::display() {
    std::cout << "I am a green wing teal\n";
}