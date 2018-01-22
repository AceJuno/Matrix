# komentarze zaczynaja sie od #

# tak mozemy deklarowac zmienne
LIBNAME=matrix
A=Projekt
# ogolna struktura zadan w makefile
#	NAZWA_CELU: NAZWA_POPRZEDNIKA_1 NAZWA_POPRZEDNIKA_2
#		KOMENDA

# komenda all uruchamiana jest przy wywolaniu samego make
all: clean $(LIBNAME).o $(A)

$(LIBNAME).o: $(LIBNAME).h $(LIBNAME).c
	gcc -c $(LIBNAME).c -o $(LIBNAME).o -lcurses

$(A): $(A).c $(LIBNAME).o
	gcc $(A).c $(LIBNAME).o -o $(A) -lcurses

clean:
# @ na poczatku linijki oznacza ze nie wyswietlamy komendy
	@rm -f $(A) $(LIBNAME).o
# echo pozwala na wyswietlanie napisow
	@echo "Posprzatane!"
