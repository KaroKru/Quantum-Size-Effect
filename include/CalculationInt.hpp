#ifndef CALCULATIONINT_HPP
#define CALCULATIONINT_HPP

class CalculationInt
{
    public:
    CalculationInt();
    ~CalculationInt();

    virtual void calculation() = 0;
    virtual void saved() = 0;
};

#endif //CALCULATIONINT_HPP