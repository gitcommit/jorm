/* 
 * File:   Table.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:24
 */

#include <bits/stl_pair.h>

#include "Table.h"
#include "Schema.h"

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

void Table::addChild(TableColumn* c) {
    _columns.insert(std::make_pair(c->name(), c));
    schema()->addChild(c);
}

void Table::addChild(UniqueConstraint* c) {
    _uniqueConstraints.insert(std::make_pair(c->name(), c));
}

TableColumnMap Table::columns() const {
    return _columns;
}

TableColumn* Table::column(const std::string& name) const {
    TableColumnMapConstIterator i = _columns.find(name);
    if (i == _columns.end()) {
        return 0;
    }
    return i->second;
}

UniqueConstraint* Table::uniqueConstraint(const std::string& name) const {
    UniqueConstraintMapConstIterator i = _uniqueConstraints.find(name);
    if (i == _uniqueConstraints.end()) {
        return 0;
    }
    return i->second;
}

void Table::addChild(TableConstraint* c) {
    _tableConstraints.insert(std::make_pair(c->name(), c));
}

void Table::addChild(PreventValueConstraint* c) {
    _preventValueConstraints.insert(std::make_pair(c->name(), c));
}

PreventValueConstraint* Table::preventValueConstraint(const std::string& name) const {
    PreventValueConstraintMapConstIterator i = _preventValueConstraints.find(name);
    if (i == _preventValueConstraints.end()) {
        return 0;
    }
    return i->second;
}

void Table::addChild(ForeignKeyConstraint* v) {
    _foreignKeyConstraints.insert(std::make_pair(v->name(), v));
}

ForeignKeyConstraint* Table::foreignKeyConstraint(const std::string& name) const {
    ForeignKeyConstraintMapConstIterator i = _foreignKeyConstraints.find(name);
    if (i == _foreignKeyConstraints.end()) {
        return 0;
    }
    return i->second;
}

std::string Table::qualifiedName() const {
    return schema()->name() + "." + name();
}