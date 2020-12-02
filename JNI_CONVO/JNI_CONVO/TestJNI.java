
class TestJNI {
	public native double[] convo(int arg1[], int arg2[]);

	static {
		// the file name must be "libmyLIB.so"
		System.loadLibrary("myLIB");
//		System.load("/home/alain/ALAIN/TestLecture/JAVA_TESTS/JNI/myLIB.so");
	}

	public static void main(String[] args) {
		int arg1[]={1,2,3,4};
		int arg2[]={10, 20, 30, 40};
		double result[];

		// print the java library path
		String property = System.getProperty("java.library.path");
		System.out.println("java.library.path="+property);

		TestJNI tjni=new TestJNI();
		result=tjni.convo(arg1, arg2);
		for(int i=0; i<result.length; i++) System.out.println("res["+i+"]="+result[i]);
	}
}
