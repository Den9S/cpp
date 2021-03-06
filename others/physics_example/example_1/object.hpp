#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include "gpcircle.hpp"
#include "physics/physicmodel.hpp"
#include "physics/force.hpp"
#include "physics/vector.hpp"

using namespace cpp_prosto::graphical;

struct  object
{
  object();
  void setPosition(geo2D::point);
  void update();
  void draw();

  void setWind(geo2D::force);
  void setGravity(geo2D::force);

  void removeWind();
  void removeGravity();

  void setVelocity(geo2D::vector);
  void setFriction(float);

  void bottom_border_collision();

  const geo2D::point &position()const;

private:
  void _move_draw_objects();

private:
  float    mX{0.f};
  float    mY{0.f};
  int      mRadius{20};
  gpCircle mCircle;

  geo2D::force  mWind;
  geo2D::force  mGravity;
  geo2D::vector mVelocity;

  geo2D::physicModel mModel;
};

#endif // OBJECT_HPP
