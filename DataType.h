/* 
 * File:   DataType.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 16:50
 */

#ifndef DATATYPE_H
#define	DATATYPE_H

#include "InDatabaseComponent.h"

class DatabaseModel;

class DataType: public InDatabaseComponent {
public:
    DataType(DatabaseModel* m, const std::string& name, const std::string& sqlName);
    DataType(const DataType& orig);
    virtual ~DataType();
    void setSqlName(const std::string& n) { _sqlName = n; }
    std::string sqlName() const { return _sqlName; }
private:
    std::string _sqlName;
};

typedef std::map<std::string, DataType*> DataTypeMap;
typedef DataTypeMap::const_iterator DataTypeMapConstIterator;

#endif	/* DATATYPE_H */

