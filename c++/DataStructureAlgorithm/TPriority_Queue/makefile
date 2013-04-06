test.exe:test.obj
	echo "linking"
	link test.obj
	
test.obj:test.cpp
	echo "conpiling"
	cl -c test.cpp
	
clean:
	del *.obj,*.exe