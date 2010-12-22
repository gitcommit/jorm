/* 
 * File:   UniqueConstraint.cpp
 * Author: jolo
 * 
 * Created on 21. Dezember 2010, 17:28
 */

#include "UniqueConstraint.h"

#include "Table.h"

UniqueConstraint::UniqueConstraint(Table* t, const std::string& name)
: TableConstraint(t, name) {
    t->addChild(this);
}

UniqueConstraint::UniqueConstraint(const UniqueConstraint& orig)
: TableConstraint(orig) {
}

UniqueConstraint::~UniqueConstraint() {
}

