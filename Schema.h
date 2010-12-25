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
    Sequence* createSequence(const std::string& name);
    Table* createTable(const std::string& name);
    Sequence* addChild(Sequence* s);
    Table* addChild(Table* t);
    TableColumn* addChild(TableColumn* c);
    SequenceMap sequences() const;
    TableMap tables() const;
    TableColumnMap tableColumns() const;
    Table* table(const std::string& name);
    Sequence* sequence(const std::string& name);
    virtual std::vector<std::string> visit(ComponentVisitor* v);
private:
    SequenceMap _sequences;
    TableMap _tables;
    TableColumnMap _columns;
};
typedef std::map<std::string, Schema*> SchemaMap;
typedef SchemaMap::const_iterator SchemaMapConstIterator;

#endif	/* SCHEMA_H */

