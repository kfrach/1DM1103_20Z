all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students


test-nowy_student: all
	./mydb baza.csv add_student Konrad Frach 307315 konrad@frach.pl	