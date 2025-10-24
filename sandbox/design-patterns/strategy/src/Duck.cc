#include "../include/Duck.hh"
#include "../include/FlyBehavior.hh"
#include "../include/QuackBehavior.hh"

Duck::Duck(std::shared_ptr<QuackBehavior> quackBehavior, std::shared_ptr<FlyBehavior> flyBehavior) : quackBehavior_{quackBehavior}, flyBehavior_{flyBehavior} {}

void Duck::setFlyBehavior(std::shared_ptr<FlyBehavior> flyBehavior) {
    flyBehavior_ = flyBehavior;
}

void Duck::setQuackBehavior(std::shared_ptr<QuackBehavior> quackBehavior) {
    quackBehavior_ = quackBehavior;
}

void Duck::performFly() {
    flyBehavior_->fly();
}

void Duck::performQuack() {
    quackBehavior_->quack();
}