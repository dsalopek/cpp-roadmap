#ifndef STRATEGY_DUCK_H

#define STRATEGY_DUCK_H

#include "QuackBehavior.hh"
#include "FlyBehavior.hh"
#include <memory>

class Duck {
public:
    Duck() = delete;

    Duck(std::shared_ptr<QuackBehavior> quackBehavior,
         std::shared_ptr<FlyBehavior>   flyBehavior);

    ~Duck() = default;

    void setFlyBehavior(std::shared_ptr<FlyBehavior> flyBehavior);

    void setQuackBehavior(std::shared_ptr<QuackBehavior> quackBehavior);

    void performQuack();

    void performFly();

    virtual void display() = 0;

private:
    std::shared_ptr<QuackBehavior> quackBehavior_;
    std::shared_ptr<FlyBehavior>   flyBehavior_;
};

#endif // STRATEGY_QUACK_H
