#ifndef AI_STARTER_PACK_IN_CPP_STATE_H
#define AI_STARTER_PACK_IN_CPP_STATE_H

#define WIDTH  3
#define HEIGHT  3

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class State {
public:
    State();

    State &operator=(const State& other);

    bool operator==(const State &other) const;

    string toString() const;

    bool moveBlankTileUp(State &nextState);

    bool moveBlankTileDown(State &nextState);

    bool moveBlankTileLeft(State &nextState);

    bool moveBlankTileRight(State &nextState);

    vector<State *> expand();

    unsigned short int getDepth();

    void setHeuristicValue(unsigned short int);

    unsigned short int getHeuristicValue() const;

    unsigned short int heuristic(State *);

    void setActionName(string actionName) { this->actionName = actionName; }

    string getActionName() const { return actionName; }

    void setPrevious(State *previous) { this->previous = previous; }

    State *getPrevious() const { return previous; }

    friend ostream &operator<<(ostream &, const State &);

    string getUniqueRepresentation() const;

    void setFinal();

protected:

private:
    unsigned short int blankTileRow = 0;
    unsigned short int blankTileColumn = 2;
    string actionName;
    State *previous;
    unsigned short int heuristicValue;
    unsigned short int table[HEIGHT][WIDTH] = {{3, 6, 0},
                                               {1, 4, 2},
                                               {7, 5, 8}};

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
