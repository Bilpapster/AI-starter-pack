#include "DepthFirstSearchAlgorithm.h"

/**
 * Constructs a DFS object with a stack implementation for the
 * search frontier. The indirectly called constructor of the
 * super class initializes the set of closed states, implemented
 * as an unordered map.
 */
DepthFirstSearchAlgorithm::DepthFirstSearchAlgorithm() {
    searchFrontier = new stack<State *>;
}

/**
 * Simple getter for the name of the DFS algorithm. The method finds
 * utility only for result printing purposes.
 *
 * @return the name of the algorithm ("DFS").
 */
string DepthFirstSearchAlgorithm::getAlgorithmName() const {
    return "DFS";
}

/**
 * Executes all necessary actions in order to insert a state into the search
 * frontier. In the case of DFS, the given state is just pushed at the top of
 * the search frontier stack.
 */
void DepthFirstSearchAlgorithm::pushToSearchFrontier(State *stateToPush) {
    searchFrontier->push(stateToPush);
}

/**
 * Simple method that checks whether the search frontier stack is empty.
 * Implementing this check in a separate method offers easy handling of
 * inheritance and enhanced code readability.
 *
 * @return true if the search frontier stack is empty, else false.
 */
bool DepthFirstSearchAlgorithm::searchFrontierIsEmpty() {
    return searchFrontier->empty();
}

/**
 * Getter for the size attribute of the search frontier stack. Implementing
 * such a getter offers easy handling of inheritance among the search algorithms
 * and enhances code readability.
 *
 * @return the size of the search frontier stack.
 */
unsigned int DepthFirstSearchAlgorithm::getSizeOfSearchFrontier() const {
    return searchFrontier->size();
}

/**
 * Extracts the top element from the search frontier stack. The
 * top element is popped out of the stack before returned, so
 * that the stack's top is now pointing to the next element.
 *
 * @return the top element of the stack, which is popped.
 */
State *DepthFirstSearchAlgorithm::extractTopFromSearchFrontier() {
    State *topElement = searchFrontier->top();
    searchFrontier->pop();
    return topElement;
}

/**
 * Performs all necessary actions on an unvisited state. The given state must
 * be checked to not belong to the closed set of already visited and expanded
 * states. In case of the DFS algorithm, the given state is just pushed at the
 * top of the search frontier stack.
 *
 * @param state the state to push at the top of the search frontier stack.
 */
void DepthFirstSearchAlgorithm::performActionsOnUnvisited(State *&state) {
    searchFrontier->push(state);
}

/**
 * Executes all necessary actions when a DFS object needs to be erased from
 * memory. In the case of DFS, the search frontier stack is deleted.
 * The indirectly called destructor of the super class takes care of deleting
 * the closed set unordered map.
 */
DepthFirstSearchAlgorithm::~DepthFirstSearchAlgorithm() {
    delete searchFrontier;
}
