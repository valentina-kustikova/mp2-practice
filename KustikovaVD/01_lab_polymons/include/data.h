#pragma once

class TData
{
public:
    int dgr_x;
    int dgr_y;
    int dgr_z;
    double cfc;
    //virtual TData* Copy() = 0; // создание копии
    ~TData() {} 
    bool operator < (const TData& N) const
    {return (dgr_x < N.dgr_x && dgr_y < N.dgr_y && dgr_z < N.dgr_z && cfc < N.cfc); }
    bool operator > (const TData& N) const
    {return (dgr_x > N.dgr_x && dgr_y > N.dgr_y && dgr_z > N.dgr_z && cfc > N.cfc); }
    bool operator == (const TData& N) const
    {return (dgr_x == N.dgr_x && dgr_y == N.dgr_y && dgr_z == N.dgr_z && cfc == N.cfc); }

};
