 struct TData
{
    double coeff; // коэффицент перед мономом
    int degree;   // свертка степени
    int degx, degy, degz;// степень x, y, z
    int operator==(const TData* data) const
    {
        return (this->degree == data->degree) && (this->coeff == data->coeff);
    }
    int operator!=(const TData* data) const
    {
        return (this->degree != data->degree) || (this->coeff != data->coeff);
    }
};