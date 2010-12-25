/* 
 * File:   DatabaseConstant.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 16:22
 */

#ifndef DATABASECONSTANT_H
#define	DATABASECONSTANT_H

#include "InDatabaseComponent.h"

class DataType;
class ComponentVisitor;

class DatabaseConstant: public InDatabaseComponent {
public:
    DatabaseConstant(DatabaseModel* m, const std::string& name, DataType* t);
    DatabaseConstant(const DatabaseConstant& orig);
    virtual ~DatabaseConstant();
    virtual void setDataType(DataType* t) { _dataType = t; }
    virtual DataType* dataType() const { return _dataType; }
    virtual bool hasDataType() const { return (0 != _dataType); }
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
private:
    DataType* _dataType;
};

typedef std::map<std::string, DatabaseConstant*> DatabaseConstantMap;
typedef DatabaseConstantMap::const_iterator DatabaseConstantMapConstIterator;

#endif	/* DATABASECONSTANT_H */

