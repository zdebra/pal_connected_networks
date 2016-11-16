//
// Created by mangowebak on 16/11/2016.
//

#ifndef PAL_CONNECTED_NETWORKS_CERTIFICATE_H
#define PAL_CONNECTED_NETWORKS_CERTIFICATE_H

struct Cert {
    bool label;
    Cert* next;
};

/**
 *
 * @param c1
 * @param c2
 * @return true if c1 is before c2 or c1 is equal to c2
 */
bool lex_cmp(Cert* c1, Cert* c2);



#endif //PAL_CONNECTED_NETWORKS_CERTIFICATE_H
