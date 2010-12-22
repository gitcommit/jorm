/* 
 * File:   DatabaseModel.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 15:41
 */

#ifndef DATABASEMODEL_H
#define	DATABASEMODEL_H

#include "Component.h"
#include "Schema.h"
#include "DataType.h"

class DatabaseModel : public Component {
public:
    DatabaseModel(const std::string& name);
    DatabaseModel(const DatabaseModel& orig);
    virtual ~DatabaseModel();
    SchemaMap schemata() const;
    DataTypeMap dataTypes() const;
    void addChild(Schema* s);
    void addChild(DataType *t);
    void addChild(Table* t);
    void addChild(TableColumn* c);
    Schema* schema(const std::string& name);
    TableMap tables() const;
    TableColumnMap tableColumns() const;
    DataType* dataType(const std::string& name);
private:
    SchemaMap _schemata;
    DataTypeMap _dataTypes;
    TableMap _tables;
    TableColumnMap _tableColumns;
};
typedef std::map<std::string, DatabaseModel*> DatabaseModelMap;
typedef DatabaseModelMap::const_iterator DatabaseModelMapConstIterator;

#endif	/* DATABASEMODEL_H */

