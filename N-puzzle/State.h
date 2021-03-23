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

    State &operator=(State other);

    bool operator==(const State &other) const;

    string toString() const;

    bool moveBlankTileUp(State &nextState);

    bool moveBlankTileDown(State &nextState);

    bool moveBlankTileLeft(State &nextState);

    bool moveBlankTileRight(State &nextState);

    vector<State *> expand();

    int getDepth();

    void setHeuristicValue(double);

    double getHeuristicValue() const;

    int heuristic(State *) const;

    void setActionName(string actionName) { this->actionName = actionName; }

    string getActionName() const { return actionName; }

    void setPrevious(State *previous) { this->previous = previous; }

    State *getPrevious() const { return previous; }

    friend ostream &operator<<(ostream &, const State &);

    string getUniqueRepresentation() const;

    void setFinal();

protected:

private:
    long long int table[HEIGHT][WIDTH] = {{3, 6, 0},
                                          {1, 4, 2},
                                          {7, 5, 8}};

    int blankTileRow = 0;
    int blankTileColumn = 2;
    string actionName;
    State *previous;
    double heuristicValue;
};

class StateComparator {
public:
    int operator()(State *leftStatePointer, State *rightStatePointer) const {
        return leftStatePointer->getHeuristicValue() > rightStatePointer->getHeuristicValue();
    }
};

#endif //AI_STARTER_PACK_IN_CPP_STATE_H
