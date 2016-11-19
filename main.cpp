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
    CertHead *certificate;
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

void cut_leaf(Node &node) {

    node.neighbor_count = 0;

    // push the certificate to where is neighbor count non zero (parent)
    Edge *cur = node.neighbor;
    while(cur->target->neighbor_count == 0) {
        cur = cur->next;
    }
    Node *parent = cur->target;

    if(node.certificate->first == nullptr) {
        Cert *head = new Cert();
        head->label = 0;
        Cert *tail = new Cert();
        tail->label = 1;
        head->next = tail;
        node.certificate->first = head;
    }

    push(*parent->certificate, *node.certificate);
    parent->neighbor_count--;

}

int main() {

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
        if(nodes[start].certificate == nullptr) {
            nodes[start].certificate = new CertHead();
        }

        add_neighbor(nodes[start], nodes[finish], edges[edge_counter]);
        edge_counter++;


        nodes[finish].neighbor_count++;
        if(nodes[finish].certificate == nullptr) {
            nodes[finish].certificate = new CertHead();
        }


        add_neighbor(nodes[finish], nodes[start], edges[edge_counter]);
        edge_counter++;
    }


    // run algorithm
    int cutted;
    do {
        cutted = 0;

        for(int i=0; i<nodes_total; i++) {

            // if it is a leaf
            if(nodes[i].neighbor_count == 1) {

                cut_leaf(nodes[i]);
                cutted++;

            }

        }

    } while(cutted > 0);

    int c;
    for(int i=0; i<nodes_total; i++) {
        if(nodes[i].neighbor_count != 0) {

            Node n = nodes[i];
            c++;

        }
    }


    delete nodes;
    delete edges;

    return 0;
}