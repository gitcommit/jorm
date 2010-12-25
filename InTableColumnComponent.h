/* 
 * File:   InTableColumnComponent.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 11:23
 */

#ifndef INTABLECOLUMNCOMPONENT_H
#define	INTABLECOLUMNCOMPONENT_H

#include "Component.h"

class TableColumn;

class InTableColumnComponent: public Component {
public:
    InTableColumnComponent(TableColumn* p, const std::string& name);
    InTableColumnComponent(const InTableColumnComponent& orig);
    virtual ~InTableColumnComponent();
    TableColumn* tableColumn();
private:

};

#endif	/* INTABLECOLUMNCOMPONENT_H */

