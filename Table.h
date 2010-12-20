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

class Table: public InSchemaComponent {
public:
    Table(Schema* s, const std::string& name);
    Table(const Table& orig);
    virtual ~Table();
    void addChild(TableColumn* c);
    TableColumnMap columns() const;
private:
    TableColumnMap _columns;
};
typedef std::map<std::string, Table*> TableMap;
typedef TableMap::const_iterator TableMapConstIterator;

#endif	/* TABLE_H */

