#ifndef STRATEGY_NOFLY_H

#define STRATEGY_NOFLY_H

#include "FlyBehavior.hh"

class NoFly : public FlyBehavior
{
public:
    void fly() override;
};

#endif // STRATEGY_NOFLY_H