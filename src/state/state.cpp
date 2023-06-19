#include <iostream>
#include <sstream>
#include <cstdint>

#include "./state.hpp"
#include "../config.hpp"


/**
 * @brief evaluate the state
 * 
 * @return int 
 */
/*
(I can't pass baseline2 with this algorithm)

 int State::evaluate(){
    int white_material = 0;
    int black_material = 0;
    int white_king_pts = 0;
    int black_king_pts = 0;
    int white_pawn_pts = 0;
    int black_pawn_pts = 0;

    int piece;

    static const int material_table[7] = {0, 2, 6, 7, 8, 20, 100};
    
    for(size_t i=0; i<BOARD_H; i+=1){
      for(size_t j=0; j<BOARD_W; j+=1){
        if((piece=this->board.board[0][i][j])){
          white_material += material_table[piece];
          white_pawn_pts += evaluatePawn(piece, i, j, 0);
        }
        if((piece=this->board.board[1][i][j])){
          black_material += material_table[piece];
          black_pawn_pts += evaluatePawn(piece, i, j, 1);
        }
      }
    }
    
    white_king_pts = evaluateKingSafety(0);
    black_king_pts = evaluateKingSafety(1);

    int white_total = white_material + white_king_pts + white_pawn_pts;
    int black_total = black_material + black_king_pts + black_pawn_pts;
    // [TODO] design your own evaluation function
    return white_total - black_total;
  }

  int State::evaluatePawn(int piece, int row, int col, int player){
    int pawnStructureScore = 0;

    if (player == 0) {  // White player
      if (row > 0 && this->board.board[player][row - 1][col] == 1)
        pawnStructureScore += 10;
      if (row < BOARD_H - 1 && this->board.board[player][row + 1][col] == 1)
        pawnStructureScore += 10;
    } else {  // Black player
      if (row > 0 && this->board.board[player][row - 1][col] == 1)
        pawnStructureScore -= 10;
      if (row < BOARD_H - 1 && this->board.board[player][row + 1][col] == 1)
        pawnStructureScore -= 10;
    }

    if (player == 0) {  // White player
      if ((col > 0 && this->board.board[player][row][col - 1] != 1) ||
          (col < BOARD_W - 1 && this->board.board[player][row][col + 1] != 1))
        pawnStructureScore -= 20;
    } else {  // Black player
      if ((col > 0 && this->board.board[player][row][col - 1] != 1) ||
          (col < BOARD_W - 1 && this->board.board[player][row][col + 1] != 1))
        pawnStructureScore += 20;
    }

    return pawnStructureScore;
  }

  int State::evaluateKingSafety(int player) {
    int kingSafetyScore = 0;

    int kingRow = player == 0 ? BOARD_H - 1 : 0;
    for (int col = 0; col < BOARD_W; col++) {
      if (this->board.board[player][kingRow][col] == 1)
        kingSafetyScore += 5;
    }

    int opponent = player == 0 ? 1 : 0;
    int kingCol = -1;
    for (int row = 0; row < BOARD_H; row++) {
      for (int col = 0; col < BOARD_W; col++) {
        if (this->board.board[opponent][row][col] != 0) {
          if (KingThreat(row, col, kingRow, kingCol)) {
            kingSafetyScore -= 10;
            break;
          }
        }
      }
    }

    for (int row = 0; row < BOARD_H; row++) {
      for (int col = 0; col < BOARD_W; col++) {
        if (this->board.board[opponent][row][col] != 0) {
          int distance = abs(row - kingRow) + abs(col - kingCol);
          if (distance <= 2)
            kingSafetyScore -= 3;
        }
      }
    }

    int ownPlayer = player == 0 ? 0 : 1;
    for (int row = 0; row < BOARD_H; row++) {
      for (int col = 0; col < BOARD_W; col++) {
        if (this->board.board[ownPlayer][row][col] != 0) {
          int distance = abs(row - kingRow) + abs(col - kingCol);
          if (distance <= 3)
            kingSafetyScore += 2;
        }
      }
    }

    return kingSafetyScore;
  }

  bool State::KingThreat(int player, int kingRow, int kingCol, int kingLayer) {
  int opponent = (player == 0) ? 1 : 0;

  for (int row = 0; row < BOARD_H; row++) {
    for (int col = 0; col < BOARD_W; col++) {
      
      if (this->board.board[opponent][row][col]!= 0) {
        if (isPieceAttacking(row, col, kingRow, kingCol)) {
          return true;
        }
      }

    }
  }

  return false;
}

bool State::isPieceAttacking(int pieceRow, int pieceCol, int kingRow, int kingCol) {
  // Check if the piece at (pieceRow, pieceCol) is attacking the king at (kingRow, kingCol)
  
  int dRow = kingRow - pieceRow;
  int dCol = kingCol - pieceCol;

  if (dRow == 0 || dCol == 0)
    return true;

  if (abs(dRow) == abs(dCol))
    return true;

  if ((abs(dRow) == 2 && abs(dCol) == 1) || (abs(dRow) == 1 && abs(dCol) == 2))
    return true;

  int opponent = (pieceRow < kingRow) ? 1 : 0;
  int pawnDirection = (opponent == 0) ? 1 : -1;
  if (abs(dRow) == 1 && abs(dCol) == 1) {
    if (this->board.board[opponent][kingRow][kingCol] == 1 && dRow == pawnDirection)
      return true;
  }

  return false;
}
*/

