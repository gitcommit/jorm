/* 
 * File:   DefaultValueSource.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 10:51
 */

#include "DefaultValueSource.h"

DefaultValueSource::DefaultValueSource(TableColumn* c, const std::string& name)
: InTableColumnComponent(c, name){
}

DefaultValueSource::DefaultValueSource(const DefaultValueSource& orig)
: InTableColumnComponent(orig) {
}

DefaultValueSource::~DefaultValueSource() {
}

