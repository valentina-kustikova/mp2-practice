 struct TData
{
    double coeff; // ���������� ����� �������
    int degree;   // ������� �������
    int degx, degy, degz;// ������� x, y, z
    int operator==(const TData* data) const
    {
        return (this->degree == data->degree) && (this->coeff == data->coeff);
    }
    int operator!=(const TData* data) const
    {
        return (this->degree != data->degree) || (this->coeff != data->coeff);
    }
};