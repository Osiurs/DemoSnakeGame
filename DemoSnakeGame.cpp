#include <SDL2/SDL.h>
#include <vector>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int GRID_WIDTH = 32;
const int GRID_HEIGHT = 24;

// SnakeGame class 
class SnakeGame {
public:
  SnakeGame();
  ~SnakeGame();

  void run();

private:
  void processInput();
  void update();
  void render();

  SDL_Window* window;
  SDL_Renderer* renderer;

  Snake snake;
  Fruit fruit;
  GameBoard board;

  bool gameOver;
};

// Snake class
class Snake {
public:
  Snake(int gridWidth, int gridHeight);

  void handleInput(SDL_Event& e);
  void move();
  void grow();

  std::vector<SDL_Point> body;
  SDL_Point direction;
};

// Fruit class
class Fruit {
public:
  Fruit(int gridWidth, int gridHeight);

  void spawn();

  SDL_Point position;
};

// GameBoard class
class GameBoard {
public:
  GameBoard(int gridWidth, int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
  }

  bool checkCollision(SDL_Rect a, SDL_Rect b);

private:
  int gridWidth;
  int gridHeight;
};

// Implementation  

SnakeGame::SnakeGame() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Snake Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  snake = Snake(GRID_WIDTH, GRID_HEIGHT);
  fruit = Fruit(GRID_WIDTH, GRID_HEIGHT);
  board = GameBoard(GRID_WIDTH, GRID_HEIGHT);

  gameOver = false;
}

SnakeGame::~SnakeGame() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SnakeGame::run() {
  while (!gameOver) {
    processInput();
    update();
    render();
  }
}

// Rest of SnakeGame class implementation

// Snake, Fruit and GameBoard implementations 

int main(int argc, char* args[]) {
  SnakeGame game;
  game.run();
  
  return 0;
}
