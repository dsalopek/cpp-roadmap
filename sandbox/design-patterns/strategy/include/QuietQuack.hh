#ifndef STRATEGY_QUIETQUACK_H

#define STRATEGY_QUIETQUACK_H

#include "QuackBehavior.hh"

class QuietQuack : public QuackBehavior {
public:
    virtual ~QuietQuack() = default;

    void quack() override;
};

#endif // STRATEGY_QUIETQUACK_H
