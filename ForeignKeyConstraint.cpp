/* 
 * File:   ForeignKeyConstraint.cpp
 * Author: jolo
 * 
 * Created on 22. Dezember 2010, 12:53
 */

#include "ForeignKeyConstraint.h"

#include "Table.h"

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
    _columnPairs.insert(std::make_pair(l, r));
}