#pragma once
#include <memory>
#include <stack>
#include "state.hpp"

using namespace std;

typedef unique_ptr<state> stateRef; //un smartPointer de state

class stateMachine
{
private:
    stack<stateRef> _states; //pile de pointeur pour empiler les fenetres du jeu
    stateRef _newState;      //la fenetre active

    bool _isRemoving; //flag pour savoir ce qui se passe ds la fenetre
    bool _isAdding;
    bool _isReplacing;

public:
    void addState(stateRef newState, bool isReplacing = true);
    void removeState();

    void processStateChanges();
    stateRef& getActiveState(); //pas de const pcq aussi setteur
};