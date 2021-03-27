#include "BestFirstSearchAlgorithm.h"

/**
 * Constructs a BestFS object with a priority queue implementation for the
 * search frontier. The indirectly called constructor of the
 * super class initializes the set of closed states, implemented
 * as an unordered map.
 */
BestFirstSearchAlgorithm::BestFirstSearchAlgorithm() {
    searchFrontier = new priority_queue<State *, vector<State *>, StateComparator>;
}

/**
 * Simple getter for the name of the BestFS algorithm. The method finds
 * utility only for result printing purposes.
 *
 * @return the name of the algorithm ("BestFS").
 */
string BestFirstSearchAlgorithm::getAlgorithmName() const {
    return "Best First";
}

/**
 * Executes all necessary actions in order to insert a state into the search
 * frontier. In the case of BestFS, the given state is just pushed at the
 * the search frontier priority queue.
 */
void BestFirstSearchAlgorithm::pushToSearchFrontier(State *stateToPush) {
    searchFrontier->push(stateToPush);
}

/**
 * Simple method that checks whether the search frontier priority queue
 * is empty.
 * Implementing this check in a separate method offers easy handling of
 * inheritance and enhanced code readability.
 *
 * @return true if the search frontier priority queue is empty, else false.
 */
bool BestFirstSearchAlgorithm::searchFrontierIsEmpty() {
    return searchFrontier->empty();
}

/**
 * Getter for the size attribute of the search frontier priority queue.
 * Implementing such a getter offers easy handling of inheritance among
 * the search algorithms and enhances code readability.
 *
 * @return the size of the search frontier priority queue.
 */
unsigned int BestFirstSearchAlgorithm::getSizeOfSearchFrontier() const {
    return searchFrontier->size();
}

/**
 * Extracts the top (max) element from the search frontier .
 * The top element is popped out of the priority queue before returned,
 * so that the priority queue's top is now pointing to the next element.
 *
 * @return the top element of the priority queue, which is popped.
 */
State *BestFirstSearchAlgorithm::extractTopFromSearchFrontier() {
    State *topElement = searchFrontier->top();
    searchFrontier->pop();
    return topElement;
}

/**
 * Performs all necessary actions on an unvisited state. The given state must
 * be checked to not belong to the closed set of already visited and expanded
 * states. In case of the BestFS algorithm, the given state is just pushed at
 * the search frontier priority queue.
 *
 * @param state the state to push at the search frontier priority queue.
 */
void BestFirstSearchAlgorithm::performActionsOnUnvisited(State *&state) {
    state->setHeuristicValue(defineHeuristicValueOf(state));
    searchFrontier->push(state);
}

/**
 * Given a state object, defines its heuristic value, based on a heuristic
 * function the state object provides itself. In the case of BestFS, the
 * manhattan distance metric is used as a way to order the expanded states
 * inside the search frontier priority queue.
 *
 * @param state the state to define heuristic value for.
 * @return the heuristic value of the given state.
 */
unsigned short BestFirstSearchAlgorithm::defineHeuristicValueOf(State *&state) {
    return state->manhattanDistance();
}

/**
 * Executes all necessary actions when a BestFS object needs to be erased from
 * memory. In the case of BestFS, the search frontier priority queue is deleted.
 * The indirectly called destructor of the super class takes care of deleting
 * the closed set unordered map.
 */
BestFirstSearchAlgorithm::~BestFirstSearchAlgorithm() {
    delete searchFrontier;
}
