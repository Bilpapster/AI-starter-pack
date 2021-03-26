#ifndef AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
#define AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H

#include "State.h"
#include "SearchAlgorithm.h"

using namespace std;

class SearchExpert {
public:

    static void executeAvailableAlgorithms(State *initial, State *goal);

private:
    static void initializeSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms);


};

#endif //AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
