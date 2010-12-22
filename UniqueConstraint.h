/* 
 * File:   UniqueConstraint.h
 * Author: jolo
 *
 * Created on 21. Dezember 2010, 17:28
 */

#ifndef UNIQUECONSTRAINT_H
#define	UNIQUECONSTRAINT_H

#include "TableConstraint.h"

class UniqueConstraint: public TableConstraint {
public:
    UniqueConstraint(Table* t, const std::string& name);
    UniqueConstraint(const UniqueConstraint& orig);
    virtual ~UniqueConstraint();
private:
};

typedef std::map<std::string, UniqueConstraint*> UniqueConstraintMap;
typedef UniqueConstraintMap::const_iterator UniqueConstraintMapConstIterator;

#endif	/* UNIQUECONSTRAINT_H */

