/* 
 * File:   DatabaseConstantDefaultValueSource.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 16:26
 */

#ifndef DATABASECONSTANTDEFAULTVALUESOURCE_H
#define	DATABASECONSTANTDEFAULTVALUESOURCE_H

#include "DefaultValueSource.h"

class DatabaseConstant;
class ComponentVisitor;

class DatabaseConstantDefaultValueSource: public DefaultValueSource {
public:
    DatabaseConstantDefaultValueSource(TableColumn* c, DatabaseConstant* cnst);
    DatabaseConstantDefaultValueSource(const DatabaseConstantDefaultValueSource& orig);
    virtual ~DatabaseConstantDefaultValueSource();
    virtual void setDatabaseConstant(DatabaseConstant* c) { _databaseConstant = c; }
    virtual bool hasDatabaseConstant() const { return (0 != _databaseConstant); }
    virtual DatabaseConstant* databaseConstant() const { return _databaseConstant; }
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
private:
    DatabaseConstant* _databaseConstant;
};

#endif	/* DATABASECONSTANTDEFAULTVALUESOURCE_H */

