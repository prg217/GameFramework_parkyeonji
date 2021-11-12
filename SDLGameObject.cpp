#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0, 0), m_acceleration(0,0)
  {
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentRow = 0;
    m_currentFrame = 0;
  }

  void SDLGameObject::update()
  {
    /*m_position.setX(m_position.getX() + 1);
    m_position.setY(m_position.getY() + 1);*/
    m_velocity += m_acceleration;
    m_position += m_velocity; //숨겨진 버그 해결하기 : 에너미에 업데이트 문 추가해보기, 슝하고 날아가버리네
  }

  void SDLGameObject::draw()
  {
    TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
  }