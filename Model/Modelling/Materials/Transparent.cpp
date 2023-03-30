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

Transparent::~Transparent() {}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, Ray& r_out) const
{
    //Vector normal a la intersecció
    vec3 normalInterseccio = normalize(rec.normal);
    vec3 raigIncident = normalize(r_in.getDirection()); // raig que entra basicament

    //Fem el cosé dels dos vectors
    float cos_theta = dot(normalInterseccio, raigIncident);
    float snell = 1.0003f / refractive_index; // Snell formula (Gracias StackOverflow)
    vec3 interseccio = rec.p; // punt intersecció

    //Ara el que farem es observar o determinar si hi ha  REFRACCIÓ o REFLEXIÓ
    if(cos_theta > 0){ //El raig entra al objecte
        //Seguim mateixa logica code original
    }else{ // Raig surt del objecte, ja que l'angle format es més gran que 0 (rebota)
        normalInterseccio = -normalInterseccio; // Per tant inverti, la normal
        snell = 1.0f / snell; // e invertim el coeficient de refraccio
    }

    //Part fonamental del nostre metode

    //Amb la funcio refract calculem el nostre vector refractat (usem formula snell)
    vec3 v_refrectat = refract(raigIncident, normalInterseccio, snell);
    //Es crea el raig resultat (el que rebota)
    r_out = Ray(interseccio, v_refrectat);
    //Color = objecte Transparent
    color = kt;

    //Comprovem si es valid el resultat calculat
    if(dot(v_refrectat, v_refrectat) < 0){
        //Si es proxim a 0, asumim que no hi ha refraccio pero si REFLEXIO
        vec3 v_reflectit = reflect(raigIncident, normalInterseccio);
        r_out = Ray(interseccio, v_reflectit);
        color = this->Ks;
    }



    return true;
}

vec3 Transparent::getDiffuse(vec2 point) const
{
    //Retornem coeficient de difusió
    return Kd;
}

