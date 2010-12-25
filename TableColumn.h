/* 
 * File:   TableColumn.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 17:32
 */

#ifndef TABLECOLUMN_H
#define	TABLECOLUMN_H

#include "InTableComponent.h"

class DataType;
class PreventValueConstraint;
class ForeignKeyConstraint;
class UniqueConstraint;
class DefaultValueSource;
class Sequence;
class DatabaseConstant;

class TableColumn: public InTableComponent {
public:
    TableColumn(Table* t, const std::string& name, DataType* t);
    TableColumn(const TableColumn& orig);
    virtual ~TableColumn();
    void setDataType(DataType* t) { _dataType = t; }
    DataType* dataType() const { return _dataType; }
    ForeignKeyConstraint* createForeignKeyConstraint(const std::string& name, TableColumn* ref);
    UniqueConstraint* createUniqueConstraint(const std::string& name);
    bool hasDataType() const { return (0 != _dataType); }
    virtual void printOn(std::ostream& strm);
    virtual void setNullable(const bool& b) { _isNullable = b; }
    virtual bool isNullable() const { return _isNullable; }
    virtual std::string qualifiedName() const;
    virtual std::string namePath() const;
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
    virtual PreventValueConstraint* createPreventValueConstraint(const std::string& name, const std::string& value);
    virtual DefaultValueSource* createDefaultValueSource(Sequence* s);
    virtual DefaultValueSource* createDefaultValueSource(DatabaseConstant* c);
    virtual DefaultValueSource* createDefaultValueSource(const std::string& txt);
    virtual DefaultValueSource* createDefaultValueSource(const double& d);
    virtual DefaultValueSource* createDefaultValueSource(const long long& i);
    virtual DefaultValueSource* defaultValueSource() const { return _defaultValueSource; }
    virtual bool hasDefaultValueSource() const { return (0 != _defaultValueSource); }
private:
    DataType* _dataType;
    bool _isNullable;
    DefaultValueSource* _defaultValueSource;
};

typedef std::map<std::string, TableColumn*> TableColumnMap;
typedef TableColumnMap::const_iterator TableColumnMapConstIterator;
typedef std::map<TableColumn*, TableColumn*> TableColumnPairMap;
typedef TableColumnPairMap::const_iterator TableColumnPairMapConstIterator;

#endif	/* TABLECOLUMN_H */

