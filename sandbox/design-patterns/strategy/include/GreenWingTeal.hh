#ifndef STRATEGY_GWTEAL_H

#define STRATEGY_GWTEAL_H
#include "Duck.hh"
#include <memory>

class GreenWingTeal : public Duck {
public:
    ~GreenWingTeal() = default;

    GreenWingTeal(std::shared_ptr<QuackBehavior> quackBheavior,
                  std::shared_ptr<FlyBehavior>   flyBheavior);

    void display() override;
};

#endif // STRATEGY_GWTEAL_H
