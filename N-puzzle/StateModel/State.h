#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <N-puzzle/DefaultDefinitions/Macros.h>

using namespace std;

class State {
public:

    /* constructors */

    State();

    State(const unsigned short *array);

    explicit State(bool isFinal);


    /* accessors */

    unsigned short getDepth() const { return this->depth; }

    unsigned short getHeuristicValue() const { return heuristicValue; }

    void setHeuristicValue(const unsigned short &value) { heuristicValue = value; }

    string getActionName() const { return actionName; }

    State *getPrevious() const { return previous; }

    void setPrevious(State *previousState);

    void setActionName(const string &name) { this->actionName = name; }

    string getUniqueEncoding() const;


    /* available actions */

    bool moveBlankTileUp(State &nextState);

    bool moveBlankTileDown(State &nextState);

    bool moveBlankTileLeft(State &nextState);

    bool moveBlankTileRight(State &nextState);


    /* heuristic functions */

    unsigned short int manhattanDistance();

    unsigned short int misplacedTiles();


    /* utility functions */

    vector<State *> expand();

    string toString() const;

    void setFinal();

    void setFromArray(const unsigned short *array);


    /* overloaded operators */

    friend ostream &operator<<(ostream &, const State &);

    State &operator=(const State &other);

    bool operator==(const State &other) const;


private:
    unsigned short blankTileRow = DEFAULT_BLANK_TILE_ROW;
    unsigned short blankTileColumn = DEFAULT_BLANK_TILE_COLUMN;
    unsigned short heuristicValue;
    unsigned short depth = 0;
    string actionName;
    State *previous;
    unsigned short board[HEIGHT][WIDTH] = DEFAULT_PUZZLE;


    /* auxiliary functions utilized inside the action methods */

    unsigned short int swapBlankTileWithUp();

    unsigned short int swapBlankTileWithDown();

    unsigned short int swapBlankTileWithLeft();

    unsigned short int swapBlankTileWithRight();
};

/**
 * A simple class representing a comparator between two state objects.
 * The state objects are compared in terms of their manhattanDistance value.
 */
class StateComparator {
public:
    /**
     * Between two state objects, the one with the greater manhattanDistance value is deemed as
     * the greater between the two.
     *
     * @param leftStatePointer  the state placed on the left side of the comparison
     * @param rightStatePointer the state placed on the right side of the comparison
     * @return true (> 0) if left > right, else false (0).
     */
    int operator()(State *leftStatePointer, State *rightStatePointer) const {
        return leftStatePointer->getHeuristicValue() > rightStatePointer->getHeuristicValue();
    }
};

#endif //STATE_H
