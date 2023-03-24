#include "PhongShading.hh"


vec3 PhongShading::shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) {
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
        float cos0 = dot(normalize(L),normalize(N));

        //Calcul difosa
        difosa = info.mat_ptr->Kd * light->getId() * cos0;

        vec3 V = normalize(lookFrom - info.p);
        vec3 R = normalize(reflect(L, N));
        float cosb = dot(R, V);
        float shi = info.mat_ptr->shininess;
        float cos_b_exp = pow(cosb, shi);

        specular = info.mat_ptr->Ks * light->getIs() * cos_b_exp;

    }
    return ambiental+difosa+specular;
}
