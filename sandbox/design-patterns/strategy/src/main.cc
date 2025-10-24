#include "../include/MallardDuck.hh"
#include "../include/GreenWingTeal.hh"
#include "../include/LoudQuack.hh"
#include "../include/QuietQuack.hh"
#include "../include/FlyWithWings.hh"
#include "../include/NoFly.hh"
#include <memory>

int main()
{

    auto loud = std::make_shared<LoudQuack>();
    auto quiet = std::make_shared<QuietQuack>();

    auto flyWithWings = std::make_shared<FlyWithWings>();
    auto noFly = std::make_shared<NoFly>();

    MallardDuck mallard{loud, flyWithWings};
    GreenWingTeal greenWingTeal{quiet, noFly};

    mallard.display();
    mallard.performFly();
    mallard.performQuack();

    greenWingTeal.display();
    greenWingTeal.performFly();
    greenWingTeal.performQuack();

    mallard.setFlyBehavior(noFly);
    greenWingTeal.setQuackBehavior(loud);

    mallard.performFly();
    greenWingTeal.performQuack();

    return 0;
}