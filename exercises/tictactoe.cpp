
#include <iostream>


class Board{

private:

  enum grid_vals {
    EMPTY,
    PLAYER_A,
    PLAYER_B
  };

  grid_vals grid[9];

public:
  Board(){
    for(int i = 0; i < 9; i++)
      grid[i] = EMPTY;
  }




};


int main(){ 

  //std::cout << "HELLO WORLD" << std::endl;

  return 0;
}