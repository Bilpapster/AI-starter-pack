#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

#include "SearchExpert.h"

State *SearchExpert::depthFirstSearch2(State *initial, State *goal,
                                       long long int &numberOfExaminedStates,
                                       long long int &volumeOfAllocatedMemory) {
    stack<State *> searchFrontier;
    unordered_map<string, State *> closedStates;

    searchFrontier.push(initial);
    numberOfExaminedStates = 0;
    volumeOfAllocatedMemory = 1;
    while (!searchFrontier.empty()) {
        if (searchFrontier.size() + closedStates.size() > volumeOfAllocatedMemory)
            volumeOfAllocatedMemory = searchFrontier.size() + closedStates.size();
        State *currentlyExaminingState = searchFrontier.top();
        searchFrontier.pop();
        if (closedStates.count(currentlyExaminingState->getUniqueRepresentation()) == 0) {
            numberOfExaminedStates++;
            if (*currentlyExaminingState == *goal)
                return currentlyExaminingState;
            pair<string, State *> k(currentlyExaminingState->getUniqueRepresentation(), currentlyExaminingState);
            closedStates.insert(k);
            vector<State *> children = currentlyExaminingState->expand();
            for (unsigned int i = 0; i < children.size(); i++)
                if (closedStates.count(children[i]->getUniqueRepresentation()) == 0)
                    searchFrontier.push(children[i]);
        }
    }
    return nullptr;
}

State *SearchExpert::breadthFirstSearch(State *initial, State *goal,
                                        long long int &numberOfExaminedStates,
                                        long long int &volumeOfAllocatedMemory) {
    queue<State *> searchFrontier;
    unordered_map<string, State *> closedStates;

    searchFrontier.push(initial);
    numberOfExaminedStates = 0;
    volumeOfAllocatedMemory = 1;
    while (!searchFrontier.empty()) {
        if (searchFrontier.size() + closedStates.size() > volumeOfAllocatedMemory)
            volumeOfAllocatedMemory = searchFrontier.size() + closedStates.size();
        State *currentlyExaminingState = searchFrontier.front();
        searchFrontier.pop();
        if (closedStates.count(currentlyExaminingState->getUniqueRepresentation()) == 0) {
            numberOfExaminedStates++;
            if ((*currentlyExaminingState) == (*goal))
                return currentlyExaminingState;
            pair<string , State *> k(currentlyExaminingState->getUniqueRepresentation(), currentlyExaminingState);
            closedStates.insert(k);
            vector<State *> children = currentlyExaminingState->expand();
            for (unsigned int i = 0; i < children.size(); i++)
                if (closedStates.count(children[i]->getUniqueRepresentation()) == 0)
                    searchFrontier.push(children[i]);
        }
    }
    return nullptr;
}

State *SearchExpert::bestFirstSearch(State *initial, State *goal,
                                     long long int &numberOfExaminedStates,
                                     long long int &volumeOfAllocatedMemory) {
    priority_queue<State *, vector<State *>, StateComparator> searchFrontier;
    unordered_map<string, State *> closedStates;

    searchFrontier.push(initial);
    numberOfExaminedStates = 0;
    volumeOfAllocatedMemory = 1;
    while (!searchFrontier.empty()) {
        if (searchFrontier.size() + closedStates.size() > volumeOfAllocatedMemory)
            volumeOfAllocatedMemory = searchFrontier.size() + closedStates.size();
        State *currentlyExaminingState = searchFrontier.top();
        searchFrontier.pop();

        if (closedStates.count(currentlyExaminingState->getUniqueRepresentation()) == 0) {
            numberOfExaminedStates++;
            if (*currentlyExaminingState == *goal)
                return currentlyExaminingState;
            pair<string, State *> k(currentlyExaminingState->getUniqueRepresentation(), currentlyExaminingState);
            closedStates.insert(k);
            vector<State *> children = currentlyExaminingState->expand();
            for (unsigned int i = 0; i < children.size(); i++) {
                if (closedStates.count(children[i]->getUniqueRepresentation()) == 0) {
                    children.at(i)->setHeuristicValue(children.at(i)->heuristic(goal));
                    searchFrontier.push(children.at(i));
                }
            }
        }
    }
    return nullptr;
}
