#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARTISTS 4
#define STR_SIZE 160
#include "sortAndShuffle.h"

void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2);
void mergeSort(char a[][STR_SIZE], int i, int j);


/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/
// sorts the Artist and song of the artist.
void sortArtistNSongs(char artists[][STR_SIZE], char songsArtist1[][STR_SIZE], char songsArtist2[][STR_SIZE], char songsArtist3[][STR_SIZE], char songsArtist4[][STR_SIZE], int numSongsPerArtist[MAX_ARTISTS], int numOfArtists)
{
	int artNum;
	// sorts the artist.
	mergeSort(artists, 0, numOfArtists-1);
	// sorts the song names by lexicographic ordering in ascending order.
	for (artNum = 0; artNum < numOfArtists; artNum++)
		if (artNum == 0)
			mergeSort(songsArtist1, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 1)
			mergeSort(songsArtist2, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 2)
			mergeSort(songsArtist3, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 3)
			mergeSort(songsArtist4, 0, numSongsPerArtist[artNum]-1);
}



/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numOfArtists: the number of artists provided from the standard input
*/
// merge sort function.
void mergeSort(char a[][STR_SIZE], int i, int j)
{
	int mid;
	
	if (i < j)
	{
		mid = (i+j)/2;
		mergeSort(a, i, mid);		// left recursion.
		mergeSort(a, mid+1, j);		// right recursion.
		merge(a, i, mid, mid+1, j);	// merging of two sorted sub-arrays.
	}
}
// merge sort function that merges two list together in ascending order via lexicographic ordering.
void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2)
{
	char temp[STR_SIZE][STR_SIZE] = {0};		// array used for merging.
	int i, j, k;
	i = i1;		// beginning of the first list.
	j = i2; 	// beginning of the second list.
	k = 0;
	
	while (i <= j1 && j <= j2)		// while elements exist in both list.
	{
		if (strcmp(a[i], a[j]) < 0)
			strcpy(temp[k++], a[i++]);
		else
			strcpy(temp[k++], a[j++]);
	}
	
	while (i <= j1)		// copy remaining elements of the first list.
		strcpy(temp[k++], a[i++]);
	
	while (j <= j2)		// copy remaining elements of the second list.
		strcpy(temp[k++], a[j++]);
		
	// Transfer elements from temp[] back to a[].
	for (i = i1, j = 0; i <= j2; i++, j++)
		strcpy(a[i], temp[j]);
}



/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
*/
// shuffle function via knuth fisher-yate's algorithm.
void shuffleArrayOfStrings(char a[][STR_SIZE], int N)
{
	int i, j, k;  // counters.
	int shuffle = 1;	// boolean value.
	int shuffle_num = 0;
	char temp[1][STR_SIZE] = {0};  // array used as temp in switching pos.
	srand(time(NULL));
	
	while (shuffle)
	{
		printf("Number of Shuffles: %d\n", shuffle_num);
		for (i = N-1; i > 0; i--)
		{
			j = rand() % i;
			
			strcpy(temp[0], a[j]);
			strcpy(a[j], a[i]);
			strcpy(a[i], temp[0]);
		}
		shuffle = 0;
		
		int conflict_num = 0;
		for (i = N-1; i > 0; i--)
		{
			//for (k = i-5; k < i; k++)
			for (k = i+5; k > i; k--)
				if (strcmp(a[i], a[k]) == 0)
				{
					printf("\nConflict: %d\n", ++conflict_num);
					printf("%d: %s\n", i, a[i]);
					puts("with");
					printf("%d: %s\n", k, a[k]);
					puts("");
					
					shuffle = 1;
					break;
				}
			if (shuffle)
				break;
		}
		shuffle_num++;
	}
	
	/*
	for (i = N-1; i > 0; )
	{
		printf("i: %d\n", i);
		j = rand() % i;
		
		printf("a[%d]: %s\t%s\n", j, a[j], "replacing with");
		// switch pos only if the element in the array does not occur in the previous 5 positions.
		for (k = i-5; k < i; k++)
		{
			printf("k: %d\ta[k]: %s\n", k, a[k]);
			if (strcmp(a[j], a[k]) == 0)
			{
				puts("");
				break;
			}
			else if (k == i-1)
			{
				++k;
				printf("k: %d\ta[k]: %s\t%s\n", k, a[k], "being replaced");
				allow_switch = 1;
			}
		}
		
		if (allow_switch)
		{
			strcpy(temp[0], a[j]);
			strcpy(a[j], a[i]);
			strcpy(a[i], temp[0]);
			
			printf("replaced\n\n");
			allow_switch = 0;
			i--;
		}
	}
	*/
}
