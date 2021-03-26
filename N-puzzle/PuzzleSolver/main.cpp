#include <iostream>
#include "N-puzzle/SearchAlgorithms/SearchExpert.h"

int main() {
    State *initial = new State();
    State *goal = new State(true);

    SearchExpert::executeAvailableAlgorithms(initial, goal);

    delete initial;
    delete goal;

    return 0;
}