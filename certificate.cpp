//
// Created by mangowebak on 16/11/2016.
//

#include "certificate.h"

/**
 *
 * @param c1
 * @param c2
 * @return true if c2 should be before c1 (when should be swithed)
 */
bool lex_cmp(Cert &c1, Cert &c2)
{
    if(c1.label != c2.label) {
        return c1.label > c2.label;
    }

    if(c1.next == nullptr) {
        return false;
    }
    if(c2.next == nullptr) {
        return true;
    }

    return lex_cmp(*c1.next, *c2.next);

};

void swap(CertHead &c1, CertHead &c2, CertHead &c1_pred) {

    c1_pred.next = &c2;
    c1.next = c2.next;
    c2.next = &c1;

}

void swap_first(CertHead &c1, CertHead &c2) {
    c1.next = c2.next;
    c2.next = &c1;
}


void push(CertHead &start, CertHead &new_head) {

    if(lex_cmp(*start.first, *new_head.first)) {

        Cert *tmp = start.first;
        start.first = new_head.first;
        new_head.first = tmp;

        new_head.prev = &start;
        new_head.next = start.next;
        start.next->prev = &new_head;
        start.next = &new_head;

    } else {

        CertHead *cur = start.next;
        bool end = false;
        while(!lex_cmp(*cur->first, *new_head.first) && !end) {
            if(cur->next == 0) {
                end = true;
            } else {
                cur = cur->next;
            }
        }

        if(!end) {
            cur->prev->next = &new_head;
            new_head.prev = cur->prev;
            cur->prev = &new_head;
            new_head.next = cur;
        } else {

            cur->next = &new_head;
            new_head.prev = cur;

        }

    }

}