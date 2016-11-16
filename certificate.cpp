//
// Created by mangowebak on 16/11/2016.
//

#include "certificate.h"

bool lex_cmp(Cert* c1, Cert* c2)
{

    if(c1 == nullptr) {
        return true;
    }
    if(c2 == nullptr) {
        return false;
    }
    if(c1->label != c2->label) {
        return c1->label < c2->label;
    }
    return lex_cmp(c1->next, c2->next);

};