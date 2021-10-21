#include "Game.h"

//엔터 : 동적 이미지 활성화

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

  //m_go.load(100, 100, 64, 64, "animate");
  //m_player.load(300, 300, 64, 64, "animate");
  GameObject* m_go = new GameObject();
  GameObject* m_player = new Player();

  m_go->load(100, 100, 64, 64, "animate");
  m_player->load(300, 300, 64, 64, "animate");
  m_gameObjects.push_back(m_go);
  m_gameObjects.push_back(m_player);
  
  m_bRunning = true;

  return true;
}

void Game::update()
{
  if (ani == true)
  {
    m_currentFrame = ((SDL_GetTicks() / 100) % 4);
  }

  //m_go.update();
  //m_player.update();

  /*for (int i = 0; m_gameObjects.size()//이이이게 문제였; i++)
  {
    m_gameObjects[i]->update();
  }*/ //여기가 문제인 것으로 파악됨 / i를 안넣어서!!!!! 여기 문제 있다고 오류 표시해주라 리플릿아 엉엉엉
  
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  //m_go.draw(m_pRenderer);
  //m_player.draw(m_pRenderer);

  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw(m_pRenderer);
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
      case SDLK_RETURN: //엔터 애니메이션 활성화 및 비활성화
        if (ani == false)
        {
          ani = true;
        }
        else if (ani == true)
        {
          ani = false;
        }
      break;
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