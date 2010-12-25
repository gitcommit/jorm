/* 
 * File:   Table.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:24
 */

#include <iostream>
#include <bits/stl_pair.h>

#include "Table.h"
#include "Schema.h"
#include "ComponentVisitor.h"

Table::Table(Schema* s, const std::string& name)
: InSchemaComponent(s, name), _primaryKeyConstraint(0) {
    s->addChild(this);
}

Table::Table(const Table& orig)
: InSchemaComponent(orig), _columns(orig._columns), _primaryKeyConstraint(orig._primaryKeyConstraint),
_uniqueConstraints(orig._uniqueConstraints), _preventValueConstraints(orig._preventValueConstraints),
_foreignKeyConstraints(orig._foreignKeyConstraints) {
}

Table::~Table() {
}

TableColumn* Table::addChild(TableColumn* c) {
    _columns.insert(std::make_pair(c->name(), c));
    schema()->addChild(c);
    return column(c->name());
}

UniqueConstraint* Table::addChild(UniqueConstraint* c) {
    _uniqueConstraints.insert(std::make_pair(c->name(), c));
    return uniqueConstraint(c->name());
}

TableColumnMap Table::columns() const {
    return _columns;
}

TableColumn* Table::column(const std::string& name) const {
    TableColumnMapConstIterator i = _columns.find(name);
    std::cout << "searching for " << name << " in " << qualifiedName() << std::endl;
    BOOST_ASSERT(_columns.end() != i);
    return i->second;
}

UniqueConstraint* Table::uniqueConstraint(const std::string& name) const {
    UniqueConstraintMapConstIterator i = _uniqueConstraints.find(name);
    BOOST_ASSERT(_uniqueConstraints.end() != i);
    return i->second;
}

TableConstraint* Table::addChild(TableConstraint* c) {
    _tableConstraints.insert(std::make_pair(c->name(), c));
    return c;
}

PreventValueConstraint* Table::addChild(PreventValueConstraint* c) {
    _preventValueConstraints.insert(std::make_pair(c->name(), c));
    return preventValueConstraint(c->name());
}

PreventValueConstraint* Table::preventValueConstraint(const std::string& name) const {
    PreventValueConstraintMapConstIterator i = _preventValueConstraints.find(name);
    BOOST_ASSERT(_preventValueConstraints.end() != i);
    return i->second;
}

ForeignKeyConstraint* Table::addChild(ForeignKeyConstraint* v) {
    _foreignKeyConstraints.insert(std::make_pair(v->name(), v));
    return foreignKeyConstraint(v->name());
}

ForeignKeyConstraint* Table::foreignKeyConstraint(const std::string& name) const {
    ForeignKeyConstraintMapConstIterator i = _foreignKeyConstraints.find(name);
    BOOST_ASSERT(_foreignKeyConstraints.end() != i);
    return i->second;
}

std::vector<std::string> Table::visit(ComponentVisitor* v) {
    return v->perform(this);
}

TableColumn* Table::createTableColumn(const std::string& name, DataType* t) {
    return addChild(new TableColumn(this, name, t));
}

TableColumn* Table::createTableColumn(const std::string& name, DataType* t, const std::string& defaultText) {
    TableColumn* c = createTableColumn(name, t);
    c->createDefaultValueSource(defaultText);
    return c;
}

PrimaryKeyConstraint* Table::createPrimaryKeyConstraint(const std::string& name) {
    return setPrimaryKeyConstraint(new PrimaryKeyConstraint(this, name));
}

UniqueConstraint* Table::createUniqueConstraint(const std::string& name) {
    return addChild(new UniqueConstraint(this, name));
}

PreventValueConstraint* Table::createPreventValueConstraint(const std::string& name, const std::string& value) {
    return addChild(new PreventValueConstraint(this, name, value));
}

ForeignKeyConstraint* Table::createForeignKeyConstraint(const std::string& name, TableColumn* localC, TableColumn* otherC) {
    return addChild(new ForeignKeyConstraint(this, name, otherC->table(), localC, otherC));
}

TableColumn* Table::createTableColumn(const std::string& name, DataType* t, const double& defaultValue) {
    TableColumn* c = createTableColumn(name, t);
    c->createDefaultValueSource(defaultValue);
    return c;
}

TableColumn* Table::createTableColumn(const std::string& name, DataType* t, const long long& defaultValue) {
    TableColumn* c = createTableColumn(name, t);
    c->createDefaultValueSource(defaultValue);
    return c;
}

TableColumn* Table::createTableColumn(const std::string& name, DataType* t, DatabaseConstant* cnst) {
    TableColumn* c = createTableColumn(name, t);
    c->createDefaultValueSource(cnst);
    return c;
}

TableColumn* Table::createTableColumn(const std::string& name, DataType* t, Sequence* s) {
    TableColumn* c = createTableColumn(name, t);
    c->createDefaultValueSource(s);
    return c;
}
