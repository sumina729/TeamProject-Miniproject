DormitoryManagement : main.c  manager.o student.o
	gcc -o DormitoryManagement main.c  manager.o student.o

student.o : student.c student.h
	gcc -c student.o.c -o student.o

manager.o : manager.c manager.h
	gcc -c manager.c -o manager.o

clean : 
	rm *.o market
