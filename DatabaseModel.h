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
#include "DatabaseConstant.h"

class DatabaseModel : public Component {
public:
    DatabaseModel(const std::string& name);
    DatabaseModel(const DatabaseModel& orig);
    virtual ~DatabaseModel();
    SchemaMap schemata() const;
    DataTypeMap dataTypes() const;
    Schema* addChild(Schema* s);
    DataType* addChild(DataType *t);
    Table* addChild(Table* t);
    TableColumn* addChild(TableColumn* c);
    Schema* schema(const std::string& name);
    Schema* createSchema(const std::string& name);
    DataType* createDataType(const std::string& name, const std::string& sqlName);
    TableMap tables() const;
    TableColumnMap tableColumns() const;
    DataType* dataType(const std::string& name);
    DatabaseConstant* addChild(DatabaseConstant* c);
    DatabaseConstantMap databaseConstants() const;
    DatabaseConstant* createDatabaseConstant(const std::string& name, DataType* t);
    DatabaseConstant* databaseConstant(const std::string& name);
    virtual std::vector<std::string> visit(ComponentVisitor* v);
private:
    SchemaMap _schemata;
    DataTypeMap _dataTypes;
    TableMap _tables;
    TableColumnMap _tableColumns;
    DatabaseConstantMap _databaseConstants;
};
typedef std::map<std::string, DatabaseModel*> DatabaseModelMap;
typedef DatabaseModelMap::const_iterator DatabaseModelMapConstIterator;

#endif	/* DATABASEMODEL_H */

