#include "NormalShadow.hh"


float NormalShadow::computeShadow(shared_ptr<Scene> scene, HitInfo& info, shared_ptr<Light> light, vec3 point){
    float result = 0.01f;

    return result;
}

vec3 NormalShadow::shading(shared_ptr<Scene> scene, HitInfo &info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight){
    return (info.normal + 1.0f) / 2.0f;
}

