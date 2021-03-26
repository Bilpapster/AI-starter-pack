#include "BreadthFirstSearchAlgorithm.h"

BreadthFirstSearchAlgorithm::BreadthFirstSearchAlgorithm() {
    searchFrontier = new queue<State *>;
}

string BreadthFirstSearchAlgorithm::getAlgorithmName() const {
    return "BFS";
}

void BreadthFirstSearchAlgorithm::pushToSearchFrontier(State *stateToPush) {
    searchFrontier->push(stateToPush);
}

bool BreadthFirstSearchAlgorithm::searchFrontierIsEmpty() {
    return searchFrontier->empty();
}

unsigned int BreadthFirstSearchAlgorithm::getSizeOfSearchFrontier() const {
    return searchFrontier->size();
}

State *BreadthFirstSearchAlgorithm::extractTopFromSearchFrontier() {
    State *topElement = searchFrontier->front();
    searchFrontier->pop();
    return topElement;
}

void BreadthFirstSearchAlgorithm::performActionsOnUnvisited(State *&state) {
    searchFrontier->push(state);
}

BreadthFirstSearchAlgorithm::~BreadthFirstSearchAlgorithm() {
    delete searchFrontier;
}
