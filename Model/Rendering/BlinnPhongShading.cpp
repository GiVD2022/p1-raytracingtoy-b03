#include "BlinnPhongShading.hh"


vec3 BlinnPhongShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom,vector<shared_ptr<Light>> lights, vec3 globalLight) {

    //Falta per acabar -> Zijian7
    vec3 ambiental;
    vec3 difosa;
    vec3 specular;
    vec3 N = normalize(info.normal);
    vec3 L;
    vec3 H;
    vec3 V = lookFrom - info.p;
    vec3 cosO;
    float attenuation;
    for(const shared_ptr<Light> &light: lights){
        L = light->vectorL(info.p);
        cosO = N*L;
        H = normalize(L+V);
        attenuation = light->attenuation(info.p);
        ambiental = info.mat_ptr->Ka*light->getIa();
        difosa = info.mat_ptr->Kd*light->getId()*cosO;
        specular = info.mat_ptr->Ks*light->getIs()*H;
    }
    //return ambiental;
    return difosa;
    //return specular;
    //return ambiental+difosa+specular;
    //return ambiental + (difosa+specular)*attenuation;
    //return globalLight + (difosa+specular)*attenuation + ambiental; globalLight*info.mat_ptr->Ka + (difosa+specular)*attenuation + ambiental; (No se cual de las 2 es)

}
