/* 
 * File:   DatabaseConstantDefaultValueSource.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 16:26
 */

#include "DatabaseConstantDefaultValueSource.h"

#include "ComponentVisitor.h"

DatabaseConstantDefaultValueSource::DatabaseConstantDefaultValueSource(TableColumn* col, DatabaseConstant* c)
: DefaultValueSource(col, col->name() + "_default_" + c->name()), _databaseConstant(c) {
    _databaseConstant = c;
}

DatabaseConstantDefaultValueSource::DatabaseConstantDefaultValueSource(const DatabaseConstantDefaultValueSource& orig)
: DefaultValueSource(orig), _databaseConstant(orig._databaseConstant) {
}

DatabaseConstantDefaultValueSource::~DatabaseConstantDefaultValueSource() {
}

std::vector<std::string> DatabaseConstantDefaultValueSource::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string DatabaseConstantDefaultValueSource::toString() const {
    return databaseConstant()->name();
}