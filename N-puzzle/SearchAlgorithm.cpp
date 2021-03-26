#include <unordered_map>
#include "SearchAlgorithm.h"

SearchAlgorithm::SearchAlgorithm() {
    this->closedStates = new unordered_map<string, State *>;
}

State *
SearchAlgorithm::search(State *initial, State *goal,
                        long long int &numberOfExaminedStates,
                        long long int &volumeOfAllocatedMemory) {

    pushToSearchFrontier(initial);  //
    numberOfExaminedStates = 0;
    volumeOfAllocatedMemory = 1;
    while (!searchFrontierIsEmpty()) {  //
        if (getSizeOfSearchFrontier() + closedStates->size() > volumeOfAllocatedMemory)  //
            volumeOfAllocatedMemory = getSizeOfSearchFrontier() + closedStates->size();
        State *currentlyExaminingState = extractTopFromSearchFrontier();  //
        if (closedStates->count(currentlyExaminingState->getUniqueRepresentation()) == 0) {
            numberOfExaminedStates++;
            if (*currentlyExaminingState == *goal)
                return currentlyExaminingState;
            pair<string, State *> k(currentlyExaminingState->getUniqueRepresentation(), currentlyExaminingState);
            closedStates->insert(k);
            vector<State *> children = currentlyExaminingState->expand();
            for (auto &child : children)
                if (closedStates->count(child->getUniqueRepresentation()) == 0)
                    performActionsOnUnvisited(child);  //
        }
    }
    return nullptr;
}

SearchAlgorithm::~SearchAlgorithm() {
    delete closedStates;
}












