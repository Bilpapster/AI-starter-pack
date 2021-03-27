#include "BreadthFirstSearchAlgorithm.h"

/**
 * Constructs a BFS object with a queue implementation for the
 * search frontier. The indirectly called constructor of the
 * super class initializes the set of closed states, implemented
 * as an unordered map.
 */
BreadthFirstSearchAlgorithm::BreadthFirstSearchAlgorithm() {
    searchFrontier = new queue<State *>;
}

/**
 * Simple getter for the name of the BFS algorithm. The method finds
 * utility only for result printing purposes.
 *
 * @return the name of the algorithm ("BFS").
 */
string BreadthFirstSearchAlgorithm::getAlgorithmName() const {
    return "BFS";
}

/**
 * Executes all necessary actions in order to insert a state into the search
 * frontier. In the case of BFS, the given state is just pushed at the end of
 * the search frontier queue.
 */
void BreadthFirstSearchAlgorithm::pushToSearchFrontier(State *stateToPush) {
    searchFrontier->push(stateToPush);
}

/**
 * Simple method that checks whether the search frontier queue is empty.
 * Implementing this check in a separate method offers easy handling of
 * inheritance and enhanced code readability.
 *
 * @return true if the search frontier queue is empty, else false.
 */
bool BreadthFirstSearchAlgorithm::searchFrontierIsEmpty() {
    return searchFrontier->empty();
}

/**
 * Getter for the size attribute of the search frontier queue. Implementing
 * such a getter offers easy handling of inheritance among the search algorithms
 * and enhances code readability.
 *
 * @return the size of the search frontier queue.
 */
unsigned int BreadthFirstSearchAlgorithm::getSizeOfSearchFrontier() const {
    return searchFrontier->size();
}

/**
 * Extracts the front element from the search frontier queue. The
 * top element is popped out of the queue before returned, so
 * that the queue's top is now pointing to the next element.
 *
 * @return the top element of the queue, which is popped.
 */
State *BreadthFirstSearchAlgorithm::extractTopFromSearchFrontier() {
    State *topElement = searchFrontier->front();
    searchFrontier->pop();
    return topElement;
}

/**
 * Performs all necessary actions on an unvisited state. The given state must
 * be checked to not belong to the closed set of already visited and expanded
 * states. In case of the BFS algorithm, the given state is just pushed at the
 * end of the search frontier queue.
 *
 * @param state the state to push at the end of the search frontier queue.
 */
void BreadthFirstSearchAlgorithm::performActionsOnUnvisited(State *&state) {
    searchFrontier->push(state);
}

/**
 * Executes all necessary actions when a BFS object needs to be erased from
 * memory. In the case of BFS, the search frontier queue is deleted.
 * The indirectly called destructor of the super class takes care of deleting
 * the closed set unordered map.
 */
BreadthFirstSearchAlgorithm::~BreadthFirstSearchAlgorithm() {
    delete searchFrontier;
}
