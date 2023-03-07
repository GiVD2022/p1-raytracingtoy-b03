#include "Triangle.hh"

Triangle::Triangle() {
    p1 = vec3(0.0, 0.0, 0.0);
    p2 = vec3(1.0, 0.0, 0.0);
    p3 = vec3(0.5, 1.0, 0.0);
}

Triangle::Triangle(vec3 v1, vec3 v2, vec3 v3, float data) :Object(data) {
    p1 = v1;
    p2 = v2;
    p3 = v3;
}

Triangle::Triangle(float data) :Object(data) {
    p1 = vec3(0, 0, 0);
    p2 = vec3(1, 0, 0);
    p3 = vec3(0.5, 1, 0);
}

bool Triangle::hit(Ray &raig, float tmin, float tmax, HitInfo& info) const {

}


void Triangle::aplicaTG(shared_ptr<TG> t) {


}

void Triangle::read (const QJsonObject &json)
{

}


//! [1]
void Triangle::write(QJsonObject &json) const
{

}
//! [1]

void Triangle::print(int indentation) const{

}
