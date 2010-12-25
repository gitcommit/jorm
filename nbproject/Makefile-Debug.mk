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
	${OBJECTDIR}/PreventValueConstraint.o \
	${OBJECTDIR}/Schema.o \
	${OBJECTDIR}/PrimaryKeyConstraint.o \
	${OBJECTDIR}/InDatabaseComponent.o \
	${OBJECTDIR}/DatabaseConstant.o \
	${OBJECTDIR}/DatabaseModel.o \
	${OBJECTDIR}/InTableComponent.o \
	${OBJECTDIR}/Component.o \
	${OBJECTDIR}/UniqueConstraint.o \
	${OBJECTDIR}/SequenceDefaultValueSource.o \
	${OBJECTDIR}/CreateDatabaseVisitor.o \
	${OBJECTDIR}/DebuggerVisitor.o \
	${OBJECTDIR}/DatabaseConstantDefaultValueSource.o \
	${OBJECTDIR}/InSchemaComponent.o \
	${OBJECTDIR}/CheckConstraint.o \
	${OBJECTDIR}/ForeignKeyConstraint.o \
	${OBJECTDIR}/ComponentVisitor.o \
	${OBJECTDIR}/DataType.o \
	${OBJECTDIR}/DefaultValueSource.o \
	${OBJECTDIR}/Table.o \
	${OBJECTDIR}/NumericDefaultValueSource.o \
	${OBJECTDIR}/TableConstraint.o \
	${OBJECTDIR}/InTableColumnComponent.o \
	${OBJECTDIR}/TextDefaultValueSource.o \
	${OBJECTDIR}/IntegerDefaultValueSource.o


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

${OBJECTDIR}/PreventValueConstraint.o: PreventValueConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/PreventValueConstraint.o PreventValueConstraint.cpp

${OBJECTDIR}/Schema.o: Schema.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Schema.o Schema.cpp

${OBJECTDIR}/PrimaryKeyConstraint.o: PrimaryKeyConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/PrimaryKeyConstraint.o PrimaryKeyConstraint.cpp

${OBJECTDIR}/InDatabaseComponent.o: InDatabaseComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InDatabaseComponent.o InDatabaseComponent.cpp

${OBJECTDIR}/DatabaseConstant.o: DatabaseConstant.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatabaseConstant.o DatabaseConstant.cpp

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

${OBJECTDIR}/UniqueConstraint.o: UniqueConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/UniqueConstraint.o UniqueConstraint.cpp

${OBJECTDIR}/SequenceDefaultValueSource.o: SequenceDefaultValueSource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SequenceDefaultValueSource.o SequenceDefaultValueSource.cpp

${OBJECTDIR}/CreateDatabaseVisitor.o: CreateDatabaseVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/CreateDatabaseVisitor.o CreateDatabaseVisitor.cpp

${OBJECTDIR}/DebuggerVisitor.o: DebuggerVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DebuggerVisitor.o DebuggerVisitor.cpp

${OBJECTDIR}/DatabaseConstantDefaultValueSource.o: DatabaseConstantDefaultValueSource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatabaseConstantDefaultValueSource.o DatabaseConstantDefaultValueSource.cpp

${OBJECTDIR}/InSchemaComponent.o: InSchemaComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InSchemaComponent.o InSchemaComponent.cpp

${OBJECTDIR}/CheckConstraint.o: CheckConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/CheckConstraint.o CheckConstraint.cpp

${OBJECTDIR}/ForeignKeyConstraint.o: ForeignKeyConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ForeignKeyConstraint.o ForeignKeyConstraint.cpp

${OBJECTDIR}/ComponentVisitor.o: ComponentVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ComponentVisitor.o ComponentVisitor.cpp

${OBJECTDIR}/DataType.o: DataType.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DataType.o DataType.cpp

${OBJECTDIR}/DefaultValueSource.o: DefaultValueSource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DefaultValueSource.o DefaultValueSource.cpp

${OBJECTDIR}/Table.o: Table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Table.o Table.cpp

${OBJECTDIR}/NumericDefaultValueSource.o: NumericDefaultValueSource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/NumericDefaultValueSource.o NumericDefaultValueSource.cpp

${OBJECTDIR}/TableConstraint.o: TableConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/TableConstraint.o TableConstraint.cpp

${OBJECTDIR}/InTableColumnComponent.o: InTableColumnComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InTableColumnComponent.o InTableColumnComponent.cpp

${OBJECTDIR}/TextDefaultValueSource.o: TextDefaultValueSource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/TextDefaultValueSource.o TextDefaultValueSource.cpp

${OBJECTDIR}/IntegerDefaultValueSource.o: IntegerDefaultValueSource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I../../../usr/boost/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IntegerDefaultValueSource.o IntegerDefaultValueSource.cpp

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
