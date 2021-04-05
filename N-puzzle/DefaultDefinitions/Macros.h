#ifndef MACROS_H
#define MACROS_H

    #define CONSOLE_PRINTING_ENABLED true
    #define FILE_PRINTING_ENABLED false
    #define DEFAULT_REPORT_FILE_NAME "Reports.txt"


    /* in case you wish to change default puzzle
     * you must update all default values! */
    #define NUMBER_OF_TILES_IN_PUZZLE 9
    #define HEIGHT 3
    #define WIDTH 3
    #define DEFAULT_PUZZLE {{3, 6, 0}, \
                            {1, 4, 2}, \
                            {7, 5, 8}}
    #define DEFAULT_BLANK_TILE_ROW 0
    #define DEFAULT_BLANK_TILE_COLUMN 2

#endif //MACROS_H
