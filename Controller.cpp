#include "Controller.hh"

Controller::Controller()
{
    scene = make_shared<Scene>();
    // Valors per defecte de visualSetup
    visualSetup = make_shared<SetUp>();
}


bool Controller::createScene(SceneFactory::SCENE_TYPES currentType, QString name) {
    shared_ptr<SceneFactory> sf = nullptr;
    switch (currentType)  {
    case SceneFactory::SCENE_TYPES::VIRTUALWORLD:
        sf = make_shared<SceneFactoryVirtual>();
        break;
    case SceneFactory::SCENE_TYPES::REALDATA:
        sf = make_shared<SceneFactoryData>();
        break;
    case SceneFactory::SCENE_TYPES::TEMPORALVW:
        // TO DO:  Afegir les factories de escenes temporals amb les animacions
        return false;
      break;
    default:
        break;
    }
    scene = sf->createScene(name);
    return (scene != nullptr);
}

bool Controller::createScene(vec3 position, float radius) {
    // Create a single Sphere
    //scene = make_shared<Scene>();
    auto sphere = make_shared<Sphere>(position, radius, 1.0);
    sphere->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));
    scene->objects.push_back(sphere);
    return true;

}

bool Controller::createTriangle(vec3 v1, vec3 v2, vec3 v3, float data) {
    // Create a single Triangle
    //scene = make_shared<Scene>();
    auto triangle = make_shared<Triangle>(v1, v2, v3, 1.0);
    triangle->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));
    scene->objects.push_back(triangle);
    return true;

}

bool Controller::createBox(vec3 v1, vec3 v2, vec3 v3, vec3 v4, float data){
    //scene = make_shared<Scene>();
    auto box = make_shared<Box>(v1, v2, v3, v4, 1.0);
    box->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));
    scene->objects.push_back(box);
    return true;
}

bool Controller::createCylinder(vec3 center, float radius, float height, vec3 axis, float data){
    //scene = make_shared<Scene>();
    auto cylinder = make_shared<Cylinder>(center, radius, height, axis, 1.0);
    cylinder->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));
    scene->objects.push_back(cylinder);
    return true;
}



bool Controller::createMesh(){
    //Create Mesh
    //scene = make_shared<Scene>();
    auto mesh = make_shared<Mesh>("://resources/cube.obj");
    mesh->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));
    scene->objects.push_back(mesh);
    return true;
}

//FittedPlane(vec2 max, vec2 min, vec3 point, vec3 normal, float data);
bool Controller::createFittedPlane(vec2 max , vec2 min, vec3 point, vec3 normal, float data){
    auto fittedPlane = make_shared<FittedPlane>(max, min, point, normal, data);
    fittedPlane->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));
    if(scene.get()->objects.empty()){
        scene = make_shared<Scene>(fittedPlane);
    }else{
        scene.get()->ground = fittedPlane;
    }
    return true;
}
bool Controller::createScene() {
    //TODO: Pots posar codi per a fer una escena amb multiples esferes

    return true;
}

bool Controller::createScene(int nFrames) {

    //TO DO Fase 3 opcional: Codi exemple amb animacions però que es pot canviar
    // pel que creguis convenient

    auto sphere = make_shared<Sphere>(vec3(0, 0, -1), 0.5, 1.0);
    sphere->setMaterial(make_shared<Lambertian>(vec3(0.5, 0.2, 0.7)));

    shared_ptr<Animation> anim = make_shared<Animation>();
    anim->transf =  make_shared<TranslateTG>(vec3(0.2));
    sphere->addAnimation(anim);

    return true;
}
bool Controller::createSettings(QString name) {
    // Create Settings and set them to the scene
    visualSetup = make_shared<SetUp>();
    if (visualSetup->load(name) ) {
        visualSetup->print(0);
        return (true);
    }
    return false;
}

void Controller::rendering(QImage *image) {
    RayTracer *tracer = new RayTracer(image);
    tracer->run();
    delete tracer;
}


bool Controller::createShading(ShadingFactory::SHADING_TYPES t) {
    visualSetup->setShadingStrategy(ShadingFactory::getInstance().createShading(t));
    return visualSetup->getShadingStrategy()!=nullptr;

}

void Controller::update(int i) {
    scene->update(i);
}
