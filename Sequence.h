/* 
 * File:   Sequence.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 17:11
 */

#ifndef SEQUENCE_H
#define	SEQUENCE_H

#include "InSchemaComponent.h"

class Sequence: public InSchemaComponent {
public:
    Sequence(Schema* s, const std::string& name);
    Sequence(const Sequence& orig);
    virtual ~Sequence();
    virtual std::vector<std::string> visit(ComponentVisitor* v);
private:

};
typedef std::map<std::string, Sequence*> SequenceMap;
typedef SequenceMap::const_iterator SequenceMapConstIterator;

#endif	/* SEQUENCE_H */

