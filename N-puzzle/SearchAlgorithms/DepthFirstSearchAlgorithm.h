#ifndef DEPTH_FIRST_SEARCH_ALGORITHM_H
#define DEPTH_FIRST_SEARCH_ALGORITHM_H


#include <stack>
#include "SearchAlgorithm.h"

class DepthFirstSearchAlgorithm : public SearchAlgorithm {
public:
    DepthFirstSearchAlgorithm();

    ~DepthFirstSearchAlgorithm();

    string getAlgorithmName() const override;

protected:
    stack<State *>* searchFrontier;

    void pushToSearchFrontier(State *stateToPush) override;

    bool searchFrontierIsEmpty() override;

    unsigned int getSizeOfSearchFrontier() const override;

    State *extractTopFromSearchFrontier() override;

    void performActionsOnUnvisited(State *&state) override;
};


#endif //DEPTH_FIRST_SEARCH_ALGORITHM_H