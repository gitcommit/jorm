/* 
 * File:   InTableComponent.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 17:30
 */

#ifndef INTABLECOMPONENT_H
#define	INTABLECOMPONENT_H

#include "Component.h"

class Table;

class InTableComponent: public Component {
public:
    InTableComponent(Table* t, const std::string& name);
    InTableComponent(const InTableComponent& orig);
    virtual ~InTableComponent();
    Table* table() const;
private:

};

#endif	/* INTABLECOMPONENT_H */

