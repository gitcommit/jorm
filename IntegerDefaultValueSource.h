/* 
 * File:   IntegerDefaultValueSource.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 17:45
 */

#ifndef INTEGERDEFAULTVALUESOURCE_H
#define	INTEGERDEFAULTVALUESOURCE_H

#include "DefaultValueSource.h"

class IntegerDefaultValueSource: public DefaultValueSource {
public:
    IntegerDefaultValueSource(TableColumn* c, const long long& v);
    IntegerDefaultValueSource(const IntegerDefaultValueSource& orig);
    virtual ~IntegerDefaultValueSource();
    virtual void setValue(const long long& v) { _value = v; }
    virtual long long value() const { return _value; }
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
private:
    long long _value;
};

#endif	/* INTEGERDEFAULTVALUESOURCE_H */

