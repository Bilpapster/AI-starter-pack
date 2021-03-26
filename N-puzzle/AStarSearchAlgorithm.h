#ifndef AI_STARTER_PACK_IN_CPP_A_STAR_SEARCH_ALGORITHM_H
#define AI_STARTER_PACK_IN_CPP_A_STAR_SEARCH_ALGORITHM_H


#include "BestFirstSearchAlgorithm.h"

class AStarSearchAlgorithm : public BestFirstSearchAlgorithm {
public:
    string getAlgorithmName() const override;


protected:
    unsigned short defineHeuristicValueOf(State *&state) override;
};


#endif //AI_STARTER_PACK_IN_CPP_A_STAR_SEARCH_ALGORITHM_H
