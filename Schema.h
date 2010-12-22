/* 
 * File:   Schema.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 15:47
 */

#ifndef SCHEMA_H
#define	SCHEMA_H

#include "InDatabaseComponent.h"

#include "Sequence.h"
#include "Table.h"

class DatabaseModel;

class Schema : public InDatabaseComponent {
public:
    Schema(DatabaseModel* m, const std::string& name);
    Schema(const Schema& orig);
    virtual ~Schema();
    void addChild(Sequence* s);
    void addChild(Table* t);
    void addChild(TableColumn* c);
    SequenceMap sequences() const;
    TableMap tables() const;
    TableColumnMap tableColumns() const;
    Table* table(const std::string& name);
private:
    SequenceMap _sequences;
    TableMap _tables;
    TableColumnMap _columns;
};
typedef std::map<std::string, Schema*> SchemaMap;
typedef SchemaMap::const_iterator SchemaMapConstIterator;

#endif	/* SCHEMA_H */

