#ifndef __Enemy__
#define __Enemy__

#include "SDLGameObject.h"
//몬스터도 추가시켜야 내 맘대로 움직일까 

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};

#endif