#pragma once

class TData
{
public:
    virtual TData* Copy() = 0; // создание копии
    ~TData() {} 
    virtual int operator==(const TData& data) const;
    virtual int operator<(const TData& data) const;
    virtual int operator>(const TData& data) const;
    virtual int operator+(const TData& data) const;
};
