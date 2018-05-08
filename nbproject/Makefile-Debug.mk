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
CND_CONF=Debug
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
	${OBJECTDIR}/BarCodeReaderTest.o \
	${OBJECTDIR}/BarCodeTest.o \
	${OBJECTDIR}/BarCodeValidationAlgorithm.o \
	${OBJECTDIR}/BusinessStateMachine.o \
	${OBJECTDIR}/BusinessStateMachineTest.o \
	${OBJECTDIR}/Cabecote.o \
	${OBJECTDIR}/CabecoteRepository.o \
	${OBJECTDIR}/CabecoteTest.o \
	${OBJECTDIR}/CorDaTinta.o \
	${OBJECTDIR}/DigitalSignal.o \
	${OBJECTDIR}/DigitalSignalTest.o \
	${OBJECTDIR}/Drawer.o \
	${OBJECTDIR}/DrawerRepository.o \
	${OBJECTDIR}/DrawerTest.o \
	${OBJECTDIR}/EmergencyButtom.o \
	${OBJECTDIR}/EmergencyButtomTest.o \
	${OBJECTDIR}/InputSignalStubTest.o \
	${OBJECTDIR}/Job.o \
	${OBJECTDIR}/JobConsumer.o \
	${OBJECTDIR}/JobProducer.o \
	${OBJECTDIR}/JobProducerTest.o \
	${OBJECTDIR}/JobTest.o \
	${OBJECTDIR}/MaintenanceWindow.o \
	${OBJECTDIR}/MaintenanceWindowTest.o \
	${OBJECTDIR}/Matriz.o \
	${OBJECTDIR}/MatrizRepository.o \
	${OBJECTDIR}/MatrizRepositoryTest.o \
	${OBJECTDIR}/MatrizTest.o \
	${OBJECTDIR}/Queue.o \
	${OBJECTDIR}/QueueTest.o \
	${OBJECTDIR}/ServiceLocatorBasic.o \
	${OBJECTDIR}/ServiceLocatorBasicTest.o \
	${OBJECTDIR}/ServiceLocatorStub.o \
	${OBJECTDIR}/SimpleClass.o \
	${OBJECTDIR}/SimpleClassTest.o \
	${OBJECTDIR}/TimeStamp.o \
	${OBJECTDIR}/TimeStampTest.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/software_p4-leoni.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/software_p4-leoni.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/software_p4-leoni ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BarCode.o: BarCode.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCode.o BarCode.cpp

${OBJECTDIR}/BarCodeReader.o: BarCodeReader.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCodeReader.o BarCodeReader.cpp

${OBJECTDIR}/BarCodeReaderTest.o: BarCodeReaderTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCodeReaderTest.o BarCodeReaderTest.cpp

${OBJECTDIR}/BarCodeTest.o: BarCodeTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCodeTest.o BarCodeTest.cpp

${OBJECTDIR}/BarCodeValidationAlgorithm.o: BarCodeValidationAlgorithm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BarCodeValidationAlgorithm.o BarCodeValidationAlgorithm.cpp

${OBJECTDIR}/BusinessStateMachine.o: BusinessStateMachine.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BusinessStateMachine.o BusinessStateMachine.cpp

${OBJECTDIR}/BusinessStateMachineTest.o: BusinessStateMachineTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BusinessStateMachineTest.o BusinessStateMachineTest.cpp

${OBJECTDIR}/Cabecote.o: Cabecote.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cabecote.o Cabecote.cpp

${OBJECTDIR}/CabecoteRepository.o: CabecoteRepository.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CabecoteRepository.o CabecoteRepository.cpp

${OBJECTDIR}/CabecoteTest.o: CabecoteTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CabecoteTest.o CabecoteTest.cpp

${OBJECTDIR}/CorDaTinta.o: CorDaTinta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CorDaTinta.o CorDaTinta.cpp

