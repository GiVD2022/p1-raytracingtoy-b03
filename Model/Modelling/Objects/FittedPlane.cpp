#include "FittedPlane.hh"

#include <iostream>

FittedPlane::FittedPlane(vec3 normal, vec3 pass_point, vec2 pmin, vec2 pmax, float v) : Object(v){
    this->normal = normalize(normal);
    this->point = pass_point;
    this->pmin = pmin;
    this->pmax = pmax;
}

FittedPlane::FittedPlane(vec3 normal, float d, float v) : Object(v) {
    normal  = normalize(normal);
    this->normal = normal;
    if (abs(normal.z)>DBL_EPSILON)
        this->point = vec3(0.0, 0.0, -d/normal.z);
    else if (abs(normal.y)>DBL_EPSILON)
        this->point = vec3(0.0, -d/normal.y, 0.0);
    else
        this->point = vec3(-d/normal.x, 0.0, 0.0);
};

bool FittedPlane::hit(Ray &raig, float tmin, float tmax, HitInfo &info) const{
    // Comprovem interseccio entre el pla i el raig

    // Comprovem si el normal al pla i el raig son ortogonals.
    // En aquest cas son paralels i no hi ha interseccio

    if(abs(dot(raig.getDirection(), normal))<DBL_EPSILON){
        return false;
    }

    float d = -normal[0]*point[0] - normal[1]*point[1] - normal[2]*point[2];

    // 2) Imposem que la recta p+tv compleixi l'eq del pla
    // A(p1 + tv1) + ... + D = 0
    // Aillem la t
    vec3 rp = raig.getOrigin();
    vec3 vp = raig.getDirection();
    float temp =  -normal[0]*rp[0] - normal[1]*rp[1] - normal[2]*rp[2] - d;

    temp/= normal[0]*vp[0] + normal[1]*vp[1] + normal[2]*vp[2];

    if (temp > tmax || temp < tmin) {
            return false;
    }

    if((info.p.z <= pmax.y && info.p.z >= pmin.y) && (info.p.x <= pmax.x && info.p.x >= pmin.x)){
                float u = (info.p.x-pmin.x)/(pmax.x-pmin.x);
                float v = (info.p.z-pmin.y)/(pmax.y-pmin.y);
                info.uv = vec2(u,v);
                return true;
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
    Object::read(json);

    if (json.contains("point") && json["point"].isArray()) {
        QJsonArray auxVec = json["point"].toArray();
        point[0] = auxVec[0].toDouble();
        point[1] = auxVec[1].toDouble();
        point[2] = auxVec[2].toDouble();
    }
    if (json.contains("normal") && json["normal"].isArray()) {
        QJsonArray auxVec = json["normal"].toArray();
        normal[0] = auxVec[0].toDouble();
        normal[1] = auxVec[1].toDouble();
        normal[2] = auxVec[2].toDouble();
    }
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
    Object::write(json);

    QJsonArray auxArray;
    auxArray.append(normal[0]);auxArray.append(normal[1]);auxArray.append(normal[2]);
    json["normal"] = auxArray;

    QJsonArray auxArray2;
    auxArray2.append(point[0]);auxArray2.append(point[1]);auxArray2.append(point[2]);
    json["normal"] = auxArray2;

    QJsonArray auxArray3;
    auxArray.append(pmin[0]);auxArray.append(pmin[1]);
    json["pmin"] = auxArray;

    QJsonArray auxArray4;
    auxArray2.append(pmax[0]);auxArray2.append(pmax[1]);
    json["pmax"] = auxArray2;
}
//! [1]

void FittedPlane::print(int indentation) const
{
    Object::print(indentation);
    const QString indent(indentation * 2, ' ');

    QTextStream(stdout) << indent << "point:\t" << point[0] << ", "<< point[1] << ", "<< point[2] << "\n";
    QTextStream(stdout) << indent << "normal:\t" << normal[0] << ", "<< normal[1] << ", "<< normal[2] << "\n";
    QTextStream(stdout) << indent << "pmin:\t" << pmin[0] << ", "<< pmin[1] << "\n";
    QTextStream(stdout) << indent << "pmax:\t" << pmax[0] << ", "<< pmax[1] << "\n";
}
