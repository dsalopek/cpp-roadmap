#ifndef STRATEGY_LOUDQUACK_H

#define STRATEGY_LOUDQUACK_H

#include "QuackBehavior.hh"

class LoudQuack : public QuackBehavior
{
public:
    virtual ~LoudQuack() = default;
    void quack() override;
};

#endif // STRATEGY_LOUDQUACK_H