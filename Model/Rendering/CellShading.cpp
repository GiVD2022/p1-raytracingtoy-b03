#include "CellShading.hh"


vec3 CellShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
    //Falta per acabar -> Zijian

    return info.mat_ptr->Kd;
}
