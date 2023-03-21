#include "ShadingFactory.hh"


shared_ptr<ShadingStrategy> ShadingFactory::createShading(SHADING_TYPES t) {
    shared_ptr<ShadingStrategy> s;
    switch(t) {
    case COLOR:
        s= make_shared<ColorShading>();
        break;
    case NORMAL:
        s = make_shared<NormalShading>();
        break;
    case COLORSHADOW:
        s = make_shared<ColorShadow>();
        break;
    case BLINNPHONG:
        s = make_shared<BlinnPhongShading>();
    default:
        s = nullptr;
    }
    return s;
}

ShadingFactory::SHADING_TYPES ShadingFactory::getShadingType(QString name) {
    if (name=="COLOR") return SHADING_TYPES::COLOR;
    else if (name == "COLORSHADOW") return SHADING_TYPES::COLORSHADOW;
    else if(name == "NORMAL") return SHADING_TYPES::NORMAL;
    else if(name == "BLINNPHONG") return SHADING_TYPES::BLINNPHONG;
}

QString ShadingFactory::getNameType(SHADING_TYPES t) {
    switch (t) {
    case COLOR:
        return (QString("COLOR"));
        break;
    case COLORSHADOW:
        return (QString("COLORSHADOW"));
        break;
    case NORMAL:
        return (QString("NORMAL"));
        break;
    case BLINNPHONG:
        return (QString("BLINNPHONG"));
        break;
    default:
        return(QString(""));
    }
}
ShadingFactory::SHADING_TYPES ShadingFactory::getIndexType(shared_ptr<ShadingStrategy> m) {
    if (dynamic_pointer_cast<ColorShading>(m) != nullptr) {
        return SHADING_TYPES::COLOR;
    } else if (dynamic_pointer_cast<ColorShadow>(m) != nullptr) {
        return SHADING_TYPES::COLORSHADOW;
    } else if (dynamic_pointer_cast<NormalShading>(m) != nullptr){
        return SHADING_TYPES::NORMAL;
    } else if (dynamic_pointer_cast<BlinnPhongShading>(m) != nullptr){
        return SHADING_TYPES::BLINNPHONG;
    } else
        return SHADING_TYPES::COLOR;
}

shared_ptr<ShadingStrategy> ShadingFactory::switchShading(shared_ptr<ShadingStrategy> m, bool shadow) {
    shared_ptr<ShadingStrategy> m_out = nullptr;
    if (shadow) {
        if (dynamic_pointer_cast<ColorShading>(m) != nullptr) {
             m_out = createShading(COLORSHADOW);
        }
    } else {
        if (dynamic_pointer_cast<ColorShadow>(m) != nullptr) {
             m_out = createShading(COLOR);
        }else if(dynamic_pointer_cast<NormalShading>(m) != nullptr) {
            m_out = createShading(NORMAL);
        }else if(dynamic_pointer_cast<BlinnPhongShading>(m) != nullptr){
            m_out = createShading(BLINNPHONG);
        }
    }
    return m_out;
}
