/* 
 * File:   PrimaryKeyConstraint.cpp
 * Author: jolo
 * 
 * Created on 21. Dezember 2010, 09:58
 */

#include "PrimaryKeyConstraint.h"

#include "Table.h"
#include "ComponentVisitor.h"

PrimaryKeyConstraint::PrimaryKeyConstraint(Table* t, const std::string& name)
: TableConstraint(t, name){
    t->setPrimaryKeyConstraint(this);
}

PrimaryKeyConstraint::PrimaryKeyConstraint(const PrimaryKeyConstraint& orig)
: TableConstraint(orig){
}

PrimaryKeyConstraint::~PrimaryKeyConstraint() {
}

std::vector<std::string> PrimaryKeyConstraint::visit(ComponentVisitor* v) {
    return v->perform(this);
}