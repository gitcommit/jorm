/* 
 * File:   SequenceDefaultValueSource.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 11:03
 */

#ifndef SEQUENCEDEFAULTVALUESOURCE_H
#define	SEQUENCEDEFAULTVALUESOURCE_H

#include "DefaultValueSource.h"

class Sequence;

class SequenceDefaultValueSource: public DefaultValueSource {
public:
    SequenceDefaultValueSource(TableColumn* c, Sequence* s);
    SequenceDefaultValueSource(const SequenceDefaultValueSource& orig);
    virtual ~SequenceDefaultValueSource();
    virtual void setSequence(Sequence* s) { _sequence = s; }
    virtual Sequence* sequence() const { return _sequence; }
    virtual bool hasSequence() const { return (0 != _sequence); }
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
private:
    Sequence* _sequence;
};

#endif	/* SEQUENCEDEFAULTVALUESOURCE_H */

