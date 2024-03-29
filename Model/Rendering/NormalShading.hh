#pragma once

#include "ShadingStrategy.hh"
#include <math.h>
#include <stdlib.h>
#include "glm/glm.hpp"

class NormalShading: public ShadingStrategy
{
public:
    NormalShading() {};
    vec3 shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) override;
    ~NormalShading(){};
};

