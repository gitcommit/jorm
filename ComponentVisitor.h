/* 
 * File:   ComponentVisitor.h
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 13:50
 */

#ifndef COMPONENTVISITOR_H
#define	COMPONENTVISITOR_H

#include <string>
#include <vector>

#include "UniqueConstraint.h"
#include "PreventValueConstraint.h"

#include "DatabaseModel.h"
#include "DataType.h"
#include "Schema.h"
#include "Sequence.h"
#include "Table.h"
#include "TableColumn.h"
#include "PrimaryKeyConstraint.h"
#include "UniqueConstraint.h"
#include "PreventValueConstraint.h"
#include "ForeignKeyConstraint.h"

class ComponentVisitor {
public:
    ComponentVisitor();
    ComponentVisitor(const ComponentVisitor& orig);
    virtual ~ComponentVisitor();

    virtual std::vector<std::string> perform(DatabaseModel* m) = 0;
    virtual std::vector<std::string> perform(DataType* t) = 0;
    virtual std::vector<std::string> perform(Schema* s) = 0;
    virtual std::vector<std::string> perform(Sequence* s) = 0;
    virtual std::vector<std::string> perform(Table* t) = 0;
    virtual std::vector<std::string> perform(TableColumn* c) = 0;
    virtual std::vector<std::string> perform(PrimaryKeyConstraint* c) = 0;
    virtual std::vector<std::string> perform(UniqueConstraint* c) = 0;
    virtual std::vector<std::string> perform(PreventValueConstraint* c) = 0;
    virtual std::vector<std::string> perform(ForeignKeyConstraint* c) = 0;
};

#endif	/* COMPONENTVISITOR_H */

