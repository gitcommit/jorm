/* 
 * File:   DatabaseModel.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 15:41
 */

#include <boost/typeof/typeof.hpp>
#include <boost/typeof/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

#include "DatabaseModel.h"

#include "Schema.h"

#include <iostream>

DatabaseModel::DatabaseModel(const std::string& name)
: Component(name) {
}

DatabaseModel::DatabaseModel(const DatabaseModel& orig)
: Component(orig) {
}

DatabaseModel::~DatabaseModel() {
}

SchemaMap DatabaseModel::schemata() const {
    return _schemata;
}

DataTypeMap DatabaseModel::dataTypes() const {
    return _dataTypes;
}

void DatabaseModel::addChild(Schema* s) {
    _schemata.insert(std::make_pair(s->name(), s));
}

void DatabaseModel::addChild(DataType* t) {
    _dataTypes.insert(std::make_pair(t->name(), t));
}

Schema* DatabaseModel::schema(const std::string& name) {
    SchemaMapConstIterator i = _schemata.find(name);
    if (i == _schemata.end()) {
        return 0;
    }
    return i->second;
}

DataType* DatabaseModel::dataType(const std::string& name) {
    DataTypeMapConstIterator i = _dataTypes.find(name);
    if (i == _dataTypes.end()) {
        return 0;
    }
    return i->second;
}

void DatabaseModel::addChild(Table* t) {
    _tables.insert(std::make_pair(t->qualifiedName(), t));
}

void DatabaseModel::addChild(TableColumn* c) {
    _tableColumns.insert(std::make_pair(c->namePath(), c));
}

TableMap DatabaseModel::tables() const {
    return _tables;
}

TableColumnMap DatabaseModel::tableColumns() const {
    return _tableColumns;
}