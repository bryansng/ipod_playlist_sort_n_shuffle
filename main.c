// https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/Arrays.html
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sortAndShuffle.h"

#define MAX_ARTISTS 4
#define MAX_SONGS 3
//#define MAX_ARTISTS 1
//#define MAX_SONGS 1
#define STR_SIZE 160

// NOTE: at least specify the size of second dimension.
void mergesort(char a[][STR_SIZE], int i, int j);
void merge(char a[][STR_SIZE], int i1, int j1, int i2, int j2);

int main(void)
{
	//The array containing artists names
	//char artists[MAX_ARTISTS][STR_SIZE] = {0};
	char artists[MAX_ARTISTS][STR_SIZE] = {"b\n", "c\n", "d\n", "a\n"};
	//char artists[MAX_ARTISTS][STR_SIZE] = {"a", "b", "c", "d"};
	//The array containing the sorted artists
	//char sortedArtists[MAX_ARTISTS][STR_SIZE] = {0};
	//Songs for Artist 1
	//char songsArtist1[MAX_SONGS][STR_SIZE] = {0};
	char songsArtist1[MAX_SONGS][STR_SIZE] = {"a3\n", "a1\n", "a2\n"};
	//char songsArtist1[MAX_SONGS][STR_SIZE] = {"a1", "a2", "a3"};
	//Songs for Artist 2
	//char songsArtist2[MAX_SONGS][STR_SIZE] = {0};
	char songsArtist2[MAX_SONGS][STR_SIZE] = {"b3\n", "b1\n", "b2\n"};
	//char songsArtist2[MAX_SONGS][STR_SIZE] = {"b1", "b2", "b3"};
	//Songs for Artist 3
	//char songsArtist3[MAX_SONGS][STR_SIZE] = {0};
	char songsArtist3[MAX_SONGS][STR_SIZE] = {"c3\n", "c1\n", "c2\n"};
	//char songsArtist3[MAX_SONGS][STR_SIZE] = {"c1", "c2", "c3"};
	//Songs for Artist 4
	char songsArtist4[MAX_SONGS][STR_SIZE] = {"d3\n", "d1\n", "d2\n"};
	//char songsArtist4[MAX_SONGS][STR_SIZE] = {"d1", "d2", "d3"};
	//The total number of artists (Note it can be less than 4)
	int numOfArtists = 4;
	//The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
	int numSongsPerArtist[MAX_ARTISTS] = {0};
	//The total number of songs
	int totalSongs = 0;
	numSongsPerArtist[0] = 3;
	numSongsPerArtist[1] = 3;
	numSongsPerArtist[2] = 3;
	numSongsPerArtist[3] = 3;
	totalSongs = 3 * 4;
	
	
	/*
	* Use here functions that you should implement to insert artists and songs from the standard input.
	* Note that you also need to track the number of artists and the number of songs for each artist.
	*/
	int artNum, songNum;
	/*for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		// takes in the artist names.
		printf("Insert an artist/group name:\n");
		fgets(artists[artNum], STR_SIZE, stdin);
		puts("");
		
		// takes in the artist songs.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
		{
			printf("Insert song %d for %s", songNum+1, artists[artNum]);
			if (artNum == 0)
				fgets(songsArtist1[songNum], STR_SIZE, stdin);
			else if (artNum == 1)
				fgets(songsArtist2[songNum], STR_SIZE, stdin);
			else if (artNum == 2)
				fgets(songsArtist3[songNum], STR_SIZE, stdin);
			else if (artNum == 3)
				fgets(songsArtist4[songNum], STR_SIZE, stdin);
			
			// keeps track number of songs per artist and total number of songs.
			numSongsPerArtist[artNum] += 1;
			totalSongs += 1;
		}
		// keeps track the number of artists.
		numOfArtists += 1;
		puts("");
	}*/
	int songLength;
	// removes newline, if present.
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		songLength = strlen(artists[artNum])-1;
		if (artists[artNum][songLength] == '\n')
			artists[artNum][songLength] = '\0';
		
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
		{
			if (artNum == 0)
			{
				songLength = strlen(songsArtist1[songNum])-1;
				if (songsArtist1[songNum][songLength] == '\n')
					songsArtist1[songNum][songLength] = '\0';
			}
			else if (artNum == 1)
			{
				songLength = strlen(songsArtist2[songNum])-1;
				if (songsArtist2[songNum][songLength] == '\n')
					songsArtist2[songNum][songLength] = '\0';
			}
			else if (artNum == 2)
			{
				songLength = strlen(songsArtist3[songNum])-1;
				if (songsArtist3[songNum][songLength] == '\n')
					songsArtist3[songNum][songLength] = '\0';
			}
			else if (artNum == 3)
			{
				songLength = strlen(songsArtist4[songNum])-1;
				if (songsArtist4[songNum][songLength] == '\n')
					songsArtist4[songNum][songLength] = '\0';
			}
		}
	}
	
	
	/*
	* Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
	* Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
	*/
	// sorts the artist.
	mergesort(artists, 0, numOfArtists-1);
	// sorts the song names by lexicographic ordering by ascending order.
	for (artNum = 0; artNum < numOfArtists; artNum++)
	{
		if (artNum == 0)
			mergesort(songsArtist1, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 1)
			mergesort(songsArtist2, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 2)
			mergesort(songsArtist3, 0, numSongsPerArtist[artNum]-1);
		else if (artNum == 3)
			mergesort(songsArtist4, 0, numSongsPerArtist[artNum]-1);
	}
	
	printf("Sorted list of songs:\n");
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
	{
		// prints the artist name.
		printf("%s\n", artists[artNum]);
		
		// prints the songs of the artist.
		for (songNum = 0; songNum < MAX_SONGS; songNum++)
		{
			if (artNum == 0)
				printf("    -  %s\n", songsArtist1[songNum]);
			else if (artNum == 1)
				printf("    -  %s\n", songsArtist2[songNum]);
			else if (artNum == 2)
				printf("    -  %s\n", songsArtist3[songNum]);
			else if (artNum == 3)
				printf("    -  %s\n", songsArtist4[songNum]);
		}
	}
	
	
	/*
	* Use here the function shuffleSongs to shuffle all the songs
	* Print the list of shuffled songs
	*/
	int totalSongNum = 0;
	char songs[MAX_ARTISTS*MAX_SONGS][STR_SIZE] = {0}; // holds the artist + song that is added to the playlist.
	
	// creates a playlist by adding all the songs with their artist together.
	for (artNum = 0; artNum < MAX_ARTISTS; artNum++)
		for (songNum = 0; songNum < MAX_SONGS; songNum++, totalSongNum++)
		{
			strcat(songs[totalSongNum], artists[artNum]);
			strcat(songs[totalSongNum], " - ");
			if (artNum == 0)
				strcat(songs[totalSongNum], songsArtist1[songNum]);
			else if (artNum == 1)
				strcat(songs[totalSongNum], songsArtist2[songNum]);
			else if (artNum == 2)
				strcat(songs[totalSongNum], songsArtist3[songNum]);
			else if (artNum == 3)
				strcat(songs[totalSongNum], songsArtist4[songNum]);
		}
	puts("");
	puts("");
	
	// for debug, prints the songs in the playlist.
	//for (totalSongNum = 0; totalSongNum < totalSongs; totalSongNum++)
		//printf("totalSongNum, %d:\n%s\n\n", totalSongNum, songs[totalSongNum]);
	
	int i, j;
	char temp[STR_SIZE][STR_SIZE] = {0};
	srand(time(NULL));
	// shuffle playlist via knuth fisher-yates's algorithm.
	printf("Shuffled Playlist:\n");
	for (i = totalSongs-1; i > 0; i--)
	{
		j = rand() % i;
		
		strcpy(temp[0], songs[j]);
		strcpy(songs[j], songs[i]);
		strcpy(songs[i], temp[0]);
	}
	
	for (totalSongNum = 0; totalSongNum < totalSongs; totalSongNum++)
		printf("%d: %s\n", totalSongNum, songs[totalSongNum]);
	
	return 0;
}

// merge sort function.
void mergesort(char a[][STR_SIZE], int i, int j)
{
	int mid;
	
	if (i < j)
	{
		mid = (i+j)/2;
		mergesort(a, i, mid);		// left recursion.
		mergesort(a, mid+1, j);		// right recursion.
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



