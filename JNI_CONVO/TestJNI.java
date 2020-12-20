
class TestJNI {
	public native double[] convo(int arg1[], int arg2[]);

	static {
		// the file name must be "libmyLIB.so"
		System.loadLibrary("myLIB");
//		System.load("/home/alain/ALAIN/TestLecture/JAVA_TESTS/JNI/myLIB.so");
	}
	
    final static int SIGTAB_SIZE = 1000000;
    final static int MASKTAB_SIZE = 1024;
	public static void main(String[] args) {
        long startTime, endTime;
		
        int sig[] = new int[SIGTAB_SIZE];

		int mask[] = new int[MASKTAB_SIZE];
		
        for(int i=0;i<SIGTAB_SIZE;i++) sig[i]=1;
        for(int i=0;i<MASKTAB_SIZE;i++) mask[i]=1;
		double result[];

		// print the java library path
		//String property = System.getProperty("java.library.path");
		//System.out.println("java.library.path="+property);
		
		startTime = System.currentTimeMillis();
        result=new TestJNI().convo(sig, mask);
        endTime = System.currentTimeMillis();
		System.out.println("Java+C convo time = " + (endTime - startTime) + "ms");
	}
}
