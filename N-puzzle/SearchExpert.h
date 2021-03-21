#ifndef AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
#define AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H

#include "State.h"

using namespace std;

class SearchExpert {
public:
    static State *depthFirstSearch2(State *initial, State *goal, long long &numberOfExaminedStates, long long &volumeOfAllocatedMemory);

    static State *breadthFirstSearch(State *initial, State *goal, long long &numberOfExaminedStates, long long &volumeOfAllocatedMemory);

    static State *breadthFirstSearch2(State *initial, State *goal, long long &numberOfExaminedStates, long long &volumeOfAllocatedMemory);

    static State *bestFirstSearch(State *initial, State *goal, long long &numberOfExaminedStates, long long &volumeOfAllocatedMemory);
};


#endif //AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
