/* 
 * File:   Schema.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 15:47
 */

#include "Schema.h"

#include "DatabaseModel.h"
#include "ComponentVisitor.h"

Schema::Schema(DatabaseModel* m, const std::string& n)
: InDatabaseComponent(m, n) {
    m->addChild(this);
}

Schema::Schema(const Schema& orig)
: InDatabaseComponent(orig) {
}

Schema::~Schema() {
}

Sequence* Schema::addChild(Sequence* s) {
    _sequences.insert(std::make_pair(s->name(), s));
    return sequence(s->name());
}

Table* Schema::addChild(Table* t) {
    _tables.insert(std::make_pair(t->name(), t));
    databaseModel()->addChild(t);
    return table(t->name());
}

SequenceMap Schema::sequences() const {
    return _sequences;
}

TableMap Schema::tables() const {
    return _tables;
}

Table* Schema::table(const std::string& name) {
    TableMapConstIterator i = _tables.find(name);
    BOOST_ASSERT(_tables.end() != i);
    return i->second;
}

TableColumn* Schema::addChild(TableColumn* c) {
    _columns.insert(std::make_pair(c->qualifiedName(), c));
    databaseModel()->addChild(c);
    return c;
}

TableColumnMap Schema::tableColumns() const {
    return _columns;
}

std::vector<std::string> Schema::visit(ComponentVisitor* v) {
    return v->perform(this);
}

/*std::ostream& operator<<(std::ostream& s, Schema& c) {
    c.printOn(s);
    return s;
}
*/

Sequence* Schema::createSequence(const std::string& name) {
    return addChild(new Sequence(this, name));
}

Table* Schema::createTable(const std::string& name) {
    return addChild(new Table(this, name));
}

Sequence* Schema::sequence(const std::string& name) {
    SequenceMapConstIterator i = _sequences.find(name);
    BOOST_ASSERT(_sequences.end() != i);
    return i->second;
}

ForeignKeyConstraint* Schema::addChild(ForeignKeyConstraint* c) {
    _foreignKeyConstraints.insert(std::make_pair(c->name(), c));
    databaseModel()->addChild(c);
    return c;
}