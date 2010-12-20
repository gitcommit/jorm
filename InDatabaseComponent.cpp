/* 
 * File:   InDatabaseComponent.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:06
 */

#include "InDatabaseComponent.h"

#include "DatabaseModel.h"

InDatabaseComponent::InDatabaseComponent(DatabaseModel* m, const std::string& name)
: Component(m, name) {
}

InDatabaseComponent::InDatabaseComponent(const InDatabaseComponent& orig)
: Component(orig) {
}

InDatabaseComponent::~InDatabaseComponent() {
}

DatabaseModel* InDatabaseComponent::databaseModel() const {
    return dynamic_cast<DatabaseModel*>(parent());
}