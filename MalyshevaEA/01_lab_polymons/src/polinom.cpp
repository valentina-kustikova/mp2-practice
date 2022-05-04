#include "polinom.h"

polinom::polinom()
{
    
}

void polinom::vod(const string& s)
{
    string str = s;
    monom tmp;
    string cf1 = "", m = "";
    while(str.length() > 0)
    {
        tmp.cf = 0.0;
        tmp.stx = 0;
        tmp.sty = 0;
        tmp.stz = 0;
        int i = 1;
        if ((str[0] != '-') && (str[0]) != '+')
        {str.insert(0, "+");}
        while((str[i] != '+') && (str[i] != '-') && (i < str.length() - 1))
        {
            i++;
        }

        //if ((str[i] != '+') || (str[i] != '-')) {i--;}
        if (str[0] == '+')
        {m = str.substr(1, i);}
        else if(str[0] == '-')
        {m = str.substr(0, i + 1);}
        else{m = str.substr(0, i);}

        int j = 0;
        while (((m[j] != 'x') && (m[j] != 'y') && (m[j] != 'z')) && (j < m.length() - 1))
        {
            j++;
        }
        if (m[0] == '-')
        {
            int f = 0;
            int i1 = 0;
            while (i1 < m.length())
            {
                if ((m[i1] == 'x') || (m[i1] == 'y') || (m[i1] == 'z'))
                {f = 1;}
                i1++;
            }
            if (f == 0)
            {cf1 = m.substr(0, j + 1);}
            else 
            {
                cf1 = m.substr(0, j);
            }
            if ((m[1] == 'x') || (m[1] == 'y') || (m[1] == 'z'))
            {cf1 = "-1";}
        }
        else if(j == 0)
        {cf1 = "1.0";}
        else
        {
            cf1 = m.substr(0, j);
        }
        tmp.cf = atof(cf1.c_str());

        j = 0;
        string s2 = "";
        while(j < m.length())
        {
            switch (m[j])
            {
            case 'x':
                {
                    if ((j + 2 < m.length()) && (m[j + 1] == '^'))
                    {
                        s2 = m[j + 2];
                        tmp.stx = atof(s2.c_str());
                    }
                    else 
                    {
                        tmp.stx = 1;
                    }
                }
                break;
            case 'y':
                {
                    if ((j + 2 < m.length()) && (m[j + 1] == '^'))
                    {
                        s2 = m[j + 2];
                        tmp.sty = atof(s2.c_str());
                    }
                    else 
                    {
                        tmp.sty = 1;
                    }
                }
                break;
            case 'z':
                {
                    if ((j + 2 < m.length()) && (m[j + 1] == '^'))
                    {
                        s2 = m[j + 2];
                        tmp.stz = atof(s2.c_str());
                    }
                    else 
                    {
                        tmp.stz = 1;
                    }
                }
                break;
            default:
                break;
            }
            j++;
        }

        mon.pushback(tmp);
        if (str[0] == '+')
        {
            j++;
        }
        if ((str[j - 1] == '+') || ((str[j - 1] == '-')))
        {j--;}
        str.erase(0, j);
    }
    //ochered();
    //ochered();
}

polinom::polinom(const string& s)
{
    vod(s);
    /*string str = s;
    monom tmp;
    string cf1 = "", m = "";
    while(str.length() > 0)
    {
        tmp.cf = 0.0;
        tmp.stx = 0;
        tmp.sty = 0;
        tmp.stz = 0;
        int i = 1;
        if ((str[0] != '-') && (str[0]) != '+')
        {str.insert(0, "+");}
        while((str[i] != '+') && (str[i] != '-') && (i < str.length() - 1))
        {
            i++;
        }

        //if ((str[i] != '+') || (str[i] != '-')) {i--;}
        if (str[0] == '+')
        {m = str.substr(1, i);}
        else if(str[0] == '-')
        {m = str.substr(0, i + 1);}
        else{m = str.substr(0, i);}

        int j = 0;
        while (((m[j] != 'x') && (m[j] != 'y') && (m[j] != 'z')) && (j < str.length() - 1))
        {
            j++;
        }
        if (m[j] == '-')
        {cf1 = "-1";}
        else if(j == 0)
        {cf1 = "1.0";}
        else
        {cf1 = m.substr(0, j);}
        tmp.cf = atof(cf1.c_str());

        j = 0;
        string s2 = "";
        while(j < m.length())
        {
            switch (m[j])
            {
            case 'x':
                {
                    if ((j + 2 < m.length()) && (m[j + 1] == '^'))
                    {
                        s2 = m[j + 2];
                        tmp.stx = atof(s2.c_str());
                    }
                    else 
                    {
                        tmp.stx = 1;
                    }
                }
                break;
            case 'y':
                {
                    if ((j + 2 < m.length()) && (m[j + 1] == '^'))
                    {
                        s2 = m[j + 2];
                        tmp.sty = atof(s2.c_str());
                    }
                    else 
                    {
                        tmp.sty = 1;
                    }
                }
                break;
            case 'z':
                {
                    if ((j + 2 < m.length()) && (m[j + 1] == '^'))
                    {
                        s2 = m[j + 2];
                        tmp.stz = atof(s2.c_str());
                    }
                    else 
                    {
                        tmp.stz = 1;
                    }
                }
                break;
            default:
                break;
            }
            j++;
        }

        mon.pushback(tmp);
        if (str[0] == '+')
        {
            j++;
        }
        if ((str[j - 1] == '+') || ((str[j - 1] == '-')))
        {j--;}
        str.erase(0, j);
    }
    ochered();*/
}

