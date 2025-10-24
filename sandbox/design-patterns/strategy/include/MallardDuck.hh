#ifndef STRATEGY_MALLARD_H
#define STRATEGY_MALLARD_H

#include "Duck.hh"
#include <memory>

class MallardDuck : public Duck
{
public:
    MallardDuck(std::shared_ptr<QuackBehavior> quackBehavior, std::shared_ptr<FlyBehavior> flyBehavior);

    void display() override;
};

#endif // STRATEGY_MALLARD_H