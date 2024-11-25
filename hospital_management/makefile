CC = gcc
CFLAGS = -Wall -g

OBJS = main.o receptionist.o doctor.o patient.o utility.o disease_info.o

hospital_management: $(OBJS)
	$(CC) $(CFLAGS) -o hospital_management $(OBJS)

main.o: main.c utility.h patient.h doctor.h receptionist.h
	$(CC) $(CFLAGS) -c main.c

receptionist.o: receptionist.c receptionist.h patient.h doctor.h
	$(CC) $(CFLAGS) -c receptionist.c

doctor.o: doctor.c doctor.h utility.h
	$(CC) $(CFLAGS) -c doctor.c

patient.o: patient.c patient.h utility.h disease_info.h
	$(CC) $(CFLAGS) -c patient.c

utility.o: utility.c utility.h
	$(CC) $(CFLAGS) -c utility.c

disease_info.o: disease_info.c disease_info.h
	$(CC) $(CFLAGS) -c disease_info.c

clean:
	rm -f *.o hospital_management