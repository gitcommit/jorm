/* 
 * File:   Schema.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 15:47
 */

#include "Schema.h"

#include "DatabaseModel.h"

Schema::Schema(DatabaseModel* m, const std::string& n)
: InDatabaseComponent(m, n) {
    m->addChild(this);
}

Schema::Schema(const Schema& orig)
: InDatabaseComponent(orig) {
}

Schema::~Schema() {
}

void Schema::addChild(Sequence* s) {
    _sequences.insert(std::make_pair(s->name(), s));
}

void Schema::addChild(Table* t) {
    _tables.insert(std::make_pair(t->name(), t));
}

SequenceMap Schema::sequences() const {
    return _sequences;
}

TableMap Schema::tables() const {
    return _tables;
}

Table* Schema::table(const std::string& name) {
    TableMapConstIterator i = _tables.find(name);
    if (i == _tables.end()) {
        return 0;
    }
    return i->second;
}
/*std::ostream& operator<<(std::ostream& s, Schema& c) {
    c.printOn(s);
    return s;
}
*/
