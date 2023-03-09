#makefile to test the program

TESTDIR:=Tests/
TESTFILES:=$(wildcard $(TESTDIR)test*)

EXECUTABLE:=wordLimit.out
SOURCECODE:=countColumn.c

compile:
	gcc -Wall $(SOURCECODE) -o $(EXECUTABLE)

run:
	@echo "For test1.c line 37 should show"
	@echo "For test2.java line 121 should show"
	@echo "For test3.cpp lines 17, 27, 29, 32, and 46 should show"
	@echo "For test4.c no lines should show"
	@echo "For test5.c line 3 should show"
	@echo "For test6.c lines 29, 31, 33, and 34 should show"
	for file in $(TESTFILES); do\
		echo "Executing $$file";\
		./$(EXECUTABLE) $$file;\
		echo "\n";\
	done

	@echo "Testing it now by including comments"
	for file in $(TESTFILES); do\
		echo "Executing $$file";\
		./$(EXECUTABLE) -i $$file;\
		echo "\n";\
	done

clean:
	rm $(EXECUTABLE)
