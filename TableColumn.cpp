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
#include "PreventValueConstraint.h"
#include "DefaultValueSource.h"
#include "SequenceDefaultValueSource.h"
#include "DatabaseConstantDefaultValueSource.h"
#include "TextDefaultValueSource.h"
#include "NumericDefaultValueSource.h"
#include "IntegerDefaultValueSource.h"
#include "ComponentVisitor.h"

TableColumn::TableColumn(Table* t, const std::string& name, DataType* ty)
: InTableComponent(t, name), _dataType(ty),
_isNullable(false), _defaultValueSource(0) {
    t->addChild(this);
    setDataType(ty);
}

TableColumn::TableColumn(const TableColumn& orig)
: InTableComponent(orig), _dataType(orig._dataType), _isNullable(orig._isNullable), _defaultValueSource(orig._defaultValueSource) {
}

TableColumn::~TableColumn() {
}

void TableColumn::printOn(std::ostream& strm) {
    strm << toString();
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

    if (isNullable()) {
        buf += " Nullable ";
    } else {
        buf += " Not Nullable ";
    }

    return buf;
}

PreventValueConstraint* TableColumn::createPreventValueConstraint(const std::string& name, const std::string& value) {
    table()->createPreventValueConstraint(name, value)->addColumn(this);
    return table()->preventValueConstraint(name);
}

ForeignKeyConstraint* TableColumn::createForeignKeyConstraint(const std::string& name, TableColumn* ref) {
    return table()->createForeignKeyConstraint(name, this, ref);
}

UniqueConstraint* TableColumn::createUniqueConstraint(const std::string& name) {
    table()->createUniqueConstraint(name)->addColumn(this);
    return table()->uniqueConstraint(name);
}

DefaultValueSource* TableColumn::createDefaultValueSource(Sequence* s) {
    _defaultValueSource = new SequenceDefaultValueSource(this, s);
    return defaultValueSource();
}

DefaultValueSource* TableColumn::createDefaultValueSource(DatabaseConstant* c) {
    _defaultValueSource = new DatabaseConstantDefaultValueSource(this, c);
    return defaultValueSource();
}

DefaultValueSource* TableColumn::createDefaultValueSource(const std::string& txt) {
    _defaultValueSource = new TextDefaultValueSource(this, txt);
    return defaultValueSource();
}

DefaultValueSource* TableColumn::createDefaultValueSource(const double& d) {
    _defaultValueSource = new NumericDefaultValueSource(this, d);
    return defaultValueSource();
}

DefaultValueSource* TableColumn::createDefaultValueSource(const long long& i) {
    _defaultValueSource = new IntegerDefaultValueSource(this, i);
    return defaultValueSource();
}