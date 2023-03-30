#include "FittedPlane.hh"

#include <iostream>

FittedPlane::FittedPlane(vec3 normal, vec3 pass_point, vec2 pmin, vec2 pmax, float v) : Plane(normal,pass_point,v){
    this->normal = normalize(normal);
    this->point = pass_point;
    this->pmin = pmin;
    this->pmax = pmax;
}

FittedPlane::FittedPlane(vec3 normal, float d, float v) : Plane(normal, d, v) {
    normal  = normalize(normal);
    this->normal = normal;
    if (abs(normal.z)>DBL_EPSILON)
        this->point = vec3(0.0, 0.0, -d/normal.z);
    else if (abs(normal.y)>DBL_EPSILON)
        this->point = vec3(0.0, -d/normal.y, 0.0);
    else
        this->point = vec3(-d/normal.x, 0.0, 0.0);
};

bool FittedPlane::hit(Ray &raig, float t_min, float t_max, HitInfo &info) const {
    if (Plane::hit(raig, t_min, t_max, info)) {
        if((info.p.z <= pmax.y && info.p.z >= pmin.y) && (info.p.x <= pmax.x && info.p.x >= pmin.x)){
                    float u = (info.p.x-pmin.x)/(pmax.x-pmin.x);
                    float v = (info.p.z-pmin.y)/(pmax.y-pmin.y);
                    info.uv = vec2(u,v);
                    return true;
                }
            }
    return false;
}

void FittedPlane::aplicaTG(shared_ptr<TG> t) {
    if (dynamic_pointer_cast<shared_ptr<TranslateTG>>(t)) {

        // Nomes movem el punt de pas
        vec4 newp(this->point, 1.0);
        newp = t->getTG() * newp;
        this->point.x = newp.x;
        this->point.y = newp.y;
        this->point.z = newp.z;
    }
}

void FittedPlane::read (const QJsonObject &json)
{
    Plane::read(json);
    if(json.contains("pmin") && json["pmin"].isArray()) {
        QJsonArray auxVec = json["pmin"].toArray();
        pmin[0] = auxVec[0].toDouble();
        pmin[1] = auxVec[0].toDouble();
    }
    if(json.contains("pmax") && json["pmax"].isArray()) {
        QJsonArray auxVec = json["pmax"].toArray();
        pmax[0] = auxVec[0].toDouble();
        pmax[1] = auxVec[0].toDouble();
    }
}


//! [1]
void FittedPlane::write(QJsonObject &json) const
{
    Plane::write(json);

    QJsonArray auxArray;
    auxArray.append(pmin[0]);auxArray.append(pmin[1]);
    json["pmin"] = auxArray;

    QJsonArray auxArray2;
    auxArray2.append(pmax[0]);auxArray2.append(pmax[1]);
    json["pmax"] = auxArray2;
}
//! [1]

void FittedPlane::print(int indentation) const
{
    Plane::print(indentation);
    const QString indent(indentation * 2, ' ');

    QTextStream(stdout) << indent << "pmin:\t" << pmin[0] << ", "<< pmin[1] << "\n";
    QTextStream(stdout) << indent << "pmax:\t" << pmax[0] << ", "<< pmax[1] << "\n";
}
