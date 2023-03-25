#include "BlinnPhongShading.hh"


vec3 BlinnPhongShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom,vector<shared_ptr<Light>> lights, vec3 globalLight) {
    vec3 ambiental= vec3(0.0f);
    vec3 difosa= vec3(0.0f);
    vec3 specular = vec3(0.0f);

    vec3 global = info.mat_ptr->Ka * globalLight;

    for(const shared_ptr<Light> &light: lights){
        //Calcul ambiental
        ambiental = info.mat_ptr->Ka * light->getIa();
        //Asignem el vector L
        vec3 L = light->vectorL(info.p);
        //Vector Normal
        vec3 N = info.normal;
        //Angul entre L i N
        float cos0 = dot(normalize(N),normalize(L));
        float atte = light->attenuation(info.p);
        if(cos0 > 0.0f){
            //Calcul difosa
            difosa = atte * info.mat_ptr->Kd * light->getId() * cos0;
            vec3 V = normalize(lookFrom - info.p);
            vec3 H = normalize(L+V);
            float cosb = dot(N, H);
            float shi = info.mat_ptr->shininess;
            float cos_b_exp = pow(cosb, shi);
            if(cos_b_exp > 0.0f){
                specular = atte * info.mat_ptr->Ks * light->getIs() * cos_b_exp;
            }
        }
    }
    //return ambiental;
    //return difosa;
    return specular;
    //return ambiental+difosa+specular;
    //return ambiental + (difosa+specular)*attenuation;
    //return globalLight + (difosa+specular)*attenuation + ambiental; globalLight*info.mat_ptr->Ka + (difosa+specular)*attenuation + ambiental; (No se cual de las 2 es)

}
