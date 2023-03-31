#include "MaterialTextura.hh"

MaterialTextura ::MaterialTextura() : Material(){
    this->Kd = vec3(0.5,0.5,0.5);
    this->Ks = vec3(0.0,0.0,0.0);
    this->Ka = vec3(0.1, 0.1, 0.1);
    this->opacity = 1.0;
    this->shininess = 1.0;
}

MaterialTextura::~MaterialTextura(){

}

bool MaterialTextura::scatter(const Ray &r_in, const HitInfo &rec, vec3 &color, Ray &r_out) const{
    return false;
}

MaterialTextura::MaterialTextura(vec3 ka, vec3 kd, vec3 ks, float sh, float o) : Material(ka, kd, ks, sh, o){
    this->Kd = kd;
    this->Ks = ks;
    this->Ka = ka;

    if(o > 1.0 + DBL_EPSILON){
        o = 1.0;
    }
    this->opacity = o;

    if(sh > 500+ DBL_EPSILON){
        sh = 500;
    }

    this->shininess = sh;
}

vec3 MaterialTextura::getDiffuse(vec2 uv) const{
    return this->imatge->getColorPixel(uv);
}
