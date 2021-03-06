/* 
 * File:   TableConstraint.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 22:22
 */

#ifndef TABLECONSTRAINT_H
#define	TABLECONSTRAINT_H

#include "InTableComponent.h"
#include "TableColumn.h"

#include <vector>

class TableConstraint: public InTableComponent {
public:
    TableConstraint(Table* t, const std::string& name);
    TableConstraint(const TableConstraint& orig);
    virtual ~TableConstraint();
    void addColumn(TableColumn* c);
    void addColumn(const std::string& name);
    TableColumnMap columns() const { return _columns; }
    std::vector<std::string> columnNames() const;
    std::string joinedColumnNames(const std::string& sep = ", ") const;
    virtual std::string toString() const;
private:
    TableColumnMap _columns;
};

typedef std::map<std::string, TableConstraint*> TableConstraintMap;
typedef TableConstraintMap::const_iterator TableConstraintMapConstIterator;

#endif	/* TABLECONSTRAINT_H */

