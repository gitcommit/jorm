/* 
 * File:   SequenceDefaultValueSource.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 11:03
 */

#include "SequenceDefaultValueSource.h"

#include "Table.h"
#include "Sequence.h"

#include "ComponentVisitor.h"

SequenceDefaultValueSource::SequenceDefaultValueSource(TableColumn* c, Sequence* s)
: DefaultValueSource(c, c->name() + " sequence " + s->qualifiedName()), _sequence(s) {
    setSequence(s);
}

SequenceDefaultValueSource::SequenceDefaultValueSource(const SequenceDefaultValueSource& orig)
: DefaultValueSource(orig), _sequence(orig._sequence) {
}

SequenceDefaultValueSource::~SequenceDefaultValueSource() {
}

std::vector<std::string> SequenceDefaultValueSource::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string SequenceDefaultValueSource::toString() const {
    return "Sequence: " + sequence()->qualifiedName();
}