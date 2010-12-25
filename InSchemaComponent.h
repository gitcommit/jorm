/* 
 * File:   InSchemaComponent.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 17:09
 */

#ifndef INSCHEMACOMPONENT_H
#define	INSCHEMACOMPONENT_H

#include "Component.h"

class Schema;

class InSchemaComponent: public Component {
public:
    InSchemaComponent(Schema* s, const std::string& name);
    InSchemaComponent(const InSchemaComponent& orig);
    virtual ~InSchemaComponent();
    Schema* schema() const;
    virtual std::string qualifiedName() const;
private:

};

#endif	/* INSCHEMACOMPONENT_H */