polinom::polinom(const polinom& p)
{
    //mon = p.mon;
    for (int i = 0; i < p.mon.size; i++)
    {
        mon.pushback(p.mon[i]);
    }
}

/*void polinom::privpodob()
{
    if (this->mon.getsize() == 0) 
    {return;}
    polinom res;
    res.mon.clear();
    node<monom>* data1;
    data1 = this->mon.gethead();
    node<monom>* data2 = data1->pnext;
    while(data1)
    {
        while(data2)
        {

        }
    }
}*/

void polinom::privpodob()
{
    int f1 = 0;
    polinom res;
    //monom monom1(1, -1, -1, -1);
    //res.mon.pushback(monom1);
    monom tmpm;
    for (int i = 0; i < this->mon.getsize(); i++)
    {
        tmpm = this->mon[i];
        for (int j = i + 1; j < this->mon.getsize(); j++)
        {
            if (this->mon[i] == this->mon[j])
            {
                tmpm = tmpm + this->mon[j];                
            }
        }
        
        f1 = 0;
        for (int j = 0; j < res.mon.getsize(); j++)
        {
            if (res.mon[j] == tmpm)
            {
                f1 = 1;
            }
        }

        if (f1 == 0) //&& (fabs(tmpm.cf) > 0.00001))
        {res.mon.pushback(tmpm);}
    }
    //*this = res;
    mon.clear();
    for (int i = 0; i < res.mon.size; i++)
    {
        if (fabs(res.mon[i].cf) > 0.00001)
        {mon.pushback(res.mon[i]);}
    }
}

void polinom::ochered()
{
    monom tmp1, tmp2, tmp3, tmp4;
    for (int i = 0; i < mon.getsize() - 1; i++) {
        for (int j = 0; j < mon.getsize() - i - 1; j++) {
        tmp3 = mon[j];
        tmp4 = mon[j + 1];
        if (tmp4 < tmp3) 
        {
            tmp1 = mon[j];
            tmp2 = mon[j + 1];
            mon.dlat(j);
            mon.dlat(j);
            mon.insert(tmp1, j);
            mon.insert(tmp2, j);
            }
        }
    }

}

polinom polinom::operator+(const polinom& p) const
{
    polinom res;
    //res.mon = mon;
    for (int i = 0; i < mon.size; i++)
    {
        res.mon.pushback(mon[i]);
    }
    polinom poli(p);
    //cout << res << endl;
    //cout << res.mon.getsize() << endl;
    //cout << poli << endl;
    //cout << poli.mon.getsize() << endl;
    for (int i = 0; i < poli.mon.getsize(); i++)
    {
        res.mon.pushback(poli.mon[i]);
    }
    //cout << res << endl;
    //cout << res.mon.getsize() << endl;
    if (res.mon.size > 1)
    {res.privpodob();
    res.ochered();}
    return res;
}

polinom polinom::operator*(const double a) const
{
    polinom poli, tmp;
    for (int i = 0; i < mon.size; i++)
    {
        tmp.mon.pushback(mon[i]);
    }
    for (int i = 0; i < tmp.mon.getsize(); i++)
    {
        poli.mon.insert(tmp.mon[i] * a, i);
    }
    if (poli.mon.size > 1)
    {poli.ochered();}
    return poli;
}

polinom polinom::operator-(const polinom& p) const
{
   // polinom res;
    polinom res(*this + p*(-1));
    //res = *this + p*(-1);
   /* for (int i = 0; i < tmp.mon.getsize(); i++)
    {
        res.mon.insert(tmp.mon[i] * m, i);
    }*/
    if (res.mon.size > 1)
    {res.privpodob();
    res.ochered();}
    return res;
}

polinom polinom::operator*(const monom& m) const
{
    polinom res, tmp;
    for (int i = 0; i < mon.size; i++)
    {
        tmp.mon.pushback(mon[i]);
    }
    for (int i = 0; i < tmp.mon.getsize(); i++)
    {
        res.mon.insert(tmp.mon[i] * m, i);
    }
    if (res.mon.size > 1)
    {res.privpodob();
    res.ochered();}
    return res;
}

/*polinom& polinom::operator=(const polinom& p) const
{
    polinom res1(p);
    res1.privpodob();
    res1.ochered();
    return res1;
}*/

polinom polinom::operator*(const polinom& p) const
{
    polinom res;
    polinom poli1;
    //poli1 = *this;
    for (int i = 0; i < mon.size; i++)
    {
        poli1.mon.pushback(mon[i]);
    }
    polinom poli(p);
    for (int i = 0; i < poli1.mon.getsize(); i++)
    {
        for (int j = 0; j < poli.mon.getsize(); j++)
        {
            res.mon.pushback(poli1.mon[i] * poli.mon[j]);
        }
    }
    if (res.mon.size > 1)
    {res.privpodob();
    res.ochered();}
    return res;
}

double polinom::operator() (double x, double y, double z) const
{
    double res = 0.0;
    for (int i = 0; i < this->mon.getsize(); i++)
    {
        res += (this->mon[i].cf) * pow(x, this->mon[i].stx) * pow(y, this->mon[i].sty) * pow(z, this->mon[i].stz);
    }
    return res;
}

bool polinom::operator==(const polinom& other) const
{
    return mon == other.mon;
}