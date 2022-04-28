#pragma once

class TData
{
public:
    int mean_x;
    int mean_y;
    int mean_z;
    double cfc;
    virtual TData* Copy() = 0; // создание копии
    TData() : mean_x(0),  mean_y(0) , mean_z(0), cfc(0){};
    ~TData() {}
    TData(double cfcM) : cfc(cfcM) {};
    TData( int dgrx, int dgry, int dgrz, double cfc): mean_x(dgrx), mean_y(dgry), mean_z(dgrz), cfc (cfc){};
    bool operator < (const TData& N) const
    {return (mean_x < N.mean_x && mean_y < N.mean_y && mean_z < N.mean_z && cfc < N.cfc); }
    bool operator > (const TData& N) const
    {return (mean_x > N.mean_x && mean_y > N.mean_y && mean_z > N.mean_z && cfc > N.cfc); }
    bool operator == (const TData& N) const
    {return (mean_x == N.mean_x && mean_y == N.mean_y && mean_z == N.mean_z && cfc == N.cfc); }
    bool operator != (const TData& N) const
    {return (mean_x != N.mean_x && mean_y != N.mean_y && mean_z != N.mean_z && cfc != N.cfc); }
    /*TData& operator = (const TData& N)
    {
        TData p;
        p.mean_x = N.mean_x; 
        p.mean_y = N.mean_y;
        p.mean_z = N.mean_z;
        p.cfc = N.cfc;
        return p;
    }*/
    /*double operator << (const TData& N)
    {
        std::cout << N.cfc << std::endl;
    }*/
};
