project:project.o
	cc project.c -o project
main.o:project.c
	cc -c project.c
