#include "PhongShading.hh"


vec3 PhongShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom) {
    //Falta per acabar -> Zijian

    return info.mat_ptr->Kd;
}