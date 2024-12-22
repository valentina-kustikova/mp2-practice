#include "stack.h"
#include <map>
#include <vector>



using namespace std;

class PosfixForm {
public:
    string virtual return_form() = 0;
    int virtual return_answer() = 0;
};

class PostfixFormArray : public PosfixForm {
private:
    string inf_form;
    string post_form;
    TArrayStack<string> stack;
public:
    PostfixFormArray() {};
    PostfixFormArray(string in);
    ~PostfixFormArray() {};
    string return_form() { return post_form; };
    int return_answer() { return 0; };
};


class PostfixFormList : public PosfixForm {
private:
    string inf_form;
    string post_form;
    TListStack<string> stack;
public:
    string return_form() {};
    int return_answer() {};
};

