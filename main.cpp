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


    /*
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



    return 0;
}