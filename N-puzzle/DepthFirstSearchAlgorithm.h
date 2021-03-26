#ifndef AI_STARTER_PACK_IN_CPP_DEPTH_FIRST_SEARCH_ALGORITHM_H
#define AI_STARTER_PACK_IN_CPP_DEPTH_FIRST_SEARCH_ALGORITHM_H


#include "SearchAlgorithm.h"
#include <stack>

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


#endif //AI_STARTER_PACK_IN_CPP_DEPTH_FIRST_SEARCH_ALGORITHM_H
