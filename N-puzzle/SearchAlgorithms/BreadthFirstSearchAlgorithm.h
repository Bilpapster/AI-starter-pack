#ifndef BREADTH_FIRST_SEARCH_ALGORITHM_H
#define BREADTH_FIRST_SEARCH_ALGORITHM_H

#include <queue>
#include "SearchAlgorithm.h"
#include "N-puzzle/StateModel/State.h"

class BreadthFirstSearchAlgorithm : public SearchAlgorithm {
public:

    /* constructor & destructor */

    BreadthFirstSearchAlgorithm();

    ~BreadthFirstSearchAlgorithm() override;


    /* utility getter  */

    string getAlgorithmName() const override;

protected:

    /* in BFS the searchFrontier is implemented
     *       as a queue of state pointers       */

    queue<State *> *searchFrontier;


    /* utility functions that are derived as abstract
     * from the abstract super class and implemented
     *  especially based on the BFS way of searching */

    void pushToSearchFrontier(State *stateToPush) override;

    bool searchFrontierIsEmpty() override;

    unsigned int getSizeOfSearchFrontier() const override;

    State *extractTopFromSearchFrontier() override;

    void performActionsOnUnvisited(State *&state) override;
};


#endif //BREADTH_FIRST_SEARCH_ALGORITHM_H
