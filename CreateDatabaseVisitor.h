/*
 * File:   CreateDatabaseVisitor.h
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 13:53
 */

#ifndef CREATEDATABASEVISITOR_H
#define	CREATEDATABASEVISITOR_H

#include "ComponentVisitor.h"

class CreateDatabaseVisitor: public ComponentVisitor {
public:
    CreateDatabaseVisitor();
    CreateDatabaseVisitor(const CreateDatabaseVisitor& orig);
    virtual ~CreateDatabaseVisitor();

    virtual std::vector<std::string> perform(DatabaseModel* m);
    virtual std::vector<std::string> perform(DatabaseConstant* c);
    virtual std::vector<std::string> perform(DataType* t);
    virtual std::vector<std::string> perform(Schema* s);
    virtual std::vector<std::string> perform(Sequence* s);
    virtual std::vector<std::string> perform(Table* t);
    virtual std::vector<std::string> perform(TableColumn* c);
    virtual std::vector<std::string> perform(PrimaryKeyConstraint* c);
    virtual std::vector<std::string> perform(UniqueConstraint* c);
    virtual std::vector<std::string> perform(PreventValueConstraint* c);
    virtual std::vector<std::string> perform(ForeignKeyConstraint* c);
    virtual std::vector<std::string> perform(SequenceDefaultValueSource* s);
    virtual std::vector<std::string> perform(DatabaseConstantDefaultValueSource* s);
    virtual std::vector<std::string> perform(TextDefaultValueSource* s);
    virtual std::vector<std::string> perform(IntegerDefaultValueSource* s);
    virtual std::vector<std::string> perform(NumericDefaultValueSource* s);
protected:
    virtual std::string toComment(const std::string& s) const;
private:

};

#endif	/* CREATEDATABASEVISITOR_H */

