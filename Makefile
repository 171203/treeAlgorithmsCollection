
# Make file Tree Algorithms Collection


Tree:	Tree_Main.o Tree_Algorithms.o
	gcc -o Tree Tree_Main.o Tree_Algorithms.o -g	
Tree_Main.o:	Tree_Main.c Tree.h
	gcc -c Tree_Main.c -g
Tree_Algorithms.o:    Tree_Algorithms.c Tree.h
	gcc -c  Tree_Algorithms.c -g
clean:
	     rm -f  *.s  *.o *Tree
