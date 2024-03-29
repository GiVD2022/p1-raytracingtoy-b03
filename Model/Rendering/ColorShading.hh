#pragma once

#include "ShadingStrategy.hh"

class ColorShading: public ShadingStrategy
{
public:
    ColorShading() {};
    virtual vec3 shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight)override;
    ~ColorShading(){};
};

