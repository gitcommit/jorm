/* 
 * File:   TableColumn.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 17:32
 */

#include "TableColumn.h"

#include "Schema.h"
#include "Table.h"
#include "DataType.h"
#include "ComponentVisitor.h"

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

std::string TableColumn::qualifiedName() const {
    return table()->name() + "." + name();
}

std::string TableColumn::namePath() const {
    return table()->schema()->name() + "." + qualifiedName();
}

std::vector<std::string> TableColumn::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string TableColumn::toString() const {
    std::string buf = namePath();
    if (hasDataType()) {
        buf += " " + dataType()->sqlName();
    }
    return buf;
}