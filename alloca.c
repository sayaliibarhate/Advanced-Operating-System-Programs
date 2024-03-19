#include <stdio.h>
#include <string.h>
#include <alloca.h>

struct student
{
	int stud_id;
	int name_len;
	int struct_size;
	char stud_name[];;
};

struct student *createStudent(int id, const char *name)
{
	int name_len = strlen(name);
	struct student *s = alloca (sizeof(struct student) * name_len + 1);
	s -> stud_id = id;
	s -> name_len = name_len;
	strcpy(s->stud_name,name);
	s -> struct_size = sizeof(struct student) + name_len + 1;
	return s;
}

void printStudent(struct student *s)
{
	printf("Student_id : %d\n Stud_Name : %s\n Name_length : %d\n Allocated_struct_size : %d\n\n",s->stud_id,s->stud_name,s->name_len,s->struct_size);
}

int main()
{
	struct student *s1 = createStudent (531,"ABC");
	printStudent(s1);

	struct student *s2 = createStudent (567,"DEF");
        printStudent(s2);

	printf("Size of struct Student : %lu\n",sizeof(struct student));
}

