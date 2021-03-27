#ifndef DEPTH_FIRST_SEARCH_ALGORITHM_H
#define DEPTH_FIRST_SEARCH_ALGORITHM_H

#include <stack>
#include "SearchAlgorithm.h"

class DepthFirstSearchAlgorithm : public SearchAlgorithm {
public:

    /* constructor & destructor */

    DepthFirstSearchAlgorithm();

    ~DepthFirstSearchAlgorithm() override;


    /* utility getter  */

    string getAlgorithmName() const override;

protected:

    /* in DFS the searchFrontier is implemented
     *       as a stack of state pointers       */
    stack<State *> *searchFrontier;


    /* utility functions that are derived as abstract
     * from the abstract super class and implemented
     *  especially based on the DFS way of searching */

    void pushToSearchFrontier(State *stateToPush) override;

    bool searchFrontierIsEmpty() override;

    unsigned int getSizeOfSearchFrontier() const override;

    State *extractTopFromSearchFrontier() override;

    void performActionsOnUnvisited(State *&state) override;
};


#endif //DEPTH_FIRST_SEARCH_ALGORITHM_H
