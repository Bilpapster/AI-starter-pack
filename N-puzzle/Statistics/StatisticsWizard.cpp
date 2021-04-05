#include <algorithm>
#include <ctime>
#include <random>

#include "StatisticsWizard.h"
#include <N-puzzle/DefaultDefinitions/Macros.h>

void StatisticsWizard::initializeRandomPuzzle(State *&initial) {


    unsigned short array[NUMBER_OF_TILES_IN_PUZZLE];

    for (unsigned short tile = 0; tile < NUMBER_OF_TILES_IN_PUZZLE; tile++) {
        array[tile] = tile;
    }
    auto seed = time(nullptr);
    shuffle(array, array + NUMBER_OF_TILES_IN_PUZZLE, default_random_engine(seed));
    initial->setFromArray(array);
}
