/* 
 * File:   InDatabaseComponent.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 17:06
 */

#ifndef INDATABASECOMPONENT_H
#define	INDATABASECOMPONENT_H

#include "Component.h"

class DatabaseModel;

class InDatabaseComponent: public Component {
public:
    InDatabaseComponent(DatabaseModel* m, const std::string& name);
    InDatabaseComponent(const InDatabaseComponent& orig);
    virtual ~InDatabaseComponent();
    DatabaseModel* databaseModel() const;
};

#endif	/* INDATABASECOMPONENT_H */

