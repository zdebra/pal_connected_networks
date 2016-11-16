//
// Created by mangowebak on 16/11/2016.
//

#ifndef PAL_CONNECTED_NETWORKS_CERTIFICATE_H
#define PAL_CONNECTED_NETWORKS_CERTIFICATE_H

struct Cert {
    bool label;
    Cert *next;
};

struct CertHead {
    CertHead *next;
    CertHead *prev;
    Cert *first;
};


void push(CertHead &start, CertHead &new_head);

#endif //PAL_CONNECTED_NETWORKS_CERTIFICATE_H
