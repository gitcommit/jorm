/* 
 * File:   Sequence.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:11
 */

#include "Sequence.h"

#include "Schema.h"
#include "ComponentVisitor.h"

Sequence::Sequence(Schema* s, const std::string& name)
: InSchemaComponent(s, name) {
    s->addChild(this);
}

Sequence::Sequence(const Sequence& orig)
: InSchemaComponent(orig) {
}

Sequence::~Sequence() {
}

std::vector<std::string> Sequence::visit(ComponentVisitor* v) {
    return v->perform(this);
}