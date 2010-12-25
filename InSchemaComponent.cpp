/* 
 * File:   InSchemaComponent.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:09
 */

#include "InSchemaComponent.h"

#include "Schema.h"

InSchemaComponent::InSchemaComponent(Schema* s, const std::string& name)
: Component(s, name) {
}

InSchemaComponent::InSchemaComponent(const InSchemaComponent& orig)
: Component(orig) {
}

InSchemaComponent::~InSchemaComponent() {
}

Schema* InSchemaComponent::schema() const {
    return dynamic_cast<Schema*>(parent());
}

std::string InSchemaComponent::qualifiedName() const {
    return schema()->name() + "." + name();
}

