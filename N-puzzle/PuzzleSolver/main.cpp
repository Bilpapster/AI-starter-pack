#include <iostream>
#include <random>
#include <N-puzzle/Statistics/StatisticsWizard.h>
#include "N-puzzle/SearchAlgorithms/SearchExpert.h"

/**
 * The driving code for the N-puzzle solver. Just initializes the
 * initial snapshot of the puzzle and the goal one, invoking the
 * search functions to run on them and solve the puzzle.
 *
 * @return 0 as normal execution code
 */
int main() {

    State *goal = new State(true);

    for (int i = 0; i < 2; i++) {
        State *initial = new State();
        StatisticsWizard::initializeRandomPuzzle(initial);
        cout << "Random generated puzzle to solve:" << endl
                << initial->toString() << endl;

        SearchExpert::executeAvailableAlgorithms(initial, goal);
        delete initial;
        cout << "----------------------------------------------" << endl;
    }

    delete goal;

    return 0;
}
