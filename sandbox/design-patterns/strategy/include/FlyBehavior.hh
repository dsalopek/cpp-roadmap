#ifndef STRATEGY_FLY_H

#define STRATEGY_FLY_H

class FlyBehavior {
public:
    virtual void fly() = 0;

    virtual ~FlyBehavior() = default;
};

#endif // STRATEGY_FLY_H
