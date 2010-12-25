/* 
 * File:   NumericDefaultValueSource.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 17:42
 */

#include "NumericDefaultValueSource.h"

#include "TableColumn.h"
#include "ComponentVisitor.h"

#include <sstream>

NumericDefaultValueSource::NumericDefaultValueSource(TableColumn* c, const double& d)
: DefaultValueSource(c, c->name() + "_default_double_value"), _value(d) {
    setValue(d);
}

NumericDefaultValueSource::NumericDefaultValueSource(const NumericDefaultValueSource& orig)
: DefaultValueSource(orig), _value(orig._value) {
}

NumericDefaultValueSource::~NumericDefaultValueSource() {
}

std::vector<std::string> NumericDefaultValueSource::visit(ComponentVisitor* v) {
    return v->perform(this);
}

std::string NumericDefaultValueSource::toString() const {
    std::stringstream strm;
    strm << value();
    return strm.str();
}