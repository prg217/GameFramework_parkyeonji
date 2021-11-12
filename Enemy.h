#ifndef __Enemy__
#define __Enemy__

#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
};

#endif