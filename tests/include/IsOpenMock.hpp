#ifndef ISOPENMOCK_HPP
#define ISOPENMOCK_HPP

#include <fstream>
#include <gmock/gmock.h>
#include <string>

class IsOpenMock : public std::ifstream
{
  public:
    IsOpenMock() : std::ifstream() {};

    MOCK_METHOD(bool, is_open, (), (const));
    MOCK_METHOD(void, close, (), ());
    MOCK_METHOD(std::istream&, getline, (std::string&), ());
};

#endif // ISOPENMOCK_HPP