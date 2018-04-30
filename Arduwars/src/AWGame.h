#ifndef GAME_H
#define GAME_H

#include <Arduboy2.h>
#include <Tinyfont.h>

enum class AWGameState{
  Menu = 0,
  SinglePlayer,
  MultiPlayer
};

class AWGame{
  public:
    AWGame();

    // ======================
    // Methods

    /// starts the game and calls all methods in neccesary order
    void run(void);

private:
    // ======================
    // Methods

    // Game methods

    // ======================
    // Data
    Arduboy2 arduboy;
    Tinyfont tinyfont = Tinyfont(arduboy.getBuffer(), Arduboy2::width(), Arduboy2::height());
    AWGameState gameState;
};
#endif
