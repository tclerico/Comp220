#include <iostream>
#include "PriorityQueue.h"
#include "LinkedPriorityQueue.h"

int main() {
    PriorityQueue* pq = new LinkedPriorityQueue();

    pq->addItem("Clara", 2.5);
    pq->addItem("Renata", 3.4);
    pq->addItem("Selina", 1.1);
    pq->addItem("Claudia", 0.8);
    pq->addItem("Janice", 1.05);

    while (!pq->isEmpty()){
        std::cout << pq->dequeueHighestPriorityItem() << std::endl;
    }

    return 0;
}