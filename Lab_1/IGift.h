#pragma once


using std::string;
using std::cout;


class IGift {
public:
    virtual void getInformation() = 0;
    virtual ~IGift() = default;
};