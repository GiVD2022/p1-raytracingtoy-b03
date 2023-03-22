#pragma once

#include "ShadingStrategy.hh"

class PhongShading: public ShadingStrategy
{
public:
    PhongShading() {};
    vec3 shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom) override;
    ~PhongShading(){};
};

