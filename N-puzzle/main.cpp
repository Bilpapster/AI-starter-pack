#include <iostream>
#include <ctime>

#include "SearchExpert.h"
#include "PrettyPrinter.h"
#include "DepthFirstSearchAlgorithm.h"
#include "BreadthFirstSearchAlgorithm.h"
#include "BestFirstSearchAlgorithm.h"
#include "AStarSearchAlgorithm.h"

int main() {
    State *initial = new State();
    State *goal = new State(true);

    SearchExpert::executeAvailableAlgorithms(initial, goal);

    delete initial;
    delete goal;

    return 0;
}
