#pragma once

#include <consolelib.hpp>
#include "Chess.hpp"

extern Chess g_Chess;

const int BOARD_LENGTH = 8;
const int BOARD_WIDTH = 8;

const int SQUARE_LENGTH = 12;
const int SQUARE_WIDTH = 6;

const int WHITE_PIECE_COLOUR = Colours::F_DARKGREEN;
const int BLACK_PIECE_COLOUR = Colours::F_RED;
const int LIGHT_BOARD_COLOUR = Colours::B_GRAY;
const int DARK_BOARD_COLOUR = Colours::B_BLACK;