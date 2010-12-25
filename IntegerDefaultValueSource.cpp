/* 
 * File:   IntegerDefaultValueSource.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 17:45
 */

#include "IntegerDefaultValueSource.h"

#include "TableColumn.h"
#include "ComponentVisitor.h"

#include <sstream>

IntegerDefaultValueSource::IntegerDefaultValueSource(TableColumn* c, const long long& v)
: DefaultValueSource(c, c->name() + "_default_integer_value"), _value(v) {
    setValue(v);
}

IntegerDefaultValueSource::IntegerDefaultValueSource(const IntegerDefaultValueSource& orig)
: DefaultValueSource(orig), _value(orig._value) {
}

IntegerDefaultValueSource::~IntegerDefaultValueSource() {
}

std::vector<std::string> IntegerDefaultValueSource::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string IntegerDefaultValueSource::toString() const {
    std::stringstream strm;
    strm << value();
    return strm.str();
}