#pragma once

class TData
{
public:
    virtual TData* Copy() = 0; // создание копии
    ~TData() {} 
};
