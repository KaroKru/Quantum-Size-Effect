#ifndef CALCULATIONINTMOCK_HPP
#define CALCULATIONINTMOCK_HPP

#include "CalculationInt.hpp"
#include <gmock/gmock.h>

class CalculationIntMock : public CalculationInt
{
  public:
    MOCK_METHOD(void, calculation, (), (override));
    MOCK_METHOD(void, saved, (), (override));
};

#endif // CALCULATIONINTMOCK_HPP