/* 
 * File:   PreventValueConstraint.h
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 12:29
 */

#ifndef PREVENTVALUECONSTRAINT_H
#define	PREVENTVALUECONSTRAINT_H

#include "CheckConstraint.h"

class PreventValueConstraint: public CheckConstraint {
public:
    PreventValueConstraint(Table* t, const std::string& name, const std::string& value);
    PreventValueConstraint(const PreventValueConstraint& orig);
    virtual ~PreventValueConstraint();
    void setValue(const std::string& v);
    std::string value() const;
private:
    std::string _value;
};

typedef std::map<std::string, PreventValueConstraint*> PreventValueConstraintMap;
typedef PreventValueConstraintMap::const_iterator PreventValueConstraintMapConstIterator;

#endif	/* PREVENTVALUECONSTRAINT_H */

