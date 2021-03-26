#include "AStarSearchAlgorithm.h"

string AStarSearchAlgorithm::getAlgorithmName() const {
    return "A*";
}

unsigned short AStarSearchAlgorithm::defineHeuristicValueOf(State *&state) {
    return BestFirstSearchAlgorithm::defineHeuristicValueOf(state) + state->getDepth();
}
