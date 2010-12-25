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
    TableColumn* createTableColumn(const std::string& name, DataType* t);
    TableColumn* createTableColumn(const std::string& name, DataType* t, const std::string& defaultText);
    TableColumn* createTableColumn(const std::string& name, DataType* t, const double& defaultValue);
    TableColumn* createTableColumn(const std::string& name, DataType* t, const long long& defaultValue);
    TableColumn* createTableColumn(const std::string& name, DataType* t, DatabaseConstant* c);
    TableColumn* createTableColumn(const std::string& name, DataType* t, Sequence* s);
    TableColumn* addChild(TableColumn* c);
    TableConstraint* addChild(TableConstraint* c);
    UniqueConstraint* addChild(UniqueConstraint* c);
    PreventValueConstraint* addChild(PreventValueConstraint* c);
    ForeignKeyConstraint* addChild(ForeignKeyConstraint* c);
    ForeignKeyConstraint* createForeignKeyConstraint(const std::string& name, TableColumn* localC, TableColumn* otherC);
    TableColumn* column(const std::string& name) const;
    UniqueConstraint* createUniqueConstraint(const std::string& name);
    UniqueConstraint* uniqueConstraint(const std::string& name) const;
    PreventValueConstraint* preventValueConstraint(const std::string& name) const;
    TableConstraintMap tableConstraints() const { return _tableConstraints; }
    TableColumnMap columns() const;
    UniqueConstraintMap uniqueConstraints() const { return _uniqueConstraints; }
    PreventValueConstraint* createPreventValueConstraint(const std::string& name, const std::string& value);
    PreventValueConstraintMap preventValueConstraints() const { return _preventValueConstraints; }
    ForeignKeyConstraintMap foreignKeyConstraints() const { return _foreignKeyConstraints; }
    bool hasPrimaryKeyConstraint() const { return (0 != _primaryKeyConstraint); }
    PrimaryKeyConstraint* setPrimaryKeyConstraint(PrimaryKeyConstraint* pk) { _primaryKeyConstraint = pk; }
    PrimaryKeyConstraint* createPrimaryKeyConstraint(const std::string& name);
    PrimaryKeyConstraint* primaryKeyConstraint() const { return _primaryKeyConstraint; }
    ForeignKeyConstraint* foreignKeyConstraint(const std::string& name) const;
    virtual std::vector<std::string> visit(ComponentVisitor* v);
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

