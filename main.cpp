#include "Game.h"

Game* g_game = 0;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false; //초기화 할 때 true가 되어 게임 루프를 실행시켜준다.
SDL_Event event;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
void update();
void render();

int main(int argc, char* args[])
{
  g_game = new Game();
  g_game->init("Game Class", 100, 100, 640, 480, 0);

  while (g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
  }

  g_game->clean();
  
  /*
  if (init("HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN))//이름, 사이즈
  {
    g_bRunning = true;
  }
  else
  {
    return 1;
  }

  while (g_bRunning)
  {
    update();
    render();
  }

  //SDL_Delay(5000);
  SDL_Quit();*/

  return 0;
}
/*
bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if (g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }
  else
  {
    return false;
  }
  
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);//파란색
  return true;
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
  // g_bRunning = false; //무한루프 탈출 
}

void update()
{
  if (SDL_PollEvent(&event))
  { 
    switch (event.type)
    { 
      // 링크 참고해서 완성 해보렴 
      // https://thenumbat.github.io/cpp-course/sdl2/03/03.html 
      // 지금은 아무 키 누르면 종료 
    case SDL_KEYDOWN:  // SDLK_ESCAPE 
      g_bRunning = false;
      printf("false");
      break;
    } 
  } //esc키 누르면 무한루프 탈출(작성중)
}*/