/* 
 * File:   DebuggerVisitor.h
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 13:53
 */

#ifndef DEBUGGERVISITOR_H
#define	DEBUGGERVISITOR_H

#include "ComponentVisitor.h"

class DebuggerVisitor: public ComponentVisitor {
public:
    DebuggerVisitor();
    DebuggerVisitor(const DebuggerVisitor& orig);
    virtual ~DebuggerVisitor();

    virtual std::vector<std::string> perform(DatabaseModel* m);
    virtual std::vector<std::string> perform(DataType* t);
    virtual std::vector<std::string> perform(Schema* s);
    virtual std::vector<std::string> perform(Sequence* s);
    virtual std::vector<std::string> perform(Table* t);
    virtual std::vector<std::string> perform(TableColumn* c);
    virtual std::vector<std::string> perform(PrimaryKeyConstraint* c);
    virtual std::vector<std::string> perform(UniqueConstraint* c);
    virtual std::vector<std::string> perform(PreventValueConstraint* c);
    virtual std::vector<std::string> perform(ForeignKeyConstraint* c);
private:

};

#endif	/* DEBUGGERVISITOR_H */

