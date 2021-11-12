#ifndef __Game__
#define __Game__

#include <iostream>
#include <vector>
#include "SDL.h"
#include "TextureManager.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "InputHandler.h"

class Game
{
public:
  static Game* Instance()
  {
    if (s_pInstance == 0)
    {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }
  SDL_Renderer* getRenderer() const { return m_pRenderer; }

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();
  void quit() { m_bRunning = false; }

private:
  Game() {}
  ~Game() {}
  static Game* s_pInstance;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif /*defined(__Game__)*/