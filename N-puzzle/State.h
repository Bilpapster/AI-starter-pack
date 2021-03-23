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

    State(int x, int y, bool lights);

    void setFree(int x, int y, bool flag);

    int getY() const;

    int getX() const;

    bool isFree(int x, int y);

    void setX(int x);

    void setY(int y);

    State &operator=(State other);

    bool operator==(const State &other) const;

    friend bool operator<(const State &left, const State &right);

    string toString() const;

    bool turnOn(State &nextState);

    bool turnOff(State &nextState);

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

    unsigned long getKey() const {
        unsigned long k = xCoordinate * 1000000 + yCoordinate * 1000;
        if (lights) k += 1;
        return k;
    }

    friend ostream &operator<<(ostream &, const State &);

    string getUniqueRepresentation() const;

    void setFinal();

protected:

private:
    int xCoordinate, yCoordinate;
    bool free[WIDTH][HEIGHT];
    long long int table[HEIGHT][WIDTH] = {{3, 6, 0},
                                          {1, 4, 2},
                                          {7, 5, 8}};

    double heuristicValue;
    string actionName;
    State *previous;
    bool lights;

    int blankTileRow = 0;
    int blankTileColumn = 2;
};

class StateComparator {
public:
    int operator()(State *leftStatePointer, State *rightStatePointer) const {
        return leftStatePointer->getHeuristicValue() > rightStatePointer->getHeuristicValue();
    }
};

#endif //AI_STARTER_PACK_IN_CPP_STATE_H
