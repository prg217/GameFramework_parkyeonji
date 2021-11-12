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
  int error_check = 0; //error_check값을 0으로 한 후 성공할때마다 1씩 더해줌! 그리고 다 통과되지 않으면 그 값이 그렇게 될 수 없으니 만약 몇 이하면 false로 만들어준다. 

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif /*defined(__Game__)*/