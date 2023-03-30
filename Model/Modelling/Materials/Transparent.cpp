#include "Transparent.hh"

Transparent::Transparent(){

}

Transparent::Transparent(const vec3& color): Material(){
    this->Kd = color; // color difús!
}

Transparent::Transparent(const vec3& a, const vec3& d, const vec3& s, float k) : Material(a, d, s, k)
{
}

Transparent::Transparent(const vec3& a, const vec3& d, const vec3& s, float k,float o) : Material(a, d, s, k, o)
{
    this->refractive_index = o;
}

Transparent::Transparent(const vec3& a, const vec3& d, const vec3& s, const float k, const float opac, const vec3& kt, const float nut):
    Material(a, d, s, k, opac, nut, kt){

}

Transparent::~Transparent() {}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& r_out) const
{
    vec3 N = rec.normal;
    float snell; //Formula Snell
    if(dot(r_in.getDirection(), N) > 0){
        N = -N;
        snell = nut / 1;

    }else{
        N = rec.normal;
        snell = 1 / nut;
    }

    vec3 t = refract(r_in.getDirection(), N, snell);
    if(length(t) < DBL_EPSILON){
        t = reflect(r_in.getDirection(), N);
        color = this->Kd;
    }else{

        color = this->kt;
    }
    r_out = Ray(rec.p + 0.01f * t, t);

    return true;
}

vec3 Transparent::getDiffuse(vec2 point) const
{
    //Retornem coeficient de difusió
    return Kd;
}

