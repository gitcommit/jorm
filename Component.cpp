/* 
 * File:   Component.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 13:30
 */

#include "Component.h"

#include <iostream>

Component::Component(Component* p)
: _parent(p), _name("") {
    setParent(_parent);
    setName("");
}

Component::Component(Component* p, const std::string& name)
: _parent(p), _name(name) {
    setParent(p);
    setName(name);
}

Component::Component(const std::string& name)
: _parent(0), _name(name) {
    setParent(0);
    setName(name);
}

Component::Component(const Component& orig)
: _parent(orig._parent), _name(orig._name) {
    setParent(orig._parent);
    setName(orig._name);
}

Component::~Component() {
}

void Component::setName(const std::string& n) {
    _name = n;
}

std::string Component::name() const {
    return _name;
}

void Component::setParent(Component* p) {
    if (hasParent()) {
        if (p != parent()) {
            parent()->removeChild(this);
        }
    }
    _parent = p;
    if (0 != _parent) {
        _parent->addChild(this);
    }
}

void Component::addChild(Component* c) {
    _children.insert(make_pair(c->name(), c));
}

void Component::removeChild(Component* c) {
    ComponentMap::const_iterator delCand = _children.find(c->name());

    for (ComponentMapConstIterator i = _children.begin(); i != _children.end(); ++i) {
        std::cout << i->first << ": " << i->second;
    }
}

void Component::printOn(std::ostream& strm) {
    if (hasParent()) {
        strm << *(parent()) << ".";
    }
    strm << name();
}

std::map<std::string, Component*> Component::children() const {
    return _children;
}

Component* Component::parent() const {
    return _parent;
}

bool Component::hasParent() const {
    return (0 != _parent);
}

std::ostream & operator<<(std::ostream& s, Component& c) {
    c.printOn(s);
    return s;
}
