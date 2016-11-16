#include <iostream>
#include "certificate.h"

struct Edge;
struct Node;

struct Edge {
    Node *target;
    Edge *next;
};

struct Node {
    int neighbor_count;
    Edge *neighbor;
    //int label;
};

Node *nodes;

void add_neighbor(Node& source, Node& neighbor, Edge& edge) {
    if(source.neighbor == NULL) {
        edge.target = &neighbor;
        source.neighbor = &edge;
    } else {
        Edge* cur = source.neighbor;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        edge.target = &neighbor;
        cur->next = &edge;
    }
}

int main() {
/*
    int nodes_total, total_connections;
    Edge *edges;

    std::cin >> nodes_total;
    std::cin >> total_connections;

    nodes = new Node[nodes_total];
    edges = new Edge[total_connections*2];

    int start, finish;
    int edge_counter = 0;
    for(int i=0; i<total_connections; i++) {

        std::cin >> start;
        std::cin >> finish;

        nodes[start].neighbor_count++;
        nodes[start].label = start;
        add_neighbor(nodes[start], nodes[finish], edges[edge_counter]);
        edge_counter++;


        nodes[finish].neighbor_count++;
        nodes[finish].label = finish;
        add_neighbor(nodes[finish], nodes[start], edges[edge_counter]);
        edge_counter++;
    }



    // printing
    for(int i=0; i<nodes_total; i++) {
        std::cout << "node" << i << "("<< nodes[i].neighbor_count <<"): ";
        Edge* next = nodes[i].neighbor;
        while(next!=NULL) {
            std::cout << next->target->label << ", ";
            next = next->next;
        }
        std::cout << std::endl;
    }
     */

    // {1}
    Cert *h1 = new Cert();
    h1->label = 1;


    // {0,1}
    Cert *h2 = new Cert();
    h2->label = 0;
    Cert *c21 = new Cert();
    c21->label = 1;
    h2->next = c21;


    // {1, 1, 1}
    Cert *h3 = new Cert();
    Cert *c31 = new Cert();
    Cert *c32 = new Cert();
    h3->label = 1;
    c31->label = 1;
    c32->label = 1;
    h3->next = c31;
    c31->next = c32;

    CertHead *ch1 = new CertHead();
    ch1->first = h1;
    CertHead *ch2 = new CertHead();
    ch2->first = h2;
    CertHead *ch3 = new CertHead();
    ch3->first = h3;

    ch1->next = ch2;
    ch2->prev = ch1;
    ch2->next = ch3;
    ch3->prev = ch2;

    // {1}
    Cert *c1 = new Cert();
    c1->label = 1;
    CertHead *ch4 = new CertHead();
    ch4->first = c1;
    push(*ch1,*ch4);

    // {0}
    CertHead *ch5 = new CertHead();
    Cert *c2 = new Cert();
    c2->label = 0;
    ch5->first = c2;

    push(*ch1,*ch5);


    // {1, 1, 1, 1}
    Cert *c3 = new Cert();
    Cert *c4 = new Cert();
    Cert *c5 = new Cert();
    Cert *c6 = new Cert();
    c3->label = 1;
    c3->next = c4;
    c4->label = 1;
    c4->next = c5;
    c5->label = 1;
    c5->next = c6;
    c6->label = 1;

    CertHead *ch6 = new CertHead();
    ch6->first = c3;

    push(*ch1,*ch6);
    

    return 0;
}