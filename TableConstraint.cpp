/* 
 * File:   TableConstraint.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 22:22
 */

#include "TableConstraint.h"

#include "Table.h"

TableConstraint::TableConstraint(Table* t, const std::string& name)
: InTableComponent(t, name){
    t->addChild(this);
}

TableConstraint::TableConstraint(const TableConstraint& orig)
: InTableComponent(orig), _columns(orig._columns) {
}

TableConstraint::~TableConstraint() {
}

void TableConstraint::addColumn(TableColumn* c) {
    _columns.insert(std::make_pair(c->name(), c));
}

void TableConstraint::addColumn(const std::string& name) {
    addColumn(table()->column(name));
}