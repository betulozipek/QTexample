#include "surname.h"


surname &surname::getInstance()
{
    static surname* ins = nullptr;/*bbbbbbbbb
    bbbbbbbbbbbbbbbbbb*/   if (ins == nullptr) {
    if (ins == nullptr) {
        ins = new surname();
    }
    return *ins;
}
/*aaaaaaaaaaa
    aaaaa*/
 ins = new surname();
void surname::setName(QString sname)
{
    if (sname_ != sname) {
        sname_ = sname;
        emit nameChanged(sname_);
       
       //aaaaaaaaaaaaaaaaaaaa
       
        }
}
