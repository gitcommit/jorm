/* 
 * File:   PreventValueConstraint.cpp
 * Author: jolo
 * 
 * Created on 22. Dezember 2010, 12:29
 */

#include "PreventValueConstraint.h"

#include "Table.h"

PreventValueConstraint::PreventValueConstraint(Table* t, const std::string& name, const std::string& value)
: CheckConstraint(t, name), _value(value) {
    t->addChild(this);
}

PreventValueConstraint::PreventValueConstraint(const PreventValueConstraint& orig)
: CheckConstraint(orig), _value(orig._value) {
}

PreventValueConstraint::~PreventValueConstraint() {
}

void PreventValueConstraint::setValue(const std::string& v) {
    _value = v;
}

std::string PreventValueConstraint::value() const {
    return _value;
}