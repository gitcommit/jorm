#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sequence.o \
	${OBJECTDIR}/TableColumn.o \
	${OBJECTDIR}/Schema.o \
	${OBJECTDIR}/InDatabaseComponent.o \
	${OBJECTDIR}/DatabaseModel.o \
	${OBJECTDIR}/InTableComponent.o \
	${OBJECTDIR}/Component.o \
	${OBJECTDIR}/InSchemaComponent.o \
	${OBJECTDIR}/Table.o \
	${OBJECTDIR}/DataType.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-MacOSX/libjorm.dylib

dist/Debug/GNU-MacOSX/libjorm.dylib: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-MacOSX
	${LINK.cc} -dynamiclib -install_name libjorm.dylib -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libjorm.dylib -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Sequence.o: Sequence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sequence.o Sequence.cpp

${OBJECTDIR}/TableColumn.o: TableColumn.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/TableColumn.o TableColumn.cpp

${OBJECTDIR}/Schema.o: Schema.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Schema.o Schema.cpp

${OBJECTDIR}/InDatabaseComponent.o: InDatabaseComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InDatabaseComponent.o InDatabaseComponent.cpp

${OBJECTDIR}/DatabaseModel.o: DatabaseModel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatabaseModel.o DatabaseModel.cpp

${OBJECTDIR}/InTableComponent.o: InTableComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InTableComponent.o InTableComponent.cpp

${OBJECTDIR}/Component.o: Component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Component.o Component.cpp

${OBJECTDIR}/InSchemaComponent.o: InSchemaComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InSchemaComponent.o InSchemaComponent.cpp

${OBJECTDIR}/Table.o: Table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Table.o Table.cpp

${OBJECTDIR}/DataType.o: DataType.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DataType.o DataType.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-MacOSX/libjorm.dylib

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
