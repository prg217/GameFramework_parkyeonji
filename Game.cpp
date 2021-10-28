#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    std::cout << "생성"; //출력이 안됨 + 전에는 엔터 누르면 엔터도 입력됐는데? 지금은 안돼
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    //딜레이를 걸어봤을때는 적용됨
    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 100, 100, 255); //붉은색 배경 눈이 아파 조정   
        //SDL_Delay(10000);
      }
      else
      {
        return false; //랜더러 생성 실패
        std::cout << "랜";
      }
    }
    else
    {
      return false; //윈도우 생성 실패1
      std::cout << "윈";
    }
  }
  else
  {
    return false;//SDL 초기화 실패
    std::cout << "sdl";
  }

  if (!TheTextureManager::Instance()->load("Assets/player_p.png", "animate", m_pRenderer))
  {
    return false;
  }

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
      /*case SDLK_RETURN: //엔터 애니메이션 활성화 및 비활성화
        if (ani == false)
        {
          ani = true;
        }
        else if (ani == true)
        {
          ani = false;
        }
      break;*/
      }
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