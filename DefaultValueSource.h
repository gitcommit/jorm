/* 
 * File:   DefaultValueSource.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 10:51
 */

#ifndef DEFAULTVALUESOURCE_H
#define	DEFAULTVALUESOURCE_H

#include "InTableColumnComponent.h"

class DefaultValueSource: public InTableColumnComponent {
public:
    DefaultValueSource(TableColumn* col, const std::string& name);
    DefaultValueSource(const DefaultValueSource& orig);
    virtual ~DefaultValueSource();
private:

};

#endif	/* DEFAULTVALUESOURCE_H */

