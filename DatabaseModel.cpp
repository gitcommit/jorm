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
#include "DatabaseConstant.h"

#include "ComponentVisitor.h"

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

Schema* DatabaseModel::addChild(Schema* s) {
    _schemata.insert(std::make_pair(s->name(), s));
    return schema(s->name());
}

Schema* DatabaseModel::createSchema(const std::string& name) {
    return addChild(new Schema(this, name));
}

DataType* DatabaseModel::addChild(DataType* t) {
    _dataTypes.insert(std::make_pair(t->name(), t));
    return dataType(t->name());
}

DataType* DatabaseModel::createDataType(const std::string& name, const std::string& sqlName) {
    return addChild(new DataType(this, name, sqlName));
}

Schema* DatabaseModel::schema(const std::string& name) {
    SchemaMapConstIterator i = _schemata.find(name);
    BOOST_ASSERT(_schemata.end() != i);
    return i->second;
}

DataType* DatabaseModel::dataType(const std::string& name) {
    DataTypeMapConstIterator i = _dataTypes.find(name);
    BOOST_ASSERT(_dataTypes.end() != i);
    return i->second;
}

Table* DatabaseModel::addChild(Table* t) {
    _tables.insert(std::make_pair(t->qualifiedName(), t));
    return t;
}

TableColumn* DatabaseModel::addChild(TableColumn* c) {
    _tableColumns.insert(std::make_pair(c->namePath(), c));
    return c;
}

TableMap DatabaseModel::tables() const {
    return _tables;
}

TableColumnMap DatabaseModel::tableColumns() const {
    return _tableColumns;
}

std::vector<std::string> DatabaseModel::visit(ComponentVisitor* v) {
    return v->perform(this);
}

DatabaseConstant* DatabaseModel::addChild(DatabaseConstant* c) {
    _databaseConstants.insert(std::make_pair(c->name(), c));
    return databaseConstant(c->name());
}

DatabaseConstant* DatabaseModel::createDatabaseConstant(const std::string& name, DataType* t) {
    return addChild(new DatabaseConstant(this, name, t));
}

DatabaseConstantMap DatabaseModel::databaseConstants() const {
    return _databaseConstants;
}

DatabaseConstant* DatabaseModel::databaseConstant(const std::string& name) {
    DatabaseConstantMapConstIterator i = _databaseConstants.find(name);
    BOOST_ASSERT(i != _databaseConstants.end());
    return i->second;
}