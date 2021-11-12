#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    error_check++;
    
    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
      error_check++;

      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 100, 100, 255); //붉은색 배경 눈이 아파 조정
        error_check++;
      }
    }
  }
  
  if (error_check < 3)
  {
    return false;//실패
  }

  if (!TheTextureManager::Instance()->load("Assets/player_p.png", "animate", m_pRenderer))
  {
    return false;
  }

  //배열로 만들기 그 다음 반복문
  //배열로 만드는거를 첫번째, 두번째 인자를 배열로 줘야할듯!
  //배열은 이차원 배열로?
  /*
  for (int i = 0; i < 배열사이즈.size; i++)
  {
    if (!TheTextureManager::Instance()->load(배열1, 배열2, m_pRenderer))
    {
      return false;
    }
  }
  */

  m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 64, 64, "animate")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 64, 64, "animate")));

  m_bRunning = true;

  return true;
}

void Game::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
  //업데이트 필요없는거는 따로 예외
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  TheInputHandler::Instance()->clean();
  SDL_Quit();
}