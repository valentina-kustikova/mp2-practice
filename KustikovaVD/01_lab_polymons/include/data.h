#pragma once

class TData
{
public:
    virtual TData* Copy() = 0; // �������� �����
    ~TData() {} 
};
