#include "CellShadow.hh"

float CellShadow::computeShadow(shared_ptr<Scene> scene, HitInfo& info, shared_ptr<Light> light, vec3 point){
    float result = 0.01f;

    return 1.0f;
}

vec3 CellShadow::shading(shared_ptr<Scene> scene, HitInfo &info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight){
    return (info.normal + 1.0f) / 2.0f;
}
