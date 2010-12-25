/* 
 * File:   RegisterBoostTypes.h
 * Author: jolo
 *
 * Created on 20. Dezember 2010, 16:27
 */

#ifndef JORM_REGISTER_BOOST_TYPES
#define JORM_REGISTER_BOOST_TYPES

#include "DatabaseConstantDefaultValueSource.h"


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <boost/typeof/typeof.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP();

#include "Component.h"
#include "DatabaseModel.h"
#include "DatabaseConstant.h"
#include "Schema.h"
#include "DataType.h"
#include "Sequence.h"
#include "Table.h"
#include "TableColumn.h"
#include "PrimaryKeyConstraint.h"
#include "UniqueConstraint.h"
#include "PreventValueConstraint.h"
#include "DefaultValueSource.h"
#include "SequenceDefaultValueSource.h"

typedef std::vector<std::string> StringVector;
typedef StringVector::const_iterator StringVectorConstIterator;

BOOST_TYPEOF_REGISTER_TYPE(Component)
BOOST_TYPEOF_REGISTER_TYPE(DatabaseModel)
BOOST_TYPEOF_REGISTER_TYPE(DatabaseConstant)
BOOST_TYPEOF_REGISTER_TYPE(Schema)
BOOST_TYPEOF_REGISTER_TYPE(DataType)
BOOST_TYPEOF_REGISTER_TYPE(Schema)
BOOST_TYPEOF_REGISTER_TYPE(Table)
BOOST_TYPEOF_REGISTER_TYPE(TableColumn)
BOOST_TYPEOF_REGISTER_TYPE(TableConstraint)
BOOST_TYPEOF_REGISTER_TYPE(PrimaryKeyConstraint)
BOOST_TYPEOF_REGISTER_TYPE(UniqueConstraint)
BOOST_TYPEOF_REGISTER_TYPE(PreventValueConstraint)
BOOST_TYPEOF_REGISTER_TYPE(DefaultValueSource)
BOOST_TYPEOF_REGISTER_TYPE(SequenceDefaultValueSource)
BOOST_TYPEOF_REGISTER_TYPE(DatabaseConstantDefaultValueSource)
        
/*void test() {

    ComponentMap mp;
    mp.insert(std::make_pair("model", new DatabaseModel("model")));
    mp.insert(std::make_pair("model2", new DatabaseModel("model 2")));
    for (ComponentMapConstIterator i  = mp.begin(); i != mp.end(); ++i) {
        if ((boost::is_same<BOOST_TYPEOF(i->second), Component*>::value)) {
            std::cout << std::endl << "OK: " << *(i->second) << std::endl;
        } else {
            std::cout << std::endl << "FAIL: " << *(i->second) << std::endl;
        }
    }
}
*/
#endif

