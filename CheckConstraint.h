/* 
 * File:   CheckConstraint.h
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 12:28
 */

#ifndef CHECKCONSTRAINT_H
#define	CHECKCONSTRAINT_H

#include "TableConstraint.h"

class CheckConstraint: public TableConstraint {
public:
    CheckConstraint(Table* t, const std::string& name);
    CheckConstraint(const CheckConstraint& orig);
    virtual ~CheckConstraint();
private:

};

#endif	/* CHECKCONSTRAINT_H */

