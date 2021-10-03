#include "Game.h"

//엔터 : 동적 이미지 활성화

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    
    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 100, 100, 255); //붉은색 배경 눈이 아파 조정

        //m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer); //새로 추가된 애니메이션 불러오기

        if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
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
  if (ani == true)
  {
    m_currentFrame = ((SDL_GetTicks() / 50) % 6);
  }

  /*if (isJump == true) //점프
  {
    if (jump < 10)
    {
      jump++;
      jumpSpeed++;
      m_destinationRectangle.y -= jumpSpeed;
      SDL_Delay(100);
    }
    else if (jump >= 10 && jump < 20)
    {
      jump++;
      m_destinationRectangle.y += jumpSpeed;
      jumpSpeed--;
      SDL_Delay(100);
    }
    else
    {
      isJump = false;
      jump = 0;
    }
  }*/
  
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
  //m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

  TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
  TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

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
      /*case SDLK_LEFT: //왼쪽으로 이동
        m_destinationRectangle.x -= 5;
        break;
      case SDLK_RIGHT: //오른쪽으로 이동
        m_destinationRectangle.x += 5;
        break;
      case SDLK_UP: //위쪽으로 이동
        m_destinationRectangle.y -= 5;
        break;
      case SDLK_DOWN: //아래쪽으로 이동
        m_destinationRectangle.y += 5;
        break;
      case SDLK_SPACE: //점프
        if (isJump == false)
        {
          isJump = true;
        }   
        break;*/
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