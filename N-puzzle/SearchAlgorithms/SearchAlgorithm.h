#ifndef SEARCH_ALGORITHM_H
#define SEARCH_ALGORITHM_H

#include <unordered_map>
#include <N-puzzle/StateModel/State.h>

class SearchAlgorithm {

public:
    SearchAlgorithm();

    virtual ~SearchAlgorithm();

    virtual string getAlgorithmName() const = 0;

    State *search(State *initial, State *goal,
                  long long &numberOfExaminedStates,
                  long long &volumeOfAllocatedMemory);

protected:

    unordered_map<string, State *>* closedStates;

    virtual void pushToSearchFrontier(State *stateToPush) = 0;

    virtual bool searchFrontierIsEmpty() = 0;

    virtual unsigned int getSizeOfSearchFrontier() const = 0;

    virtual State *extractTopFromSearchFrontier() = 0;

    virtual void performActionsOnUnvisited(State *&state) = 0;
};


#endif //SEARCH_ALGORITHM_H
