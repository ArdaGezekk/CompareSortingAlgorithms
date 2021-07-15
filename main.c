#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
void makeRandom(int[], int, int, int);
void showArray(int[], int);
void iter(int[], int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);
int partitionMedian (int[], int, int);
int partitionLast (int[], int, int);
void swap(int *xp, int *yp);

	int i, j;
int main(int argc, char ** argv) {
		int n;
  	while (1==1) {
    printf(" Please write c codes of bubble sort, quick sort, insertion sort, selection sort by supplying random numbers (100,1000, 10000).\n Check their complexity and running times.Draw their separete graphs and decide which O notation they belong.  \n");
    options:
    printf("Enter 0 for EXIT :\n");
    printf("Enter 1 for Bubble Sort :\n");
    printf("Enter 2 for Selection Sort :\n");
    printf("Enter 3 for Insertion Sort :\n");
    printf("Enter 4 for Quick Sort :\n");
    printf("Enter 5 for Compare The Algorithms, Bubble sort, quick sort, insertion sort and selection sort  \n");
    scanf("%d",&n);
    switch(n)
    {
    case 0:
				printf("Quitting the program...\n\n");
				exit(5);
        break;
    case 1:
  {
    srand(time(0));
        clock_t start, stop;
        float timeTaken;
    		int numOfInputs, minValue = 0, maxValue = 100;
    		printf("Test icin giris boyutunu girin:\n ");
	      scanf("%d", &numOfInputs);
	      //Creating the arrays for testing
	      int randNum[numOfInputs];
	      int bubbleArray[numOfInputs];
	      //Assigning random values
	      makeRandom(randNum, numOfInputs, minValue, maxValue);
	      printf("##################################################################################################################\n");
	      printf(" Random Numbers [%d]: ",numOfInputs);
	      showArray(randNum, 30);
	      printf("....\n");
	      //Copying the random values into Testing arrays
	      iter(randNum, bubbleArray, numOfInputs);
	      start = clock();
	      bubbleSort(bubbleArray, numOfInputs);
				stop = clock();
				timeTaken = (double)(stop-start)/CLOCKS_PER_SEC;
	      printf(" Bubble Sort    : ");
	      showArray(bubbleArray, 30);
	      printf("....\n");
	      printf(" The process took %f sec. \n",timeTaken);
        printf("##################################################################################################################\n\n");
      	printf("If you want to view all values, please press 1 if NOT  press any key.\n"); int x; scanf("%d",&x); if(x==1){
        printf("##################################################################################################################\n");
        printf("\nRandom Numbers [%d]: ",numOfInputs);
        showArray(randNum, numOfInputs); printf("\n\nBubble Sort :");
        showArray(bubbleArray, numOfInputs);
        printf("\n##################################################################################################################\n");
      }
  }
      printf("\n\nPress any key to Main Menu: ");
      while(getchar() == '\n');
      goto options;
        break;
    case 2:
    {
      srand(time(0));
	        clock_t start, stop;
	        float timeTaken;
	      	int numOfInputs, minValue = 0, maxValue = 100;
	      	printf("Test icin giris boyutunu girin: ");
	        scanf("%d", &numOfInputs);
	        int randNum[numOfInputs];
	        int selectionArray[numOfInputs];
	        makeRandom(randNum, numOfInputs, minValue, maxValue);
	        printf("##################################################################################################################\n");
	        printf(">>  Data to Sort [%d]: ",numOfInputs);
	        showArray(randNum, 30);
	        printf("...\n");
	        iter(randNum, selectionArray, numOfInputs);
	        start = clock();
	        selectionSort(selectionArray, numOfInputs);
	        stop = clock();
	        timeTaken = (double)(stop-start)/CLOCKS_PER_SEC;
	        printf(">> Selection Sort :  ");
	        showArray(selectionArray, 30);
	        printf(".......\n");
	        printf(" The process took %f sec. \n",timeTaken);
	        printf("##################################################################################################################\n\n");
	        printf("If you want to view all values, please press 1 if NOT  press any key.\n"); int x; scanf("%d",&x); if(x==1){
          printf("##################################################################################################################\n");
          printf("\nRandom Numbers [%d]: ",numOfInputs);
          showArray(randNum, numOfInputs); printf("\n\nBubble Sort :");
          showArray(selectionArray, numOfInputs);
          printf("\n##################################################################################################################\n");
        }
    }
    printf("\n\nPress any key to Main Menu: ");
    while(getchar() == '\n');
    goto options;
        break;
    case 3:
    {
      srand(time(0));
	          clock_t start, stop;
	          float timeTaken;
	        	int numOfInputs, minValue = 0, maxValue = 100;
	        	printf("Test icin giris boyutunu girin: ");
	          scanf("%d", &numOfInputs);
	          int randNum[numOfInputs];
	          int insertionArray[numOfInputs];
	          makeRandom(randNum, numOfInputs, minValue, maxValue);
	          printf("##################################################################################################################\n");
	          printf(">>  Data to Sort [%d]: ",numOfInputs);
	          showArray(randNum, 30);
	          printf("...\n");
	          iter(randNum, insertionArray, numOfInputs);
	          start = clock();
	          insertionSort(insertionArray, numOfInputs);
	          stop = clock();
	          timeTaken = (double)(stop-start)/CLOCKS_PER_SEC;
	          printf(">> Insertion Sort :  ");
	          showArray(insertionArray, 30);
	          printf(".......\n");
	          printf(" The process took %f sec. \n",timeTaken);
	          printf("##################################################################################################################\n\n");
	          printf("If you want to view all values, please press 1 if NOT  press any key.\n"); int x; scanf("%d",&x); if(x==1){
            printf("##################################################################################################################\n");
            printf("\nRandom Numbers [%d]: ",numOfInputs);
            showArray(randNum, numOfInputs); printf("\n\nBubble Sort :");
            showArray(insertionArray, numOfInputs);
            printf("\n##################################################################################################################\n");
          }
      }
      printf("\n\nPress any key to Main Menu: ");
      while(getchar() == '\n');
      goto options;
        break;
    case 4:
    {
      srand(time(0));
          clock_t start, stop;
          float timeTaken;
        int numOfInputs, minValue = 0, maxValue = 100;
        printf("Test icin giris boyutunu girin: ");
          scanf("%d", &numOfInputs);
          int randNum[numOfInputs];
          int quickArray[numOfInputs];
          makeRandom(randNum, numOfInputs, minValue, maxValue);
          printf("##################################################################################################################\n");
          printf(">>  Data to Sort [%d]: ",numOfInputs);
          showArray(randNum, 30);
          printf("...\n");
          iter(randNum, quickArray, numOfInputs);
          start = clock();
          quickSort(quickArray, 0, numOfInputs-1);
          stop = clock();
          timeTaken = (double)(stop-start)/CLOCKS_PER_SEC;
          printf(">> Quick Sort :      ");
          showArray(quickArray, 30);
          printf(".......\n");
          printf(" The process took %f sec. \n",timeTaken);
          printf("##################################################################################################################\n\n");
          printf("If you want to view all values, please press 1 if NOT  press any key.\n"); int x; scanf("%d",&x); if(x==1){
          printf("##################################################################################################################\n");
          printf("\nRandom Numbers [%d]: ",numOfInputs);
          showArray(randNum, numOfInputs); printf("\n\nBubble Sort :");
          showArray(quickArray, numOfInputs);
          printf("\n##################################################################################################################\n");
          }
      }
      printf("\n\nPress any key to Main Menu: ");
      while(getchar() == '\n');
      goto options;
        break;
    case 5:
    {
      srand(time(0));
      clock_t start, stop;
      int i,  minValue = 0, maxValue = 100, numOfTests=4;
      int bubbleTime = 0, selectionTime = 0, insertionTime = 0, quickTime = 0,  bubbleTemp = 0, selectionTemp = 0,  insertionTemp = 0, quickTemp = 0;
      int startingSize=10, increment=10;
      printf("\n\n\tNo.\tSize\tBubble Sort (ms) \tInserion Sort (ms) \tQuickSort (ms) \tSelection Sort (ms) \t  Data ");
        for(i = 1; i <= numOfTests; i++)
        {
        int randNew[startingSize];
        int bubbleCompare[startingSize];
        int selectionCompare[startingSize];
        int insertionCompare[startingSize];
        int quickCompare[startingSize];
          makeRandom(randNew, startingSize, minValue, maxValue);
          iter(randNew, bubbleCompare, startingSize);
          iter(randNew, selectionCompare, startingSize);
          iter(randNew, insertionCompare, startingSize);
          iter(randNew, quickCompare, startingSize);
            start = clock();
            bubbleSort(bubbleCompare, startingSize);
            stop = clock();
            bubbleTemp += 1000* (stop - start)/CLOCKS_PER_SEC;
            start = clock();
            selectionSort(selectionCompare, startingSize);
            stop = clock();
            selectionTemp += 1000* (stop - start)/CLOCKS_PER_SEC;
            start = clock();
            insertionSort(insertionCompare, startingSize);
            stop = clock();
            insertionTemp += 1000* (stop - start)/CLOCKS_PER_SEC;
            start = clock();
            quickSort(quickCompare, 0, startingSize-1);
            stop = clock();
            quickTemp += 1000* (stop - start)/CLOCKS_PER_SEC;
          bubbleTime = bubbleTemp;
          insertionTime = insertionTemp;
          quickTime = quickTemp;
          selectionTime = selectionTemp;
          printf("\t%d)\t%d\t%d\t\t\t%d\t\t\t%d\t\t%d\t\t\t #[ ", i, startingSize, bubbleTime, insertionTime, quickTime, selectionTime);
          showArray(bubbleCompare, 10);printf("....." );
          startingSize *= increment;
      }
    }
    printf("\n\nPress any key to Main Menu: ");
    while(getchar() == '\n');
    goto options;
        break;
    default:
        break;
    }
  }
	return (0);
}
void makeRandom(int randNum[], int numOfInputs, int minValue, int maxValue){
int j;
    for(j = 0; j < numOfInputs; ++j){
		randNum[j] = (rand() % maxValue + 1 - minValue) + minValue;
	}
	printf("\n");
}
void showArray(int randNum[], int numOfInputs){
	int i;
	for(i = 0; i < numOfInputs; i++){
		printf("%d ", randNum[i]);
	}
}
//Copying array
void iter(int randNum[], int resultArray[], int numOfInputs){
	int i;
	for(i = 0; i < numOfInputs; i++){
		resultArray[i] = randNum[i];
	}
}
//Swapping algorithm
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//Bubble Sorting Algorithm
void bubbleSort(int bubbleArray[], int numOfInputs){
	int comp = 0, swp = 0;
	bool swapped;
	int i;
	for (i = 0; i < numOfInputs-1; i++) {
		swapped = false;
		for (j = 0; j < numOfInputs-i-1; j++) {
			if (bubbleArray[j] > bubbleArray[j+1]) {
				swap(&bubbleArray[j], &bubbleArray[j+1]);
				//swap numbers if Value >  Next Value
				swapped = true;
				swp++;
			}
			comp++;
		}
		if (swapped == false) break; //Table sorted Algorithms done.
	}
}
//Selection Sort Algorithm
void selectionSort(int selectionArray[], int numOfInputs)
{
	int index = 1;
	if(index == numOfInputs)
		return;
	else
	{
		int highest = 0;
		int highIndex = 0;
		for(int i=0; i< numOfInputs; i++)
		{
			if(selectionArray[i] > highest)
			{
				highest = selectionArray[i];
				highIndex = i;
			}
		}
		int temp = selectionArray[numOfInputs-1];
		selectionArray[numOfInputs-1] = highest;
		selectionArray[highIndex] = temp;
		selectionSort(selectionArray, numOfInputs-1);
	}
}
//Insertion Sort Algorithm
void insertionSort(int insertionArray[], int numOfInputs){
	int comp = 0, assg = 0, h;
	//loop where the key is generated and the values are swapped likewise...
	for (h = 1; h < numOfInputs; h++) {
		int key = insertionArray[h];
		int k = h - 1;
		while (k >= 0 && key < insertionArray[k]) {
			insertionArray[k + 1] = insertionArray[k];
			comp++;
			assg++;
			--k;
		}
		insertionArray[k + 1] = key;
	}
}
//Quick Sort Algorithm
void quickSort(int quickArray[], int low, int numOfInputs){
	if (low < numOfInputs) {
		//returns the pivot -> some random middle value
		int pi = partitionMedian(quickArray, low, numOfInputs);
		quickSort(quickArray, low, pi - 1);
		quickSort(quickArray, pi + 1, numOfInputs);
	}
}
int partitionMedian (int arr[], int low, int high) {
	swap(&arr[(low + high)/2], &arr[high]);
	return partitionLast(arr, low, high);
}
int partitionLast (int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low, j;
	for (j = low; j <= high- 1; j++)  {
		if (arr[j] <= pivot) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}
