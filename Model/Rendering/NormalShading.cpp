#include "NormalShading.hh"


vec3 NormalShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom) {
    return (info.normal + 1.0f) / 2.0f;
}
