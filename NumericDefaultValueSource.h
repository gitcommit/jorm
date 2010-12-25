/* 
 * File:   NumericDefaultValueSource.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 17:42
 */

#ifndef NUMERICDEFAULTVALUESOURCE_H
#define	NUMERICDEFAULTVALUESOURCE_H

#include "DefaultValueSource.h"
#include "TableColumn.h"

class ComponentVisitor;

class NumericDefaultValueSource: public DefaultValueSource {
public:
    NumericDefaultValueSource(TableColumn* c, const double& value);
    NumericDefaultValueSource(const NumericDefaultValueSource& orig);
    virtual ~NumericDefaultValueSource();
    virtual void setValue(const double& d) { _value = d; }
    virtual double value() const { return _value; }
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
private:
    double _value;
};

#endif	/* NUMERICDEFAULTVALUESOURCE_H */

