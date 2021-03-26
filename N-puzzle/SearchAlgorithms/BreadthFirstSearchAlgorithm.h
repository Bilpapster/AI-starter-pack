#ifndef BREADTH_FIRST_SEARCH_ALGORITHM_H
#define BREADTH_FIRST_SEARCH_ALGORITHM_H


#include <queue>
#include "N-puzzle/StateModel/State.h"
#include "SearchAlgorithm.h"

class BreadthFirstSearchAlgorithm : public SearchAlgorithm {
public:
    BreadthFirstSearchAlgorithm();

    ~BreadthFirstSearchAlgorithm();

    string getAlgorithmName() const override;

protected:
    queue<State *> *searchFrontier;

    void pushToSearchFrontier(State *stateToPush) override;

    bool searchFrontierIsEmpty() override;

    unsigned int getSizeOfSearchFrontier() const override;

    State *extractTopFromSearchFrontier() override;

    void performActionsOnUnvisited(State *&state) override;
};


#endif //BREADTH_FIRST_SEARCH_ALGORITHM_H