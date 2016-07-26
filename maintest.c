#include <stdio.h>
#include <wchar.h>

int main()
{
	int i = 0;
	char *str = "owiehfqwef";
	wchar_t texte[50] = L"Salut G\x82rard !";



	printf("|%ls|\n", texte);
	printf("|%*.4x|\n", 20, 2442);
	printf("|%*.*x|\n", 20, 4, 2442);
	printf("|%**.*x|\n", 20, 4, 6, 2442);
	printf("|%0+.4-20x|\n", 2442);
	printf("|%20.4x|\n", 2442);
	printf("|%20.4x|\n", 2442);




	printf("|%#+8x|\n", 2442);
	printf("|%#-8x|\n", 2442);
	printf("|%#0x|\n", 2442);
	printf("|%#0-x|\n", 2442);
	printf("|%#0-8x|\n", 2442);
	printf("|%#0+8x|\n", 2442);


	printf("\nCARE:\n");
	printf("|%#+010s%s|\n", "hello", "hello");
	printf("|%#+010%s|\n", "hello", "hello");
	printf("|%#+010|\n", "hello", "hello");

	printf("\nCARE:\n");
	printf("|%*.*x|\n", 20, 4, 2442);
	printf("|%***.**x|\n", 2, 20, 4, 6, 7, 2442);

	//printf("|%#0-8x|\n", 2442);
	//printf("|%0-#8x|\n", 2442);
	//printf("|%-0#8x|\n", 2442);
	//printf("|%0#8x|\n", 2442);
	//printf("|%#0-8d|\n", 2442);
	//printf("|%#0-8d|\n", 2442);
	//printf("|%#0-8d|\n", 2442);
	//ft_printf("salut %s les %d ami", str, n);
}
