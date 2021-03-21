#ifndef AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
#define AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H

#include "State.h"

using namespace std;

class SearchExpert {
public:
    static State *DFS2(State *initial, State *goal, long long &examined, long long &mem);

    static State *BFS2(State *initial, State *goal, long long &examined, long long &mem);

    static State *BFS(State *initial, State *goal, long long &examined, long long &mem);

    static State *BestFS2(State *initial, State *goal, long long &examined, long long &mem);
};


#endif //AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
