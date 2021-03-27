#include <unordered_map>
#include <iostream>
#include "SearchAlgorithm.h"

/**
 * Constructor for the SearchAlgorithm class. The class is abstract, so no objects
 * are meant to be constructed directly. The common data structure among all the
 * search algorithms is the set of closed (already visited and expanded) states.
 * In our implementation, the set is an unordered map containing string keys and
 * State values.
 */
SearchAlgorithm::SearchAlgorithm() {
    this->closedStates = new unordered_map<string, State *>;
}

/**
 * The basic method of a SearchAlgorithm object. The method is purposely written
 * abstract, utilizing many auxiliary, smaller methods, in order to be easily
 * applicable on all different kind of search algorithms.
 *
 * @param initial                 the initial state to start searching for the solution
 * @param goal                    the desired solution state
 * @param numberOfExaminedStates  the number of states examined (reference)
 * @param volumeOfAllocatedMemory the volume of allocated memory
 *                                in terms of State memory units (reference)
 *
 * @return the solution state if found, else nullptr.
 */
State *SearchAlgorithm::search(State *initial, State *goal,
                               long long int &numberOfExaminedStates,
                               long long int &volumeOfAllocatedMemory) {

    pushToSearchFrontier(initial);
    numberOfExaminedStates = 0;
    volumeOfAllocatedMemory = 1;
    while (!searchFrontierIsEmpty()) {
        if (getSizeOfSearchFrontier() + closedStates->size() > volumeOfAllocatedMemory)
            volumeOfAllocatedMemory = getSizeOfSearchFrontier() + closedStates->size();
        State *currentlyExaminingState = extractTopFromSearchFrontier();
        if (closedStates->count(currentlyExaminingState->getUniqueEncoding()) == 0) {
            numberOfExaminedStates++;
            if (*currentlyExaminingState == *goal)
                return currentlyExaminingState;
            pair<string, State *> k(currentlyExaminingState->getUniqueEncoding(), currentlyExaminingState);
            closedStates->insert(k);
            vector<State *> children = currentlyExaminingState->expand();
            for (auto &child : children)
                if (closedStates->count(child->getUniqueEncoding()) == 0)
                    performActionsOnUnvisited(child);
        }
    }
    return nullptr;
}

/**
 * Destructor for the SearchAlgorithm class. Deletes the dynamically allocated
 * memory for the unordered map used to implement the set of closed states.
 */
SearchAlgorithm::~SearchAlgorithm() {
    delete closedStates;
}












