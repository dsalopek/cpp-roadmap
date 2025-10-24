#ifndef STRATEGY_FLYWITHWINGS_H

#define STRATEGY_FLYWITHWINGS_H

#include "FlyBehavior.hh"

class FlyWithWings : public FlyBehavior
{
public:
    virtual ~FlyWithWings() = default;
    void fly() override;
};

#endif // STRATEGY_FLYWITHWINGS_H