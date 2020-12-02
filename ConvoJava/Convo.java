class Convo {

    static int[] convo(int sigTab[], int maskTab[]) {
        int i, sizeResult, acc, j, maskSize;
        int result[];

        sizeResult = sigTab.length-maskTab.length;
        result = new int[sizeResult];

        maskSize = maskTab.length;
        for(i = 0; i < sizeResult; i++){
            acc = 0;
            for(j = 0; j < maskSize; j++) acc += sigTab[i+j]*maskTab[j];
            result[i] = acc;
        }
        return result;
    }

    final static int SIGTAB_SIZE = 1000000;
    final static int MASKTAB_SIZE = 1024;

    public static void main(String[] args) {
        int result[];
        long startTime, endTime;
        System.out.println("Hello World !");

        int sig[] = new int[SIGTAB_SIZE];

        int mask[] = new int[MASKTAB_SIZE];

        for(int i=0;i<SIGTAB_SIZE;i++) sig[i]=1;
        for(int i=0;i<MASKTAB_SIZE;i++) mask[i]=1;

        startTime = System.currentTimeMillis();
        result = convo(sig, mask);
        endTime = System.currentTimeMillis();

        System.out.println("Java convo time = " + (endTime - startTime) + "ms");
    }
}