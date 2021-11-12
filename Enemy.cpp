#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  handleInput();
  m_currentFrame = ((SDL_GetTicks() / 100) % 4);
  SDLGameObject::update();
}

void Enemy::clean() {}

void Enemy::handleInput()
{
  //한 번 클릭하면 shoot이 여러번 나온다... 총알 발사에 필요할 것 같은데 한 번으로 줄일 수 없을까?
  //Delay를 줘보자->500을 주니 shoot이 한 번 나옴 대신 캐릭터가 멈칫함(기획상 반동으로 못움직이게 쓸 수 있을 것 같다.) 50은 2번 100을 주니 1번(적당?) 시간이 있으면 멈칫 안하게 할 방법 찾아보기(예를 들어 shoot을 분리하여 그쪽에 딜레이를 주면 따로 처리되어 마우스 이동에는 문제없지 않을까? 그러면 움직이는 것과 shoot의 쿨타임을 다르게 줄 수 있을 것이다. 지금은 함께 멈칫하니까.)
  if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
  {
    printf("shoot \n");
    SDL_Delay(100);
  }
  Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;
}