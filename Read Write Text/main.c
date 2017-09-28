#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
main(void) {

	FILE *std;
	std = fopen("std.txt", "r");
	int id=0;
	int id2 = 0;
	int semester = 0;
	
	char buffer[255];

	/*while (fgets(buffer, sizeof(buffer), std) != NULL) {
		if (fscanf(std, "S %d %s", &id, buffer))
			printf("Student: %d %s\n", id, buffer);
		 if (fscanf(std, "T %d %s", &id, buffer))
			printf("Teacher: %d %s\n", id, buffer);
		else if (fscanf(std, "C %d %s %d", &id, buffer, &semester))
			printf("Course: %d %s %d\n", id, buffer, semester);
		else if (fscanf(std, "E %d %d", &id, &id2))
			printf("Enrollment: %d %d\n", id, id2);
		else if (fscanf(std, "A %d %d", &id, &id2))
			printf("Assignment: %d %d\n", id, id2);
	}*/


	while (!feof(std)) {

		if (fscanf(std, "S %d %s\n", &id, buffer) == 2)
			printf("Student: %d %s\n", id, buffer);
		else if (fscanf(std, "T %d %s\n", &id, buffer) == 2)
			printf("Teacher: %d %s\n", id, buffer);
		else if (fscanf(std, "C %d %s %d\n", &id, buffer, &semester) == 3)
			printf("Course: %d %s %d\n", id, buffer, semester);
		else if (fscanf(std, "E %d %d\n", &id, &id2) == 2)
			printf("Enrollment: %d %d\n", id, id2);
		else if (fscanf(std, "A %d %d\n", &id, &id2) == 2)
			printf("Assignment: %d %d\n", id, id2);
		else
			fgets(buffer, sizeof(buffer) ,std);

	}
	fclose(std);



	


}