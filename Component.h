/* 
 * File:   Component.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 13:30
 */

#ifndef JORM_COMPONENT_H
#define	JORM_COMPONENT_H

#include <string>
#include <ostream>
#include <map>

class Component {
public:
    Component(Component* p = 0);
    Component(Component* p, const std::string& name);
    Component(const std::string& name);
    Component(const Component& orig);
    virtual ~Component();

    friend std::ostream & operator<<(std::ostream& s, Component& c);
    virtual void printOn(std::ostream& strm);

    virtual void setName(const std::string& name);
    virtual void setParent(Component* p);
    virtual void addChild(Component* c);
    virtual void removeChild(Component* c);

    virtual std::map<std::string, Component*> children() const {
        return _children;
    }

    virtual std::string name() const;

    virtual Component* parent() const {
        return _parent;
    }

    virtual bool hasParent() const {
        return 0 != _parent;
    }
private:
    Component* _parent;
    std::string _name;
    std::map<std::string, Component*> _children;
};
typedef std::map<std::string, Component*> ComponentMap;
typedef ComponentMap::const_iterator ComponentMapConstIterator;

#endif	/* JORM_COMPONENT_H */

