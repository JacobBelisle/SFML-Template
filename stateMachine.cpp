#include "stateMachine.h"

void stateMachine::addState(stateRef newState, bool isReplacing)
{
    _isAdding = true;
    _isReplacing = isReplacing;

    _newState = move(newState);
}

void stateMachine::removeState()
{
    _isRemoving = true;
}

void stateMachine::processStateChanges()
{
    if (_isRemoving && !_states.empty())
    {
        _states.pop();
        if (!_states.empty())
            _states.top()->resume();
    }
    _isRemoving = false;

    if (_isAdding)
    {
        if (!_states.empty())
        {
            if (_isReplacing)
                _states.pop();
            else
                _states.top()->pause();
        }

        _states.push(move(_newState));
        _states.top()->init();
        _isAdding = false;
    }
}

stateRef &stateMachine::getActiveState()
{
    return _states.top();
}