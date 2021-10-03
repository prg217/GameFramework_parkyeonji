#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
  Game() {}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();
  bool ani = false;
  
  bool isJump = false;
  int jump = 0;
  int jumpSpeed = 0;
  int time = 0;

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  SDL_Texture* m_pTexture;

  //원본 사각형
  //SDL_Rect m_sourceRectangle;

  //대상 사각형
  //SDL_Rect m_destinationRectangle;

  TextureManager m_textureManager;
  int m_currentFrame;
};

#endif /*defined(__Game__)*/