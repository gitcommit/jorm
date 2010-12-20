/* 
 * File:   TableColumn.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:32
 */

#include "TableColumn.h"

#include "Table.h"
#include "DataType.h"

TableColumn::TableColumn(Table* t, const std::string& name, DataType* ty)
: InTableComponent(t, name), _dataType(ty) {
    t->addChild(this);
    setDataType(ty);
}

TableColumn::TableColumn(const TableColumn& orig)
: InTableComponent(orig), _dataType(orig._dataType) {
}

TableColumn::~TableColumn() {
}

void TableColumn::printOn(std::ostream& strm) {
    strm << name() << " " << dataType()->sqlName();
}