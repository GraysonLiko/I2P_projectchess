#include <cstdlib>

#include "../state/state.hpp"
#include "./myAI.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move myAI::get_move(State *state, int depth){
  if (state->legal_actions.empty())
    state->get_legal_actions();

  auto actions = state->legal_actions;
  int bestValue = state->player==0?-1000000:1000000;
  Move bestMove = actions[0];

  int alpha = -1000000;
  int beta = 1000000;

  for (auto action : actions) {
    State* nextState = state->next_state(action);
    int value = minimax(nextState, depth-1, alpha, beta, state->player);

    if (state->player==0&&value > bestValue) {
      bestValue = value;
      bestMove = action;
    }
    else if(state->player==1&&value<bestValue){
        bestValue = value;
         bestMove = action;
    }

    delete nextState;
  }

  return bestMove;
}