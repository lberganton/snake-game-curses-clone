#pragma once

#include <curses.h>
#include <inttypes.h>
#include "config.h"

#define Y_MAP 19
#define X_MAP 78

#define Y_PLAYER (Y_MAP - 1)
#define X_PLAYER (X_MAP / 2)

typedef enum GameElement {
  ELEMENT_VOID,
  ELEMENT_FOOD,
  ELEMENT_SNAKE_HEAD,
  ELEMENT_SNAKE_BODY
} GameElement;

typedef struct GameMap {
  WINDOW *window;
  GameElement matrix[Y_MAP][X_MAP];
} GameMap;

typedef struct GameFood {
  uint16_t x, y;
} GameFood;

typedef struct GameScreen {
  WINDOW *border;
  WINDOW *info;
} GameScreen;

typedef struct GamePlayer GamePlayer;

void startGame(void);
void initializeGameScreen(GameMap *map, GameScreen *screen);
void deleteGameScreen(GameMap *map, GameScreen *screen);
void initializeMap(GameMap *map);
void createFood(GameFood *food, GameMap *map);
void paintElement(GameMap *map, GameElement element, int y, int x);
void paintMap(GameMap *map);
void updateGameScreen(GamePlayer *player, GameMap *map, GameScreen *screen);
