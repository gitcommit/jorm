/* 
 * File:   Component.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 13:30
 */

#ifndef JORM_COMPONENT_H
#define	JORM_COMPONENT_H

#include <string>
#include <vector>
#include <map>
#include <ostream>

#include <boost/assert.hpp>

class ComponentVisitor;

class Component {
public:
    Component(Component* p = 0);
    Component(Component* p, const std::string& name);
    Component(const std::string& name);
    Component(const Component& orig);
    virtual ~Component();

    friend std::ostream & operator<<(std::ostream& s, Component& c);
    virtual void printOn(std::ostream& strm);
    virtual std::string toString() const;
    virtual void setName(const std::string& name);
    virtual void setParent(Component* p);
    virtual void addChild(Component* c);
    virtual void removeChild(Component* c);

    virtual std::map<std::string, Component* > children() const;
    virtual std::string name() const;
    virtual Component* parent() const;
    virtual bool hasParent() const;
    virtual std::vector<std::string> visit(ComponentVisitor* v) = 0;
private:
    Component* _parent;
    std::string _name;
    std::map<std::string, Component* > _children;
};
typedef std::map<std::string, Component* > ComponentMap;
typedef ComponentMap::const_iterator ComponentMapConstIterator;

#endif	/* JORM_COMPONENT_H */