${OBJECTDIR}/DigitalSignal.o: DigitalSignal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DigitalSignal.o DigitalSignal.cpp

${OBJECTDIR}/DigitalSignalTest.o: DigitalSignalTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DigitalSignalTest.o DigitalSignalTest.cpp

${OBJECTDIR}/Drawer.o: Drawer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drawer.o Drawer.cpp

${OBJECTDIR}/DrawerRepository.o: DrawerRepository.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DrawerRepository.o DrawerRepository.cpp

${OBJECTDIR}/DrawerTest.o: DrawerTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DrawerTest.o DrawerTest.cpp

${OBJECTDIR}/EmergencyButtom.o: EmergencyButtom.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EmergencyButtom.o EmergencyButtom.cpp

${OBJECTDIR}/EmergencyButtomTest.o: EmergencyButtomTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EmergencyButtomTest.o EmergencyButtomTest.cpp

${OBJECTDIR}/InputSignalStubTest.o: InputSignalStubTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputSignalStubTest.o InputSignalStubTest.cpp

${OBJECTDIR}/Job.o: Job.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Job.o Job.cpp

${OBJECTDIR}/JobConsumer.o: JobConsumer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JobConsumer.o JobConsumer.cpp

${OBJECTDIR}/JobProducer.o: JobProducer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JobProducer.o JobProducer.cpp

${OBJECTDIR}/JobProducerTest.o: JobProducerTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JobProducerTest.o JobProducerTest.cpp

${OBJECTDIR}/JobTest.o: JobTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JobTest.o JobTest.cpp

${OBJECTDIR}/MaintenanceWindow.o: MaintenanceWindow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MaintenanceWindow.o MaintenanceWindow.cpp

${OBJECTDIR}/MaintenanceWindowTest.o: MaintenanceWindowTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MaintenanceWindowTest.o MaintenanceWindowTest.cpp

${OBJECTDIR}/Matriz.o: Matriz.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Matriz.o Matriz.cpp

${OBJECTDIR}/MatrizRepository.o: MatrizRepository.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MatrizRepository.o MatrizRepository.cpp

${OBJECTDIR}/MatrizRepositoryTest.o: MatrizRepositoryTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MatrizRepositoryTest.o MatrizRepositoryTest.cpp

${OBJECTDIR}/MatrizTest.o: MatrizTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MatrizTest.o MatrizTest.cpp

${OBJECTDIR}/Queue.o: Queue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Queue.o Queue.cpp

${OBJECTDIR}/QueueTest.o: QueueTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QueueTest.o QueueTest.cpp

${OBJECTDIR}/ServiceLocatorBasic.o: ServiceLocatorBasic.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServiceLocatorBasic.o ServiceLocatorBasic.cpp

${OBJECTDIR}/ServiceLocatorBasicTest.o: ServiceLocatorBasicTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServiceLocatorBasicTest.o ServiceLocatorBasicTest.cpp

${OBJECTDIR}/ServiceLocatorStub.o: ServiceLocatorStub.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServiceLocatorStub.o ServiceLocatorStub.cpp

${OBJECTDIR}/SimpleClass.o: SimpleClass.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SimpleClass.o SimpleClass.cpp

${OBJECTDIR}/SimpleClassTest.o: SimpleClassTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SimpleClassTest.o SimpleClassTest.cpp

${OBJECTDIR}/TimeStamp.o: TimeStamp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TimeStamp.o TimeStamp.cpp

${OBJECTDIR}/TimeStampTest.o: TimeStampTest.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TimeStampTest.o TimeStampTest.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/Users/Flavio/Google -IDrive\Flavio\10 -IProjetos\Leoni\P4-Retrofit\20 -ISoftware -IP4-Leoni\Software -I/C/Users/Flavio/Google\ Drive/Flavio/10\ -\ Projetos/Leoni/P4-Retrofit/20\ -\ Software\ P4-Leoni/Software\ P4-Leoni/date/include/date -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
