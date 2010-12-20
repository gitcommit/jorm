/* 
 * File:   InTableComponent.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:30
 */

#include "InTableComponent.h"

#include "Table.h"

InTableComponent::InTableComponent(Table* t, const std::string& name)
: Component(t, name) {
}

InTableComponent::InTableComponent(const InTableComponent& orig)
: Component(orig) {
}

InTableComponent::~InTableComponent() {
}

