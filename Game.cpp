#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    
    SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

        if (pTempSurface != 0)
        {
          m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
          SDL_FreeSurface(pTempSurface);

          SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

          m_destinationRectangle.w = m_sourceRectangle.w;
          m_destinationRectangle.h = m_sourceRectangle.h;

          m_destinationRectangle.x = m_sourceRectangle.x = 0;
          m_destinationRectangle.y = m_sourceRectangle.y = 0;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false; //랜더러 생성 실패
      }
    }
    else
    {
      return false; //윈도우 생성 실패1
    }
  }
  else
  {
    return false;//SDL 초기화 실패
  }
  
  m_bRunning = true;

  return true;
}

void Game::update()
{
  
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      m_bRunning = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_ESCAPE: //esc입력 받았을 때 종료!
        m_bRunning = false;
        break;
      case SDLK_LEFT: //왼쪽으로 이동
        m_destinationRectangle.x -= 1;
        break;
      case SDLK_RIGHT: //오른쪽으로 이동
        m_destinationRectangle.x += 1;
        break;
      case SDLK_UP: //위쪽으로 이동
        m_destinationRectangle.y -= 1;
        break;
      case SDLK_DOWN: //아래쪽으로 이동
        m_destinationRectangle.y += 1;
        break;
      }
      break;
    default:
      break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}