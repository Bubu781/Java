set JAVAPATH=C:\Program Files\AdoptOpenJDK\jdk-8.0.275.1-hotspot
set PATH=C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin;%PATH%
"%JAVAPATH%\bin\javac" TestJNI.java
"%JAVAPATH%\bin\javac" TestJNI.java -h .
gcc -c -I"%JAVAPATH%\include" -I"%JAVAPATH%\include\win32" -o myLIB.o myLIB.c
gcc -shared -o myLIB.dll myLIB.o
pause

