#ifndef CALCULATIONINT_HPP
#define CALCULATIONINT_HPP

class CalculationInt
{
  public:
    CalculationInt() = default;
    virtual ~CalculationInt() = default;

    virtual void calculation() = 0;
    virtual void saved() = 0;
};

#endif // CALCULATIONINT_HPP