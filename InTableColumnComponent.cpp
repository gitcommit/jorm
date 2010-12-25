/* 
 * File:   InTableColumnComponent.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 11:23
 */

#include "InTableColumnComponent.h"

#include "TableColumn.h"

InTableColumnComponent::InTableColumnComponent(TableColumn* p, const std::string& name)
: Component(p, name) {
}

InTableColumnComponent::InTableColumnComponent(const InTableColumnComponent& orig)
: Component(orig) {
}

InTableColumnComponent::~InTableColumnComponent() {
}

TableColumn* InTableColumnComponent::tableColumn() {
    return dynamic_cast<TableColumn*>(parent());
}