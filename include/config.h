#pragma once

#include <curses.h>
#include <inttypes.h>

#define FILE_DATA "data"
#define NAME_LEN 15

#define MSG_YOU_LOSE            "VOCÊ PERDEU!"
#define MSG_ALLOCATION_FAILED   "FALHA NA ALOCAÇÃO DE MEMÓRIA!"

#define GAME_MAX_DELAY 100000
#define GAME_MIN_DELAY 50000
#define GAME_SPEED_INCREASE 25

#define GRAPHIC_VOID ' '
#define GRAPHIC_FOOD ACS_DIAMOND
#define GRAPHIC_SNAKE_HEAD ACS_BOARD
#define GRAPHIC_SNAKE_BODY ACS_BOARD

typedef enum Colors {
  WHITE,
  BLACK,
  RED,
  GREEN,
  BLUE
} Colors;

typedef struct Profile {
  char name[NAME_LEN];
  uint32_t mostRecentScore;
  uint32_t bestScore;
  int foodAttribute;
  int snakeHeadAttribute;
  int snakeBodyAttribute;
} Profile;

bool loadData(void);
bool saveData(void);
