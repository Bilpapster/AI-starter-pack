#ifndef BEST_FIRST_ALGORITHM_H
#define BEST_FIRST_ALGORITHM_H

#include <queue>
#include "SearchAlgorithm.h"

class BestFirstSearchAlgorithm : public SearchAlgorithm {
public:

    /* constructor & destructor */

    BestFirstSearchAlgorithm();

    ~BestFirstSearchAlgorithm() override;


    /* utility getter  */

    string getAlgorithmName() const override;

protected:

    /* in BestFS the searchFrontier is implemented
     * as a priority queue (max) of state pointers  */

    priority_queue<State *, vector<State *>, StateComparator> *searchFrontier;


    /* utility functions that are derived as abstract
     * from the abstract super class and implemented
     * especially based on the BestFS way of searching */

    void pushToSearchFrontier(State *stateToPush) override;

    bool searchFrontierIsEmpty() override;

    unsigned int getSizeOfSearchFrontier() const override;

    State *extractTopFromSearchFrontier() override;

    void performActionsOnUnvisited(State *&state) override;

    virtual unsigned short defineHeuristicValueOf(State *&state);
};


#endif //BEST_FIRST_ALGORITHM_H
