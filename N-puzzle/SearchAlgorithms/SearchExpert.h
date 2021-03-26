#ifndef SEARCH_EXPERT_H
#define SEARCH_EXPERT_H

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


    static void destructSearchAlgorithms(vector<SearchAlgorithm *> *&searchAlgorithms);
};

#endif //SEARCH_EXPERT_H
