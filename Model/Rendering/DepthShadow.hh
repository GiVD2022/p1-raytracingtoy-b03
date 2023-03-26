#pragma once

#include "ShadingStrategy.hh"

class DepthShadow : public ShadingStrategy
{
public:
    DepthShadow(){};
    //virtual float computeShadow(shared_ptr<Scene> scene, HitInfo& info, shared_ptr<Light> light, vec3 point) override;
    //virtual vec3 shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight)override;
    ~DepthShadow() {};
};

