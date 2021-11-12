#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
  if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
  {
    Uint32 frameStart, frameTime;
    while (TheGame::Instance()->running())
    {
      frameStart = SDL_GetTicks();
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      frameTime = SDL_GetTicks() - frameStart;
      if (frameTime < DELAY_TIME)
      {
        SDL_Delay((int)(DELAY_TIME - frameTime));
      }
    }
  }
  else
  {
    std::cout << "game init failure " << SDL_GetError() << "\n";
  }
  TheInputHandler::Instance()->clean();
  TheGame::Instance()->clean();

  return 0;
}

//무한 회피 게임 캐릭터를 가운데에 고정하고 그 캐릭터의 좌표 값을 받아 그리고 좌우 점프 하면 배경이 움직여 그리고 장애물이 그 캐릭터 좌표 값에 닿으면 충돌처리
//배경 1, 2, 3 순으로 해서 속도를 다르게 줘서 입체감 상승
//총알이랑 에너미 리스트해서 충돌검사 같은...