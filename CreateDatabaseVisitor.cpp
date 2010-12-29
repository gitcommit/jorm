/*
 * File:   CreateDatabaseVisitor.cpp
 * Author: jolo
 *
 * Created on 22. Dezember 2010, 13:53
 */

#include "CreateDatabaseVisitor.h"

#include <vector>
#include <sstream>
#include <boost/assert.hpp>

#include "DataType.h"

CreateDatabaseVisitor::CreateDatabaseVisitor()
: ComponentVisitor() {
}

CreateDatabaseVisitor::CreateDatabaseVisitor(const CreateDatabaseVisitor& orig)
: ComponentVisitor(orig) {
}

CreateDatabaseVisitor::~CreateDatabaseVisitor() {
}

std::vector<std::string> CreateDatabaseVisitor::perform(DatabaseModel* m) {
    std::vector<std::string> buf;
    buf.push_back(toComment("CREATE DATABASE " + m->name() + ";"));

    DataTypeMap dataTypes = m->dataTypes();
    for (DataTypeMapConstIterator i = dataTypes.begin(); i != dataTypes.end(); i++) {
        std::vector<std::string> b = i->second->visit(this);
        buf.insert(buf.end(), b.begin(), b.end());
    }
    DatabaseConstantMap constants = m->databaseConstants();
    for (DatabaseConstantMapConstIterator i = constants.begin(); i != constants.end(); ++i) {
        std::vector<std::string> b = i->second->visit(this);
        buf.insert(buf.end(), b.begin(), b.end());
    }
    SchemaMap schemata = m->schemata();
    for (SchemaMapConstIterator i = schemata.begin(); i != schemata.end(); ++i) {
        std::vector<std::string> b = i->second->visit(this);
        buf.insert(buf.end(), b.begin(), b.end());
    }
    
    ForeignKeyConstraintMap fkm = m->foreignKeyConstraints();
    for (ForeignKeyConstraintMapConstIterator i = fkm.begin(); i != fkm.end(); ++i) {
        std::vector<std::string> tmp = i->second->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }
    return buf;

}

std::vector<std::string> CreateDatabaseVisitor::perform(DataType* t) {
    std::vector<std::string> buf;
    buf.push_back(toComment("Data Type: " + t->toString()));
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(Schema* s) {
    std::vector<std::string> buf;
    BOOST_ASSERT(0 != s);
    buf.push_back("CREATE SCHEMA " + s->name() + ";");

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

std::vector<std::string> CreateDatabaseVisitor::perform(Table* t) {
    std::vector<std::string> buf;
    buf.push_back("CREATE TABLE " + t->qualifiedName() + "();");

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

    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(TableColumn* c) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + c->table()->qualifiedName() + " ADD COLUMN "
                + c->name() + " " + c->dataType()->sqlName() + ";");
    if (c->hasDefaultValueSource()) {
        std::vector<std::string> tmp = c->defaultValueSource()->visit(this);
        buf.insert(buf.end(), tmp.begin(), tmp.end());
    }
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(PrimaryKeyConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + c->table()->qualifiedName() + " ADD CONSTRAINT " + c->name()
                    + " PRIMARY KEY (" + c->joinedColumnNames() + ");");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(UniqueConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + c->table()->qualifiedName() + " ADD CONSTRAINT " + c->name()
                    + " UNIQUE (" + c->joinedColumnNames() + ");");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(PreventValueConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + c->table()->qualifiedName() + " ADD CONSTRAINT " + c->name()
                    + " CHECK (" + c->joinedColumnNames() + " != " + c->value() + ");");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(ForeignKeyConstraint* c) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + c->table()->qualifiedName() + " ADD CONSTRAINT " + c->name()
                    + " FOREIGN KEY (" + c->joinedColumnNames() + ") REFERENCES "
                    + c->referencedTable()->qualifiedName() + "(" + c->joinedReferencedTableColumnNames() + ");");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(Sequence* s) {
    std::vector<std::string> buf;
    buf.push_back("CREATE SEQUENCE " + s->qualifiedName() + ";");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(SequenceDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + s->tableColumn()->table()->qualifiedName() + " ALTER COLUMN "
                    + s->tableColumn()->name() + " SET DEFAULT NEXTVAL('" + s->sequence()->qualifiedName() + "');");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(DatabaseConstant* s) {
    std::vector<std::string> buf;
    buf.push_back(toComment("Database Constant: " + s->toString()));
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(DatabaseConstantDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + s->tableColumn()->table()->qualifiedName() + " ALTER COLUMN "
                    + s->tableColumn()->name() + " SET DEFAULT " + s->databaseConstant()->name() + ";");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(TextDefaultValueSource* s) {
    std::vector<std::string> buf;
    buf.push_back("ALTER TABLE " + s->tableColumn()->table()->qualifiedName() + " ALTER COLUMN "
                    + s->tableColumn()->name() + " SET DEFAULT '" + s->defaultText() + "';");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(IntegerDefaultValueSource* s) {
    std::vector<std::string> buf;
    std::stringstream ss;
    ss << s->value();

    buf.push_back("ALTER TABLE " + s->tableColumn()->table()->qualifiedName() + " ALTER COLUMN "
                    + s->tableColumn()->name() + " SET DEFAULT " + ss.str() + ";");
    return buf;
}

std::vector<std::string> CreateDatabaseVisitor::perform(NumericDefaultValueSource* s) {
    std::vector<std::string> buf;
    std::stringstream ss;
    ss << s->value();

    buf.push_back("ALTER TABLE " + s->tableColumn()->table()->qualifiedName() + " ALTER COLUMN "
                    + s->tableColumn()->name() + " SET DEFAULT " + ss.str() + ";");
    return buf;
}

std::string CreateDatabaseVisitor::toComment(const std::string& s) const {
    std::stringstream ss;
    ss << "-- " << s;
    return ss.str();
}