/* 
 * File:   UniqueConstraint.cpp
 * Author: jolo
 * 
 * Created on 21. Dezember 2010, 17:28
 */

#include "UniqueConstraint.h"

#include "Table.h"
#include "ComponentVisitor.h"

UniqueConstraint::UniqueConstraint(Table* t, const std::string& name)
: TableConstraint(t, name) {
    t->addChild(this);
}

UniqueConstraint::UniqueConstraint(const UniqueConstraint& orig)
: TableConstraint(orig) {
}

UniqueConstraint::~UniqueConstraint() {
}

std::vector<std::string> UniqueConstraint::visit(ComponentVisitor* v) {
    return v->perform(this);
}