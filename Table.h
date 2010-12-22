/* 
 * File:   Table.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 17:24
 */

#ifndef TABLE_H
#define	TABLE_H

#include "InSchemaComponent.h"

#include "TableColumn.h"
#include "UniqueConstraint.h"
#include "PreventValueConstraint.h"
#include "ForeignKeyConstraint.h"

class PrimaryKeyConstraint;

class Table: public InSchemaComponent {
public:
    Table(Schema* s, const std::string& name);
    Table(const Table& orig);
    virtual ~Table();
    void addChild(TableColumn* c);
    void addChild(TableConstraint* c);
    void addChild(UniqueConstraint* c);
    void addChild(PreventValueConstraint* c);
    void addChild(ForeignKeyConstraint* c);
    TableColumn* column(const std::string& name) const;
    UniqueConstraint* uniqueConstraint(const std::string& name) const;
    PreventValueConstraint* preventValueConstraint(const std::string& name) const;
    TableConstraintMap tableConstraints() const { return _tableConstraints; }
    TableColumnMap columns() const;
    UniqueConstraintMap uniqueConstraints() const { return _uniqueConstraints; }
    PreventValueConstraintMap preventValueConstraints() const { return _preventValueConstraints; }
    ForeignKeyConstraintMap foreignKeyConstraints() const { return _foreignKeyConstraints; }
    bool hasPrimaryKeyConstraint() const { return (0 != _primaryKeyConstraint); }
    void setPrimaryKeyConstraint(PrimaryKeyConstraint* pk) { _primaryKeyConstraint = pk; }
    PrimaryKeyConstraint* primaryKeyConstraint() const { return _primaryKeyConstraint; }
    ForeignKeyConstraint* foreignKeyConstraint(const std::string& name) const;
    virtual std::string qualifiedName() const;
private:
    TableColumnMap _columns;
    PrimaryKeyConstraint* _primaryKeyConstraint;
    UniqueConstraintMap _uniqueConstraints;
    TableConstraintMap _tableConstraints;
    PreventValueConstraintMap _preventValueConstraints;
    ForeignKeyConstraintMap _foreignKeyConstraints;
};
typedef std::map<std::string, Table*> TableMap;
typedef TableMap::const_iterator TableMapConstIterator;

#endif	/* TABLE_H */

