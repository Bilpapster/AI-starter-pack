#include "BestFirstSearchAlgorithm.h"

BestFirstSearchAlgorithm::BestFirstSearchAlgorithm() {
    searchFrontier = new priority_queue<State *, vector<State *>, StateComparator>;
}

string BestFirstSearchAlgorithm::getAlgorithmName() const {
    return "Best First";
}

void BestFirstSearchAlgorithm::pushToSearchFrontier(State *stateToPush) {
    searchFrontier->push(stateToPush);
}

bool BestFirstSearchAlgorithm::searchFrontierIsEmpty() {
    return searchFrontier->empty();
}

unsigned int BestFirstSearchAlgorithm::getSizeOfSearchFrontier() const {
    return searchFrontier->size();
}

State *BestFirstSearchAlgorithm::extractTopFromSearchFrontier() {
    State *topElement = searchFrontier->top();
    searchFrontier->pop();
    return topElement;
}

void BestFirstSearchAlgorithm::performActionsOnUnvisited(State *&state) {
    state->setHeuristicValue(defineHeuristicValueOf(state));
    searchFrontier->push(state);
}

unsigned short BestFirstSearchAlgorithm::defineHeuristicValueOf(State *&state) {
    return state->manhattanDistance();
}

BestFirstSearchAlgorithm::~BestFirstSearchAlgorithm() {
    delete searchFrontier;
}
