#ifndef A_STAR_SEARCH_ALGORITHM_H
#define A_STAR_SEARCH_ALGORITHM_H


#include "BestFirstSearchAlgorithm.h"

class AStarSearchAlgorithm : public BestFirstSearchAlgorithm {
public:

    /* utility getter  */
    string getAlgorithmName() const override;


protected:
    unsigned short defineHeuristicValueOf(State *&state) override;
};


#endif //A_STAR_SEARCH_ALGORITHM_H
