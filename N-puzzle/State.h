#ifndef AI_STARTER_PACK_IN_CPP_STATE_H
#define AI_STARTER_PACK_IN_CPP_STATE_H

#define WIDTH  3
#define HEIGHT  3

#include <string>
#include <vector>

using namespace std;

class State {
public:

    /* constructors */

    State();

    explicit State(bool isFinal);


    /* accessors */

    unsigned short getDepth() const { return this->depth; }

    unsigned short getHeuristicValue() const { return heuristicValue; }

    void setHeuristicValue(const unsigned short &value) { heuristicValue = value; }

    string getActionName() const { return actionName; }

    State *getPrevious() const { return previous; }

    void setPrevious(State *previousState);

    void setActionName(const string &name) { this->actionName = name; }

    string getUniqueRepresentation() const;


    /* available actions */

    bool moveBlankTileUp(State &nextState);

    bool moveBlankTileDown(State &nextState);

    bool moveBlankTileLeft(State &nextState);

    bool moveBlankTileRight(State &nextState);


    /* heuristic function */

    unsigned short int heuristic(State *);

    vector<State *> expand();

    string toString() const;

    void setFinal();

    /* overloaded operators */

    friend ostream &operator<<(ostream &, const State &);

    State &operator=(const State &other);

    bool operator==(const State &other) const;


private:
    unsigned short blankTileRow = 0;
    unsigned short blankTileColumn = 2;
    unsigned short heuristicValue;
    unsigned short depth = 0;
    string actionName;
    State *previous;
    unsigned short table[HEIGHT][WIDTH] = {{3, 6, 0},
                                           {1, 4, 2},
                                           {7, 5, 8}};


    /* auxiliary functions used inside the action methods */

    unsigned short int swapBlankTileWithUp();

    unsigned short int swapBlankTileWithDown();

    unsigned short int swapBlankTileWithLeft();

    unsigned short int swapBlankTileWithRight();
};

class StateComparator {
public:
    int operator()(State *leftStatePointer, State *rightStatePointer) const {
        return leftStatePointer->getHeuristicValue() > rightStatePointer->getHeuristicValue();
    }
};

#endif //AI_STARTER_PACK_IN_CPP_STATE_H
