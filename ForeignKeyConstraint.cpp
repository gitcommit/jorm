/* 
 * File:   ForeignKeyConstraint.cpp
 * Author: jolo
 * 
 * Created on 22. Dezember 2010, 12:53
 */

#include "ForeignKeyConstraint.h"

#include "Table.h"
#include "ComponentVisitor.h"

ForeignKeyConstraint::ForeignKeyConstraint(Table* t, const std::string& name, Table* refT)
: TableConstraint(t, name), _referencedTable(0) {
    t->addChild(this);
    setReferencedTable(refT);
}

ForeignKeyConstraint::ForeignKeyConstraint(const ForeignKeyConstraint& orig)
: TableConstraint(orig), _referencedTable(orig._referencedTable), _columnPairs(orig._columnPairs) {
    setReferencedTable(orig._referencedTable);
}

ForeignKeyConstraint::~ForeignKeyConstraint() {
}

void ForeignKeyConstraint::setReferencedTable(Table* t) {
    _referencedTable = t;
}

Table* ForeignKeyConstraint::referencedTable() const {
    return _referencedTable;
}

void ForeignKeyConstraint::add(TableColumn* l, TableColumn* r) {
    addColumn(l);
    _columnPairs.insert(std::make_pair(l, r));
}

std::vector<std::string> ForeignKeyConstraint::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string ForeignKeyConstraint::toString() const {
    return std::string(name() + "(" + joinedColumnNames() + ") --> "
            + referencedTable()->qualifiedName() + "(" + joinedReferencedTableColumnNames() + ")");
}

std::vector<TableColumn*> ForeignKeyConstraint::referencedTableColumns() const {
    std::vector<TableColumn*> ret;
    TableColumnPairMap l = columnPairs();
    for (TableColumnPairMapConstIterator i = l.begin(); i != l.end(); ++i) {
        ret.push_back(i->second);
    }
    return ret;
}

std::vector<std::string> ForeignKeyConstraint::referencedTableColumnNames() const {
    std::vector<std::string> ret;
    std::vector<TableColumn*> l = referencedTableColumns();
    for (std::vector<TableColumn*>::const_iterator i = l.begin(); i != l.end(); ++i) {
        ret.push_back((*i)->name());
    }
    return ret;
}

std::string ForeignKeyConstraint::joinedReferencedTableColumnNames(const std::string& sep) const {
    std::string ret;
    std::vector<std::string> l = referencedTableColumnNames();
    for (std::vector<std::string>::const_iterator i = l.begin(); i != l.end(); ++i) {
        if (i != l.begin()) {
            ret += sep;
        }
        ret += (*i);
    }
    return ret;
}