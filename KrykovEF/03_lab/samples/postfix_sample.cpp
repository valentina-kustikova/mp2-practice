#include "postfix_form.h"

int main()
{
    string inf = "1+2-3+4";
    PostfixFormArray ex(inf);

    cout << ex.return_form();





    return 0;
}
