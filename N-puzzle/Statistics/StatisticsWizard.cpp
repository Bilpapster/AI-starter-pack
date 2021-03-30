#include <algorithm>
#include <ctime>
#include <random>

#include "StatisticsWizard.h"
#define NUMBER_OF_TILES_IN_PUZZLE 9

void StatisticsWizard::initializeRandomPuzzle(State *&initial) {
    unsigned short array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto seed = time(nullptr);
    shuffle(array, array + NUMBER_OF_TILES_IN_PUZZLE, default_random_engine(seed));
    initial->setFromArray(array);
}
