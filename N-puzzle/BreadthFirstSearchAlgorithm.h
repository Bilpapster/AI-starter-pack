#ifndef AI_STARTER_PACK_IN_CPP_BREADTH_FIRST_SEARCH_ALGORITHM_H
#define AI_STARTER_PACK_IN_CPP_BREADTH_FIRST_SEARCH_ALGORITHM_H


#include <queue>
#include "SearchAlgorithm.h"
#include "State.h"

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


#endif //AI_STARTER_PACK_IN_CPP_BREADTH_FIRST_SEARCH_ALGORITHM_H
