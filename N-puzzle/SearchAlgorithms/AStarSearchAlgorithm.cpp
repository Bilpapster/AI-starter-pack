#include "AStarSearchAlgorithm.h"

/**
 * Simple getter for the name of the A* algorithm. The method finds
 * utility only for result printing purposes.
 *
 * @return the name of the algorithm ("A*").
 */
string AStarSearchAlgorithm::getAlgorithmName() const {
    return "A*";
}

/**
 * Given a state object, defines its heuristic value, based on a heuristic
 * function the state object provides itself. In the case of A*, the sum
 * of the manhattan distances added to the depth of the given state is used
 * as a way to order the expanded states inside the search frontier priority queue.
 *
 * @param state the state to define heuristic value for.
 * @return the heuristic value of the given state.
 */
unsigned short AStarSearchAlgorithm::defineHeuristicValueOf(State *&state) {
    return BestFirstSearchAlgorithm::defineHeuristicValueOf(state) + state->getDepth();
}
