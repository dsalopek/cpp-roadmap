#include "../include/MallardDuck.hh"
#include <memory>
#include <iostream>

MallardDuck::MallardDuck(std::shared_ptr<QuackBehavior> quackBehavior, std::shared_ptr<FlyBehavior> flyBehavior) : Duck(quackBehavior, flyBehavior) {}

void MallardDuck::display() {
    std::cout << "I am a mallard\n";
}