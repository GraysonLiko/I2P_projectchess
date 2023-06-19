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

int myAI::minimax(State *state, int depth, int alpha, int beta, bool maximizing){
  if(depth==0){
    return state->evaluate();
  }
  
  if(maximizing==true){
    long long int value = -1000000;
    if(!state->legal_actions.size())
    state->get_legal_actions();

    if(state->legal_actions.size()==0){
      return state->evaluate();
    }

    for(auto itr:state->legal_actions){
      State* states= state->next_state(itr);
      value = maxim(value, minimax(states, depth-1, alpha, beta, false));
      alpha = maxim(alpha, value);
      if(alpha>=beta) break;
    }
    return value;
  }

  else if(maximizing==false){
      long long int value = 1000000;
      if(!state->legal_actions.size())
      state->get_legal_actions();

      if(state->legal_actions.size()==0){
      return state->evaluate();
      }

      for(auto itr:state->legal_actions){
        State* states = state->next_state(itr);
        value = minim(value, minimax(states, depth-1, alpha, beta, true));
        beta = minim(beta, value);
        if(beta<=alpha) break;
      }
      return value;
  }
}

int myAI::maxim(int val, int minimax){
  if(val>minimax){
    return val;
  }
  else return minimax;
}

int myAI::minim(int val, int minimax){
  if(val<minimax){
    return val;
  }
  else return minimax;
}