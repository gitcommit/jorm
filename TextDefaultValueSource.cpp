/* 
 * File:   TextDefaultValueSource.cpp
 * Author: jolo
 * 
 * Created on 25. Dezember 2010, 17:26
 */

#include "TextDefaultValueSource.h"
#include "TableColumn.h"
#include "ComponentVisitor.h"

TextDefaultValueSource::TextDefaultValueSource(TableColumn* c, const std::string& n)
: DefaultValueSource(c, c->name() + "_default_text"), _defaultText(n) {
    setDefaultText(n);
}

TextDefaultValueSource::TextDefaultValueSource(const TextDefaultValueSource& orig)
: DefaultValueSource(orig), _defaultText(orig._defaultText) {
}

TextDefaultValueSource::~TextDefaultValueSource() {
}

std::vector<std::string> TextDefaultValueSource::visit(ComponentVisitor* c) {
    return c->perform(this);
}

std::string TextDefaultValueSource::toString() const {
    return _defaultText;
}