#ifndef __SDLGameObject__
#define __SDLGameObject__

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean() {}
  virtual ~SDLGameObject() {}

protected:
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
  std::string m_textureID;

  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;
};

#endif