int State::evaluate(){
   int white_material = 0;
    int black_material = 0;
    int piece;

    static const int material_table[7] = {0, 2, 6, 7, 8, 20, 100};
    
    for(size_t i=0; i<BOARD_H; i+=1){
      for(size_t j=0; j<BOARD_W; j+=1){
        if((piece=this->board.board[0][i][j])){
          white_material += material_table[piece];  
        }
        if((piece=this->board.board[1][i][j])){
          black_material += material_table[piece];
        }
      }
    }
    return white_material - black_material;
}


/**
 * @brief return next state after the move
 * 
 * @param move 
 * @return State* 
 */
State* State::next_state(Move move){
  Board next = this->board;
  Point from = move.first, to = move.second;
  
  int8_t moved = next.board[this->player][from.first][from.second];
  //promotion for pawn
  if(moved == 1 && (to.first==BOARD_H-1 || to.first==0)){
    moved = 5;
  }
  if(next.board[1-this->player][to.first][to.second]){
    next.board[1-this->player][to.first][to.second] = 0;
  }
  
  next.board[this->player][from.first][from.second] = 0;
  next.board[this->player][to.first][to.second] = moved;
  
  State* next_state = new State(next, 1-this->player);
  
  if(this->game_state != WIN)
    next_state->get_legal_actions();
  return next_state;
}


static const int move_table_rook_bishop[8][7][2] = {
  {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}},
  {{0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7}},
  {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}},
  {{-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}},
  {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}},
  {{1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}},
  {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}},
  {{-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}},
};
static const int move_table_knight[8][2] = {
  {1, 2}, {1, -2},
  {-1, 2}, {-1, -2},
  {2, 1}, {2, -1},
  {-2, 1}, {-2, -1},
};
static const int move_table_king[8][2] = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
  {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};


/**
 * @brief get all legal actions of now state
 * 
 */
void State::get_legal_actions(){
  // [Optional]
  // This method is not very efficient
  // You can redesign it
  this->game_state = NONE;
  std::vector<Move> all_actions;
  auto self_board = this->board.board[this->player];
  auto oppn_board = this->board.board[1 - this->player];
  
  int now_piece, oppn_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece=self_board[i][j])){
        // std::cout << this->player << "," << now_piece << ' ';
        switch (now_piece){
          case 1: //pawn
            if(this->player && i<BOARD_H-1){
              //black
              if(!oppn_board[i+1][j] && !self_board[i+1][j])
                all_actions.push_back(Move(Point(i, j), Point(i+1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i+1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i+1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }else if(!this->player && i>0){
              //white
              if(!oppn_board[i-1][j] && !self_board[i-1][j])
                all_actions.push_back(Move(Point(i, j), Point(i-1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i-1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i-1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }
            break;
          
          case 2: //rook
          case 4: //bishop
          case 5: //queen
            int st, end;
            switch (now_piece){
              case 2: st=0; end=4; break; //rook
              case 4: st=4; end=8; break; //bishop
              case 5: st=0; end=8; break; //queen
              default: st=0; end=-1;
            }
            for(int part=st; part<end; part+=1){
              auto move_list = move_table_rook_bishop[part];
              for(int k=0; k<std::max(BOARD_H, BOARD_W); k+=1){
                int p[2] = {move_list[k][0] + i, move_list[k][1] + j};
                
                if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) break;
                now_piece = self_board[p[0]][p[1]];
                if(now_piece) break;
                
                all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));
                
                oppn_piece = oppn_board[p[0]][p[1]];
                if(oppn_piece){
                  if(oppn_piece==6){
                    this->game_state = WIN;
                    this->legal_actions = all_actions;
                    return;
                  }else
                    break;
                };
              }
            }
            break;
          
          case 3: //knight
            for(auto move: move_table_knight){
              int x = move[0] + i;
              int y = move[1] + j;
              
              if(x>=BOARD_H || x<0 || y>=BOARD_W || y<0) continue;
              now_piece = self_board[x][y];
              if(now_piece) continue;
              all_actions.push_back(Move(Point(i, j), Point(x, y)));
              
              oppn_piece = oppn_board[x][y];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
          
          case 6: //king
            for(auto move: move_table_king){
              int p[2] = {move[0] + i, move[1] + j};
              
              if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) continue;
              now_piece = self_board[p[0]][p[1]];
              if(now_piece) continue;
              
              all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));
              
              oppn_piece = oppn_board[p[0]][p[1]];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
        }
      }
    }
  }
  this->legal_actions = all_actions;
}


const char piece_table[2][7][5] = {
  {" ", "♙", "♖", "♘", "♗", "♕", "♔"},
  {" ", "♟", "♜", "♞", "♝", "♛", "♚"}
};
/**
 * @brief encode the output for command line output
 * 
 * @return std::string 
 */
std::string State::encode_output(){
  std::stringstream ss;
  int now_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece = this->board.board[0][i][j])){
        ss << std::string(piece_table[0][now_piece]);
      }else if((now_piece = this->board.board[1][i][j])){
        ss << std::string(piece_table[1][now_piece]);
      }else{
        ss << " ";
      }
      ss << " ";
    }
    ss << "\n";
  }
  return ss.str();
}


/**
 * @brief encode the state to the format for player
 * 
 * @return std::string 
 */
std::string State::encode_state(){
  std::stringstream ss;
  ss << this->player;
  ss << "\n";
  for(int pl=0; pl<2; pl+=1){
    for(int i=0; i<BOARD_H; i+=1){
      for(int j=0; j<BOARD_W; j+=1){
        ss << int(this->board.board[pl][i][j]);
        ss << " ";
      }
      ss << "\n";
    }
    ss << "\n";
  }
  return ss.str();
}