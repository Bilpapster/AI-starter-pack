#ifndef AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
#define AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H

#include "N-puzzle/StateModel/State.h"
#include "SearchAlgorithm.h"

using namespace std;

class SearchExpert {
public:

    static void executeAvailableAlgorithms(State *initial, State *goal);

private:
    static void initializeSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms);

    static void printResults(const SearchAlgorithm *searchAlgorithm,
                             const State *solutionState,
                             const long long &numberOfExaminedStates,
                             const long long &volumeOfAllocatedMemory,
                             const double &millisElapsedOnSearch);


};

#endif //AI_STARTER_PACK_IN_CPP_SEARCH_EXPERT_H
