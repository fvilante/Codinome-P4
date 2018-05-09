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
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Fast_Build
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BarCode.o \
	${OBJECTDIR}/BarCodeReader.o \
	${OBJECTDIR}/BarCodeValidationAlgorithm.o \
	${OBJECTDIR}/BusinessStateMachine.o \
	${OBJECTDIR}/Cabecote.o \
	${OBJECTDIR}/CabecoteRepository.o \
	${OBJECTDIR}/CorDaTinta.o \
	${OBJECTDIR}/Digital.o \
	${OBJECTDIR}/Drawer.o \
	${OBJECTDIR}/DrawerRepository.o \
	${OBJECTDIR}/EmergencyButtom.o \
	${OBJECTDIR}/Job.o \
	${OBJECTDIR}/JobConsumer.o \
	${OBJECTDIR}/JobProducer.o \
	${OBJECTDIR}/MaintenanceWindow.o \
	${OBJECTDIR}/Matriz.o \
	${OBJECTDIR}/MatrizRepository.o \
	${OBJECTDIR}/Queue.o \
	${OBJECTDIR}/Receiver.o \
	${OBJECTDIR}/ServiceLocatorBasic.o \
	${OBJECTDIR}/ServiceLocatorStub.o \
	${OBJECTDIR}/SimpleClass.o \
	${OBJECTDIR}/TimeStamp.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-O0
CXXFLAGS=-O0

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/software_p4-leoni.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/software_p4-leoni.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/software_p4-leoni ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BarCode.o: BarCode.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCode.o BarCode.cpp

${OBJECTDIR}/BarCodeReader.o: BarCodeReader.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCodeReader.o BarCodeReader.cpp

${OBJECTDIR}/BarCodeValidationAlgorithm.o: BarCodeValidationAlgorithm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCodeValidationAlgorithm.o BarCodeValidationAlgorithm.cpp

${OBJECTDIR}/BusinessStateMachine.o: BusinessStateMachine.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BusinessStateMachine.o BusinessStateMachine.cpp

${OBJECTDIR}/Cabecote.o: Cabecote.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cabecote.o Cabecote.cpp

${OBJECTDIR}/CabecoteRepository.o: CabecoteRepository.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CabecoteRepository.o CabecoteRepository.cpp

${OBJECTDIR}/CorDaTinta.o: CorDaTinta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CorDaTinta.o CorDaTinta.cpp

${OBJECTDIR}/Digital.o: Digital.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Digital.o Digital.cpp

${OBJECTDIR}/Drawer.o: Drawer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drawer.o Drawer.cpp

${OBJECTDIR}/DrawerRepository.o: DrawerRepository.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DrawerRepository.o DrawerRepository.cpp

${OBJECTDIR}/EmergencyButtom.o: EmergencyButtom.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EmergencyButtom.o EmergencyButtom.cpp

${OBJECTDIR}/Job.o: Job.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Job.o Job.cpp

${OBJECTDIR}/JobConsumer.o: JobConsumer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JobConsumer.o JobConsumer.cpp

${OBJECTDIR}/JobProducer.o: JobProducer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JobProducer.o JobProducer.cpp

${OBJECTDIR}/MaintenanceWindow.o: MaintenanceWindow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MaintenanceWindow.o MaintenanceWindow.cpp

${OBJECTDIR}/Matriz.o: Matriz.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Matriz.o Matriz.cpp

${OBJECTDIR}/MatrizRepository.o: MatrizRepository.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MatrizRepository.o MatrizRepository.cpp

${OBJECTDIR}/Queue.o: Queue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Queue.o Queue.cpp

${OBJECTDIR}/Receiver.o: Receiver.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Receiver.o Receiver.cpp

${OBJECTDIR}/ServiceLocatorBasic.o: ServiceLocatorBasic.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServiceLocatorBasic.o ServiceLocatorBasic.cpp

${OBJECTDIR}/ServiceLocatorStub.o: ServiceLocatorStub.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServiceLocatorStub.o ServiceLocatorStub.cpp

${OBJECTDIR}/SimpleClass.o: SimpleClass.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SimpleClass.o SimpleClass.cpp

${OBJECTDIR}/TimeStamp.o: TimeStamp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TimeStamp.o TimeStamp.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
