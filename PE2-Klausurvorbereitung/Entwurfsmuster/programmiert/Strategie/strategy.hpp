#ifndef _STRATEGY_HPP
#define _STRATEGY_HPP

#include <string>

class Strategy{
public:
    virtual std::string foo() = 0;
};

class fo: public Strategy{
public:
    std::string foo() override;
};

class ba: public Strategy{
public:
    std::string foo() override;
};

class Kontext{
    Strategy *_strat;
public:
    Kontext(Strategy* strat = nullptr);
    void setStrategy(Strategy* strat);
    std::string something();
};

#endif