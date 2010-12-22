/* 
 * File:   ForeignKeyConstraint.h
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 12:53
 */

#ifndef FOREIGNKEYCONSTRAINT_H
#define	FOREIGNKEYCONSTRAINT_H

#include "TableConstraint.h"

#include "TableColumn.h"

class ForeignKeyConstraint: public TableConstraint {
public:
    ForeignKeyConstraint(Table* t, const std::string& name, Table* otherT);
    ForeignKeyConstraint(const ForeignKeyConstraint& orig);
    virtual ~ForeignKeyConstraint();
    void setReferencedTable(Table* t);
    Table* referencedTable() const;
    void add(TableColumn* local, TableColumn* referenced);
    TableColumnPairMap columnPairs() const { return _columnPairs; }
private:
    Table* _referencedTable;
    TableColumnPairMap _columnPairs;
};

typedef std::map<std::string, ForeignKeyConstraint*> ForeignKeyConstraintMap;
typedef ForeignKeyConstraintMap::const_iterator ForeignKeyConstraintMapConstIterator;

#endif	/* FOREIGNKEYCONSTRAINT_H */

