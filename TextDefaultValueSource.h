/* 
 * File:   TextDefaultValueSource.h
 * Author: jolo
 *
 * Created on 25. Dezember 2010, 17:26
 */

#ifndef TEXTDEFAULTVALUESOURCE_H
#define	TEXTDEFAULTVALUESOURCE_H

#include "DefaultValueSource.h"

class ComponentVisitor;

class TextDefaultValueSource: public DefaultValueSource {
public:
    TextDefaultValueSource(TableColumn* c, const std::string& name);
    TextDefaultValueSource(const TextDefaultValueSource& orig);
    virtual ~TextDefaultValueSource();
    virtual std::vector<std::string> visit(ComponentVisitor* v);
    virtual std::string toString() const;
    virtual void setDefaultText(const std::string& t) { _defaultText = t; }
    virtual std::string defaultText() const { return _defaultText; }
private:
    std::string _defaultText;
};

#endif	/* TEXTDEFAULTVALUESOURCE_H */

