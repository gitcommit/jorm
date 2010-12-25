/* 
 * File:   DatabaseConstant.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 16:22
 */

#include "DatabaseConstant.h"

#include "DatabaseModel.h"
#include "DataType.h"
#include "ComponentVisitor.h"

DatabaseConstant::DatabaseConstant(DatabaseModel* m, const std::string& n, DataType* t)
: InDatabaseComponent(m, n), _dataType(t) {
    setDataType(t);
    m->addChild(this);
}

DatabaseConstant::DatabaseConstant(const DatabaseConstant& orig)
: InDatabaseComponent(orig), _dataType(orig._dataType) {
}

DatabaseConstant::~DatabaseConstant() {
}

std::vector<std::string> DatabaseConstant::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string DatabaseConstant::toString() const {
    return name();
}