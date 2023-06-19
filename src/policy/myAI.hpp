#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class myAI{
public:
  static Move get_move(State *state, int depth);
  static int minimax(State *state, int depth, bool maximizing);
  static int maxim(int val, int minimax);
  static int minim(int val, int minimax);
};