/* 
 * File:   CheckConstraint.cpp
 * Author: jolo
 * 
 * Created on 22. Dezember 2010, 12:28
 */

#include "CheckConstraint.h"

CheckConstraint::CheckConstraint(Table* t, const std::string& name)
: TableConstraint(t, name) {
}

CheckConstraint::CheckConstraint(const CheckConstraint& orig)
: TableConstraint(orig) {
}

CheckConstraint::~CheckConstraint() {
}

