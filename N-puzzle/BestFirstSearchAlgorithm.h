#ifndef AI_STARTER_PACK_IN_CPP_BEST_FIRST_ALGORITHM_H
#define AI_STARTER_PACK_IN_CPP_BEST_FIRST_ALGORITHM_H

#include <queue>
#include "SearchAlgorithm.h"

class BestFirstSearchAlgorithm : public SearchAlgorithm {
public:
    BestFirstSearchAlgorithm();

    ~BestFirstSearchAlgorithm();

    string getAlgorithmName() const override;

protected:
    priority_queue<State *, vector<State *>, StateComparator> *searchFrontier;

    void pushToSearchFrontier(State *stateToPush) override;

    bool searchFrontierIsEmpty() override;

    unsigned int getSizeOfSearchFrontier() const override;

    State *extractTopFromSearchFrontier() override;

    void performActionsOnUnvisited(State *&state) override;

    virtual unsigned short defineHeuristicValueOf(State *&state);
};


#endif //AI_STARTER_PACK_IN_CPP_BEST_FIRST_ALGORITHM_H
