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

class TableColumn: public InTableComponent {
public:
    TableColumn(Table* t, const std::string& name, DataType* t);
    TableColumn(const TableColumn& orig);
    virtual ~TableColumn();
    void setDataType(DataType* t) { _dataType = t; }
    DataType* dataType() const { return _dataType; }
    bool hasDataType() const { return (0 != _dataType); }
    virtual void printOn(std::ostream& strm);
    virtual std::string qualifiedName() const;
    virtual std::string namePath() const;
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
private:
    DataType* _dataType;
};

typedef std::map<std::string, TableColumn*> TableColumnMap;
typedef TableColumnMap::const_iterator TableColumnMapConstIterator;
typedef std::map<TableColumn*, TableColumn*> TableColumnPairMap;
typedef TableColumnPairMap::const_iterator TableColumnPairMapConstIterator;

#endif	/* TABLECOLUMN_H */

