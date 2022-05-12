#include <iostream>
#pragma once

class TData
{
public:
    virtual TData* Copy() = 0; // создание копии

    virtual int operator==(const TData& a) const = 0;
    virtual int operator!=(const TData& a) const = 0;
    virtual int operator<(const TData& a) const = 0;
    virtual int operator>(const TData& a) const = 0;

    virtual ~TData() = default;
};
