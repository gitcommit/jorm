/* 
 * File:   Table.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:24
 */

#include "Table.h"
#include "Schema.h"

Table::Table(Schema* s, const std::string& name)
: InSchemaComponent(s, name) {
    s->addChild(this);
}

Table::Table(const Table& orig)
: InSchemaComponent(orig) {
}

Table::~Table() {
}

void Table::addChild(TableColumn* c) {
    _columns.insert(std::make_pair(c->name(), c));
}

TableColumnMap Table::columns() const {
    return _columns;
}