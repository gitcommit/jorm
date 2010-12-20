/* 
 * File:   DataType.cpp
 * Author: jolo
 * 
 * Created on 20. Dezember 2010, 16:50
 */

#include "DataType.h"

#include "DatabaseModel.h"

DataType::DataType(DatabaseModel* m, const std::string& n, const std::string& sqlN)
: InDatabaseComponent(m, n), _sqlName(sqlN) {
    m->addChild(this);
}

DataType::DataType(const DataType& orig)
: InDatabaseComponent(orig), _sqlName(orig._sqlName) {
}

DataType::~DataType() {
}

