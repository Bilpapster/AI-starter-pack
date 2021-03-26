#include "DepthFirstSearchAlgorithm.h"

DepthFirstSearchAlgorithm::DepthFirstSearchAlgorithm() {
    searchFrontier = new stack<State *>;
}

string DepthFirstSearchAlgorithm::getAlgorithmName() const {
    return "DFS";
}

void DepthFirstSearchAlgorithm::pushToSearchFrontier(State *stateToPush) {
    searchFrontier->push(stateToPush);
}

bool DepthFirstSearchAlgorithm::searchFrontierIsEmpty() {
    return searchFrontier->empty();
}

unsigned int DepthFirstSearchAlgorithm::getSizeOfSearchFrontier() const {
    return searchFrontier->size();
}

State *DepthFirstSearchAlgorithm::extractTopFromSearchFrontier() {
    State *topElement = searchFrontier->top();
    searchFrontier->pop();
    return topElement;
}

void DepthFirstSearchAlgorithm::performActionsOnUnvisited(State *&state) {
    searchFrontier->push(state);
}

DepthFirstSearchAlgorithm::~DepthFirstSearchAlgorithm() {
    delete searchFrontier;
}
