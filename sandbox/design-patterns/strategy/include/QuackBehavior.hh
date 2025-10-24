#ifndef STRATEGY_QUACK_H

#define STRATEGY_QUACK_H

class QuackBehavior
{
public:
    virtual ~QuackBehavior() = default;
    virtual void quack() = 0;
};

#endif // STRATEGY_QUACK_H