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

std::vector<std::string> TableConstraint::columnNames() const {
    std::vector<std::string> buf;
    TableColumnMap m = columns();
    for (TableColumnMapConstIterator i = m.begin(); i != m.end(); ++i) {
        buf.push_back(i->second->name());
    }
    return buf;
}

std::string TableConstraint::joinedColumnNames(const std::string& sep) const {
    std::string ret;
    std::vector<std::string> l = columnNames();
    for (std::vector<std::string>::const_iterator i = l.begin(); i != l.end(); ++i) {
        if (i != l.begin()) {
            ret += sep;
        }
        ret += (*i);
    }
    return ret;
}

std::string TableConstraint::toString() const {
    return name() + ": " + joinedColumnNames();
}