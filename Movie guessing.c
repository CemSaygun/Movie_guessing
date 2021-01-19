#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#define MAX 100

const char* const movie_name[] = { "lord of the rings","the hobbit","matrix","king kong","dunkirk","spider man","dead poets society",
								  "the truman show","life is beautiful","the hunger games" };


int movie_name_func(char* dest, char** source) {

	srand((unsigned int)time(NULL));
	source = movie_name;
	int x = rand() % 10;
	strcpy(dest, *(source + x));

	return strlen(dest);

}



char putstar(char* dest, char* source, size_t n) {

	for (int i = 0; i < n; i++) {
		if (*source != ' ') {
			*dest++ = '*';
			source++;

		}
		else {
			*dest++ = ' ';
			source++;
		}

	}
	*dest = '\0';

	return 0;
}




int main() {

	char arr[MAX];
	char arr2[MAX];
	int n = movie_name_func(arr, movie_name);
	int guessed_ch;
	putstar(arr2, arr, n);
	printf("harf sayisi = %d\n", n);
	printf("%s\n\n", arr2);

	printf(
	"1)oyundan cikmak icin q'ya basiniz\n"
	"2)tahmin yapmak icin 'tahmin' yaziniz\n"
	"3)kucuk harf kullaniniz\n\n"
	);

	while (1) {
		printf("Harf tahmin ediniz: ");
		guessed_ch = getchar();
		if (guessed_ch == 'q') {
			break;
		}
		else {
			for (int i = 0; arr[i] != '\0'; i++) {

				if (guessed_ch == arr[i])
					arr2[i] = guessed_ch;

			}

			printf("%s\n", arr2);
		}


		int wanna_guess;
		char myguessing[MAX];
		printf("Tahminde bulunmak ister misiniz(y/n): ");
		getchar();
		wanna_guess = getchar();
		if (wanna_guess == 'y') {
			getchar();
			printf("Tahmininiz: ");
			gets(myguessing);
			if (!strcmp(myguessing, arr)) {
				printf("BRAVOO!!");
				break;
			}
			else {

				printf("DADANTT!!\n");

			}
		}
		else
		{
			getchar();

		}


	}

	return 0;
}

