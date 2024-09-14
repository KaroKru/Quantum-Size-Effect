#ifndef READDATAINTMOCK_HPP
#define READDATAINTMOCK_HPP

#include "ReadDataInt.hpp"
#include <gmock/gmock.h>

class ReadDataIntMock : public ReadDataInt
{
  public:
    MOCK_METHOD(void, readUserConfig, (), (override));
    MOCK_METHOD(void, readCellValues, (), (override));
    MOCK_METHOD(std::vector<ElementData>, getCellValue, (),
                (override));
    MOCK_METHOD(std::vector<ConfigData>, getSampleValue, (),
                (override));
};

#endif // READDATAINTMOCK_HPP