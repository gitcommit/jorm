/* 
 * File:   PrimaryKeyConstraint.h
 * Author: jolo
 *
 * Created on 21. Dezember 2010, 09:58
 */

#ifndef PRIMARYKEYCONSTRAINT_H
#define	PRIMARYKEYCONSTRAINT_H

#include "TableConstraint.h"

class PrimaryKeyConstraint: public TableConstraint {
public:
    PrimaryKeyConstraint(Table* t, const std::string& name);
    PrimaryKeyConstraint(const PrimaryKeyConstraint& orig);
    virtual ~PrimaryKeyConstraint();
};

#endif	/* PRIMARYKEYCONSTRAINT_H */

