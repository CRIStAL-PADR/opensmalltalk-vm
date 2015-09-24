/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1468 uuid: 2b6a8fd8-cddf-447d-bee4-11d53d2ef9bc
   from
	SerialPlugin VMMaker.oscog-eem.1468 uuid: 2b6a8fd8-cddf-447d-bee4-11d53d2ef9bc
 */
static char __buildInfo[] = "SerialPlugin VMMaker.oscog-eem.1468 uuid: 2b6a8fd8-cddf-447d-bee4-11d53d2ef9bc " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "SerialPlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveSerialPortClose(void);
EXPORT(sqInt) primitiveSerialPortOpen(void);
EXPORT(sqInt) primitiveSerialPortRead(void);
EXPORT(sqInt) primitiveSerialPortWrite(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*integerObjectOf)(sqInt value);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt integerObjectOf(sqInt value);
extern sqInt isBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SerialPlugin VMMaker.oscog-eem.1468 (i)"
#else
	"SerialPlugin VMMaker.oscog-eem.1468 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* SerialPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return serialPortInit();
}

	/* SerialPlugin>>#primitiveSerialPortClose: */
EXPORT(sqInt)
primitiveSerialPortClose(void)
{
	sqInt portNum;

	portNum = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	serialPortClose(portNum);
	if (failed()) {
		return null;
	}
	pop(1);
	return null;
}

	/* SerialPlugin>>#primitiveSerialPortOpen:baudRate:stopBitsType:parityType:dataBits:inFlowControlType:outFlowControlType:xOnByte:xOffByte: */
EXPORT(sqInt)
primitiveSerialPortOpen(void)
{
	sqInt baudRate;
	sqInt dataBits;
	sqInt inFlowControl;
	sqInt outFlowControl;
	sqInt parityType;
	sqInt portNum;
	sqInt stopBitsType;
	sqInt xOffChar;
	sqInt xOnChar;

	portNum = stackIntegerValue(8);
	baudRate = stackIntegerValue(7);
	stopBitsType = stackIntegerValue(6);
	parityType = stackIntegerValue(5);
	dataBits = stackIntegerValue(4);
	inFlowControl = stackIntegerValue(3);
	outFlowControl = stackIntegerValue(2);
	xOnChar = stackIntegerValue(1);
	xOffChar = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	serialPortOpen(
			portNum, baudRate, stopBitsType, parityType, dataBits,
			inFlowControl, outFlowControl, xOnChar, xOffChar);
	if (failed()) {
		return null;
	}
	pop(9);
	return null;
}

	/* SerialPlugin>>#primitiveSerialPortRead:into:startingAt:count: */
EXPORT(sqInt)
primitiveSerialPortRead(void)
{
	char *array;
	sqInt arrayPtr;
	sqInt bytesRead;
	sqInt count;
	sqInt portNum;
	sqInt startIndex;
	sqInt _return_value;

	portNum = stackIntegerValue(3);
	success(isBytes(stackValue(2)));
	array = ((char *) (firstIndexableField(stackValue(2))));
	startIndex = stackIntegerValue(1);
	count = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	success((startIndex >= 1)
	 && (((startIndex + count) - 1) <= (byteSizeOf(((sqInt)(long)(array) - BaseHeaderSize)))));
	arrayPtr = ((((sqInt)array)) + startIndex) - 1;
	bytesRead = serialPortReadInto( portNum, count, arrayPtr);
	_return_value = integerObjectOf(bytesRead);
	if (failed()) {
		return null;
	}
	popthenPush(5, _return_value);
	return null;
}

	/* SerialPlugin>>#primitiveSerialPortWrite:from:startingAt:count: */
EXPORT(sqInt)
primitiveSerialPortWrite(void)
{
	char *array;
	sqInt arrayPtr;
	sqInt bytesWritten;
	sqInt count;
	sqInt portNum;
	sqInt startIndex;
	sqInt _return_value;

	bytesWritten = 0;
	portNum = stackIntegerValue(3);
	success(isBytes(stackValue(2)));
	array = ((char *) (firstIndexableField(stackValue(2))));
	startIndex = stackIntegerValue(1);
	count = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	success((startIndex >= 1)
	 && (((startIndex + count) - 1) <= (byteSizeOf(((sqInt)(long)(array) - BaseHeaderSize)))));
	if (!(failed())) {
		arrayPtr = ((((sqInt)array)) + startIndex) - 1;
		bytesWritten = serialPortWriteFrom(portNum, count, arrayPtr);
	}
	_return_value = integerObjectOf(bytesWritten);
	if (failed()) {
		return null;
	}
	popthenPush(5, _return_value);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		integerObjectOf = interpreterProxy->integerObjectOf;
		isBytes = interpreterProxy->isBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* SerialPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return serialPortShutdown();
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* SerialPlugin_exports[][3] = {
	{"SerialPlugin", "getModuleName", (void*)getModuleName},
	{"SerialPlugin", "initialiseModule", (void*)initialiseModule},
	{"SerialPlugin", "primitiveSerialPortClose\000\000", (void*)primitiveSerialPortClose},
	{"SerialPlugin", "primitiveSerialPortOpen\000\000", (void*)primitiveSerialPortOpen},
	{"SerialPlugin", "primitiveSerialPortRead\000\000", (void*)primitiveSerialPortRead},
	{"SerialPlugin", "primitiveSerialPortWrite\000\000", (void*)primitiveSerialPortWrite},
	{"SerialPlugin", "setInterpreter", (void*)setInterpreter},
	{"SerialPlugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveSerialPortCloseAccessorDepth = 0;
signed char primitiveSerialPortOpenAccessorDepth = 0;
signed char primitiveSerialPortReadAccessorDepth = 0;
signed char primitiveSerialPortWriteAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
