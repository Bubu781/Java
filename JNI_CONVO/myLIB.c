#include <jni.h>
#include <stdio.h>
#include <malloc.h>
#include "TestJNI.h"

JNIEXPORT jdoubleArray JNICALL
Java_TestJNI_convo(JNIEnv *env, jobject obj, jintArray javaIntArrayArg1, jintArray javaIntArrayArg2) {
	int  i, sizeResult,acc,j;
	// Convert the Java Int Array into C int Array
	jint *cIntArrayArg1=(*env)->GetIntArrayElements(env, javaIntArrayArg1, NULL);
	jint *cIntArrayArg2=(*env)->GetIntArrayElements(env, javaIntArrayArg2, NULL);

	// check input argument validity
	if(cIntArrayArg1==NULL) return NULL;
	if(cIntArrayArg2==NULL) return NULL;
	jsize sizeSig=(*env)->GetArrayLength(env, javaIntArrayArg1);
	jsize sizeMask=(*env)->GetArrayLength(env, javaIntArrayArg2);
	sizeResult=sizeSig-sizeMask;

	// create C result Array
	jdouble *cDoubleArrayResult=malloc(sizeof(jdouble)*sizeResult);
	if(cDoubleArrayResult==NULL) return NULL;

	// perform operation
	for(i=0; i<sizeResult; i++) {
			acc=0;
			for(j=0; j<sizeMask; j++) acc+=(jdouble)cIntArrayArg1[i+j]*cIntArrayArg2[j];
			cDoubleArrayResult[i]=acc;
	}

	// Release resources
	(*env)->ReleaseIntArrayElements(env, javaIntArrayArg1, cIntArrayArg1, 0);
	(*env)->ReleaseIntArrayElements(env, javaIntArrayArg2, cIntArrayArg2, 0);

	// create Java result Array
	jdoubleArray javaDoubleArrayResult=(*env)->NewDoubleArray(env,sizeResult);
	if(javaDoubleArrayResult==NULL) return NULL;

	// Copy C result array into Java result Array
	(*env)->SetDoubleArrayRegion(env, javaDoubleArrayResult, 0, sizeResult, cDoubleArrayResult);

	return javaDoubleArrayResult;
}
