/* 
 * File:   DebuggerVisitor.cpp
 * Author: jolo
 * 
 * Created on 22. Dezember 2010, 13:53
 */

#include "DebuggerVisitor.h"

#include <vector>
#include <boost/assert.hpp>

#include "DataType.h"

DebuggerVisitor::DebuggerVisitor()
: ComponentVisitor() {
}

DebuggerVisitor::DebuggerVisitor(const DebuggerVisitor& orig)
: ComponentVisitor(orig) {
}

DebuggerVisitor::~DebuggerVisitor() {
}

std::vector<std::string> DebuggerVisitor::perform(DatabaseModel* m) {
    std::vector<std::string> buf;
    buf.push_back("DBM: " + m->name());
    
    DataTypeMap dtm = m->dataTypes();
    for (DataTypeMapConstIterator i = dtm.begin(); i != dtm.end(); ++i) {
        std::vector<std::string> b = i->second->visit(this);
        buf.insert(buf.end(), b.begin(), b.end());
    }
    DatabaseConstantMap dbcm = m->databaseConstants();
    for (DatabaseConstantMapConstIterator i = dbcm.begin(); i != dbcm.end(); ++i) {
        std::vector<std::string> b = i->second->visit(this);
        buf.insert(buf.end(), b.begin(), b.end());
    }
    SchemaMap schemata = m->schemata();
    for (SchemaMapConstIterator i = schemata.begin(); i != schemata.end(); ++i) {
        std::vector<std::string> b = i->second->visit(this);
        buf.insert(buf.end(), b.begin(), b.end());
    }
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(DataType* t) {
    std::vector<std::string> buf;
    buf.push_back("\tDBT: " + t->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(Schema* s) {
    std::vector<std::string> buf;
    BOOST_ASSERT(0 != s);
    buf.push_back("\tDBS: " + s->toString());

    SequenceMap sequences = s->sequences();
    for (SequenceMapConstIterator i = sequences.begin(); i != sequences.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }

    TableMap tables = s->tables();
    for(TableMapConstIterator i = tables.begin(); i != tables.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }
    
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(Table* t) {
    std::vector<std::string> buf;
    buf.push_back("\t\tTBL: " + t->toString());

    TableColumnMap columns = t->columns();
    for(TableColumnMapConstIterator i = columns.begin(); i != columns.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }
    if (t->hasPrimaryKeyConstraint()) {
        std::vector<std::string> tmp = t->primaryKeyConstraint()->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }

    UniqueConstraintMap um = t->uniqueConstraints();
    for (UniqueConstraintMapConstIterator i = um.begin(); i != um.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }

    PreventValueConstraintMap pvm = t->preventValueConstraints();
    for (PreventValueConstraintMapConstIterator i = pvm.begin(); i != pvm.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }

    ForeignKeyConstraintMap fkm = t->foreignKeyConstraints();
    for (ForeignKeyConstraintMapConstIterator i = fkm.begin(); i != fkm.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(TableColumn* c) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\tTC: " + c->toString());
    if (c->hasDefaultValueSource()) {
        std::vector<std::string> tmp = c->defaultValueSource()->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(PrimaryKeyConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\tPK: " + c->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(UniqueConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\tUC: " + c->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(PreventValueConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\tPVC: " + c->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(ForeignKeyConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\tFK: " + c->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(Sequence* s) {
    std::vector<std::string> buf;
    buf.push_back("\t\tSEQ: " + s->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(SequenceDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\t\tDefault: " + s->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(DatabaseConstant* s) {
    std::vector<std::string> buf;
    buf.push_back("\tDBCONST: " + s->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(DatabaseConstantDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\t\tDefault: " + s->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(TextDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\t\tDefault: " + s->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(IntegerDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\t\tDefault: " + s->toString());
    return buf;
}

std::vector<std::string> DebuggerVisitor::perform(NumericDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("\t\t\t\tDefault: " + s->toString());
    return buf;
}