/*******************
 *Name: Nimrod Netzer
 *ID: 322394545
 *Assigment: ex_10
 *******************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_OPTION_NAME_LENGTH 50
#define MAX_STRING_LENGTH 100
#define TRUE 1
#define ZERO 0
#define MAX_ARRAY_LENGTH 20

// Function to convert a number from a given base to decimal
int convertBaseToDec(int base, int number) {
    int index = 0;
    int reminder;
    int sum = 0;
    // Loop until the number becomes 0
    while (number != 0) {
        reminder = number % 10;
        if (reminder >= base) {
            return -1;
        }
        int multiply = pow(base, index);

        // Add the result to the sum
        sum += reminder * multiply;
        number = number / 10;
        index++;
    }
    return sum;
}

// Function one: get a number and its base from the user and print its decimal equivalent
void baseToDec(void) {
    printf("Enter a base and a number in said base: ");
    int base, number;
    scanf("%d %d", &base, &number);

    // Check if the base is valid
    if (base < 2 || base > 9) {
        printf("Invalid input\n");
        return;
    }
    // Convert the number to decimal
    int sum = convertBaseToDec(base, number);
    if (sum == -1) {
        return;
    }
    printf("%d\n", sum);
}

// Convert a decimal number to a given base
int convertDecToBase(int decimalNumber, int base) {
    int mulitply = 1, reminder, sum = 0;
    while (decimalNumber != 0) {

        // Get the reminder of the division
        reminder = decimalNumber % base;
        decimalNumber = decimalNumber / base;

        sum += reminder * mulitply;
        mulitply = mulitply * 10;
    }
    return sum;
}

// Function two: Get a decimal number and its base from the user and print its equivalent in the given base
void decToBase(void) {
    printf("Enter a counting base and a decimal number: ");
    int base, decimalNumber;
    scanf("%d %d", &base, &decimalNumber);

    if (base < 2 || base > 9) {
        printf("Invalid input\n");
        return;
    }
    // Convert the decimal number to the given base
    int sum = convertDecToBase(decimalNumber, base);

    printf("Result: %d\n", sum);
}


// Function three: add two binary numbers
void plus(void) {
    printf("Enter 2 binary numbers:\n");
    int binaryOne, binaryTwo;
    scanf("%d %d", &binaryOne, &binaryTwo);

    int convertedBinaryOne = convertBaseToDec(2, binaryOne);
    int convertedBinaryTwo = convertBaseToDec(2, binaryTwo);

    int decimalSum = convertedBinaryOne + convertedBinaryTwo;

    // Convert the sum to binary
    int binarySum = convertDecToBase(decimalSum, 2);

    //Finds the binary numbers size
    int binarySumSize = 0;
    for (int i = binarySum; i > 0; i /= 10) {
        binarySumSize++;
    }

    int binaryOneSize = 0;
    for (int i = binaryOne; i > 0; i /= 10) {
        //Checks if the input is valid
        if (binaryOne % 10 != 0 && binaryOne % 10 != 1) {
            printf("Invalid input\n");
            return;
        }
        binaryOneSize++;
    }

    int binaryTwoSize = 0;
    for (int i = binaryTwo; i > 0; i /= 10) {
        if (binaryTwo % 10 != 0 && binaryTwo % 10 != 1) {
            printf("Invalid input\n");
            return;
        }
        binaryTwoSize++;
    }
    //Prints the binary numbers in addition to zeroes when necessary
    for (int i = 0; i < binarySumSize - binaryOneSize; i++) {
        printf("%d", 0);
    }
    if (binaryOne != 0) {
        printf("%d", binaryOne);
    }
    printf("\n+\n");

    for (int i = 0; i < binarySumSize - binaryTwoSize; i++) {
        printf("%d", 0);
    }
    if (binaryTwo != 0) {
        printf("%d", binaryTwo);
    }
    printf("\n");

    for (int i = 0; i < binarySumSize; i++) {
        printf("-");
    }
    printf("\n%d\n", binarySum);
}

// Function four: perform prime factorization of a number
void primeFactorization(void) {
    printf("Enter a number: ");
    int number;
    scanf("%d", &number);
    if (number <= 0) return;

    int count;
    // Loop through possible factors starting from 2
    for (count = 2; number > 1; count++) {
        // If it is a factor, print the count (prime factor)
        while (number % count == 0) {
            printf("%d ", count);
            number = number / count;
        }
    }
    printf("\n");
}

// Function five: printing a diamond pattern
void printDiamond(void) {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return;
    }

    for (int i = 1 - n; i < n; i++) {
        for (int j = 1 - n; j < n; j++) {
            // Calculate distance from center
            int distance = (i < 0 ? -i : i) + (j < 0 ? -j : j);
            if (j == 1 - n) {
                printf(" ");
            }
            // Print asterisk or space based on distance
            if (distance < n) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}


///Part 2: Recursion

// Function one: print a string recursively in reversed order
void printString(int size, char *arr, int currentIndex) {

    if (currentIndex >= size) {
        return;
    }
    printf("%c", arr[currentIndex]);
    printString(size, arr, currentIndex + 1);
}


// Receives a string from the user recursively
void recieveStringRecursively(int size, char *arr, int currentIndex) {

    if (currentIndex < ZERO) {
        printString(size, arr, ZERO);
        return;
    }
    scanf("%c", &arr[currentIndex]);
    recieveStringRecursively(size, arr, currentIndex - 1);
}

// Reverse the string entered by the user
void reverseString(void) {
    printf("Enter a size: ");
    int size;
    scanf("%d", &size);

    //Check the input validity
    if (size <= 0) {
        printf("Invalid input\n");
        return;
    }
    printf("Enter a string: ");
    char stringArray[MAX_STRING_LENGTH];

    recieveStringRecursively(size, stringArray, size);
    printf("\n");
}

// Function 2: calculate and print all N-digit numbers with absolute difference K between adjacent digits
void calc(int N, int K, int firstDigit, int currentNum) {
    // Base case: when N becomes 1, print the current number and return
    if (N == 1) {
        printf("%d", currentNum);
        printf("\n");
        return;
    }

    // If adding or subtracting K to the firstDigit results is a valid digit, proceed with the next recursion
    if (firstDigit + K < 10) {
        calc(N - 1, K, firstDigit + K, currentNum * 10 + firstDigit + K);
    }
    if (firstDigit - K >= 0) {
        calc(N - 1, K, firstDigit - K, currentNum * 10 + firstDigit - K);
    }
}

// Function to check all possible starting digits for N-digit numbers with absolute difference K
void checkDigit(int N, int K, int firstDigit) {
    if (firstDigit > 9) {
        return;
    }
    calc(N, K, firstDigit, firstDigit);
    checkDigit(N, K, firstDigit + 1);
}


// Getting the input from the user
void absDiffNums(void) {
    printf("Enter N and K:\n");
    int N, K;
    scanf("%d %d", &N, &K);
    if (K < 0) {
        printf("Invalid input\n");
        return;
    }
    checkDigit(N, K, 1);
}

// Function 3: find array's subset sum
void getArrayElements(int arr[], int initIndex, int arraySize) {
    if (initIndex >= arraySize) {
        return;
    }
    scanf("%d", &arr[initIndex]);
    getArrayElements(arr, initIndex + 1, arraySize);
}

// Function to print the elements of an array
void printArray(int arr[], int size, int curPosition) {
    if (curPosition >= size) {
        // If the current position is beyond the size of the array, print a newline and return
        printf("\n");
        return;
    }
    if (arr[curPosition] != 0) {
        printf("%d ", arr[curPosition]);
    }
    printArray(arr, size, curPosition + 1);
}

// Calculates the sum of elements in an array recursively
int arraySum(int *arr, int position, int size) {
    if (position >= size) {
        return 0;
    }
    return arraySum(arr, (position + 1), size) + arr[position];
}

// Function to find if a subset with the given target sum exists recursively
void isSubArrayExists(int *array, int size, int target, int *sub_array, int *flag, int curPosition) {
    if (*flag != 0 || curPosition >= size) return;

    // Try including the current item in the subset
    sub_array[curPosition] = array[curPosition];
    // Check if the current subset sum matches the target sum
    if (arraySum(sub_array, ZERO, curPosition + 1) == target) {
        printArray(sub_array, curPosition + 1, ZERO);
        *flag = TRUE;
        return;
    }

    // Iteration with the next index, include elements from lower index first
    isSubArrayExists(array, size, target, sub_array, flag, curPosition + 1);

    // If the subset sum is still not reached, exclude the current item from the subset
    if (*flag == 0) {
        sub_array[curPosition] = 0;
        isSubArrayExists(array, size, target, sub_array, flag, curPosition + 1);
    }
}

void subsetSum() {
    int size, targetSum;
    int arr[MAX_ARRAY_LENGTH];
    int subArr[MAX_ARRAY_LENGTH];

    printf("Enter the size of the array (max 20): ");
    scanf("%d", &size);
    if (size > MAX_ARRAY_LENGTH || size <= ZERO) {
        printf("Invalid input\n");
        return;
    }
    printf("Enter the elements of the array: ");

    // Function to input array elements
    getArrayElements(arr, ZERO, size);
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    int flag = ZERO;

    isSubArrayExists(arr, size, targetSum, subArr, &flag, ZERO);

    // If no subset with targetSum sum is found
    if (flag == ZERO)
        printf("No such subset\n");
}


// Function four: find the longest increasing sub array:
// Copying elements from source array to destination array
void arrayCopy(int dest[], int source[], int length, int curIndex) {
    if (curIndex >= length) return;
    // Copy element from source array to destination array
    dest[curIndex] = source[curIndex];
    arrayCopy(dest, source, length, curIndex + 1);
}

int maxSubArray(int size, int currentIndex, int array[], int foundSubarray[], int foundSubarrayLength,
                int candidateSubarray[], int candidateSubarrayLength) {
    if (currentIndex >= size) {
        // Base case: If current index is greater than or equal to size, return found subarray length
        return foundSubarrayLength;
    }

    if (array[currentIndex] < array[currentIndex - 1]) {
        candidateSubarrayLength = 1;
        candidateSubarray[0] = array[currentIndex];
    } else {
        candidateSubarray[candidateSubarrayLength] = array[currentIndex];
        candidateSubarrayLength++;

        // If length of candidate subarray exceeds length of found subarray, update found subarray
        if (candidateSubarrayLength > foundSubarrayLength) {
            foundSubarrayLength = candidateSubarrayLength;
            arrayCopy(foundSubarray, candidateSubarray, candidateSubarrayLength, ZERO);
        }
    }

    // Recursive call to process next element
    return maxSubArray(size, currentIndex + 1, array, foundSubarray,
                       foundSubarrayLength, candidateSubarray, candidateSubarrayLength);
}

void longestIncreasingSubarray(void) {
    printf("Enter the size of the array: ");
    int arraySize;
    scanf("%d", &arraySize);

    // Checking validity
    if (arraySize < 1 || arraySize > MAX_ARRAY_LENGTH) return;

    printf("Enter %d elements of the array: ", arraySize);
    int array[MAX_ARRAY_LENGTH];

    getArrayElements(array, ZERO, arraySize);

    int foundSubarray[MAX_ARRAY_LENGTH] = {};
    int candidateSubarray[MAX_ARRAY_LENGTH] = {};
    foundSubarray[0] = array[0];
    candidateSubarray[0] = array[0];
    int foundSubarrayLength = 1;
    int candidateSubarrayLength = 1;

    // Find the longest increasing subarray
    foundSubarrayLength = maxSubArray(arraySize, 1, array, foundSubarray,
                                      foundSubarrayLength, candidateSubarray, candidateSubarrayLength);
    printArray(foundSubarray, foundSubarrayLength, ZERO);
}

///Part 3: data structures

typedef struct Episode {
    char *name;
    int season;
    int episode;
    struct Episode *next;
} Episode;

typedef struct Series {
    char *name;
    int numEpisode;
    Episode *episodes;
} Series;

typedef struct SeriesList {
    Series *series;
    struct SeriesList *next;
} SeriesList;


typedef struct User {
    char *name;
    int numLists;
    SeriesList **seriesLists;
    struct User *next;
} User;


typedef struct UserDB {
    User *users;
    int numUsers;
} UserDB;

// Function to read a string from the user's input
char *getString() {
    char *output = NULL;
    int size = 0;
    char x = 0;

    //Clear the buffer
    do {
        x = getchar();
    } while (x == '\n');

    //Allocate space for the '\0'
    output = (char *) malloc(1 * sizeof(char));
    while (x != '\n') {
        if (output == NULL) {
            return NULL;
        }
        output[size] = x;
        size++;
        x = getchar();
        output = (char *) realloc(output, sizeof(char) * (size + 1));
    }
    output[size] = '\0';
    return output;
}


// Function to initialize a user database
// Another option: could also allocate memory for the userDb by malloc
void initUserDb(UserDB *userDB) {
    userDB->users = NULL;
    userDB->numUsers = 0;
}

// Function to add user to the database
void addUser(UserDB *userDb) {
    printf("Enter a name: ");
    char *name = getString();

    User *userPointer = userDb->users;
    User *lastUserPointer = userPointer;

    // Check if the user already exists
    while (userPointer != NULL) {
        if (strcmp(name, userPointer->name) == 0) {
            printf("User already exists\n");
            free(name);
            return;
        }
        userPointer = userPointer->next;
    }

    // Create a new user
    User *currentUser = (User *) malloc(sizeof(User));
    if (currentUser == NULL) return;
    currentUser->name = (char *) malloc((strlen(name) + 1) * sizeof(char));
    if (currentUser->name == NULL) return;
    strcpy(currentUser->name, name);
    free(name);
    name = NULL;
    currentUser->numLists = 0;
    currentUser->seriesLists = NULL;
    currentUser->next = NULL;

    // Finds where to insert the new user
    if (userDb->users == NULL) {
        userDb->users = currentUser;
        userDb->numUsers++;
        return;
    }
    while (lastUserPointer != NULL) {
        if (lastUserPointer->next == NULL) {
            lastUserPointer->next = currentUser;
            userDb->numUsers++;
            return;
        }
        lastUserPointer = lastUserPointer->next;
    }
}

// Function to check if a user exists in the database
int isUserExist(char *name, UserDB *userDb) {
    if (userDb->users == NULL) return -1;
    User *userPointer = userDb->users;
    for (int i = 0; i < userDb->numUsers; i++) {
        if (strcmp(name, userPointer->name) == 0)
            return 1;
        userPointer = userPointer->next;
    }
    return -1;
}

// Function to check if a series exists for a user in the database, and returning the user
User *isSeriesExist(char *userName, char *seriesName, UserDB *userDb) {
    User *userPointer = userDb->users;
    while (userPointer != NULL) {
        if (strcmp(userName, userPointer->name) == 0) {
            // User found, check if series exists
            User *tempUser = userPointer;
            for (int i = 0; i < userPointer->numLists; i++) {
                SeriesList *seriesListPointer = tempUser->seriesLists[i];
                while (seriesListPointer != NULL && seriesListPointer->series != NULL) {
                    if (strcmp(tempUser->seriesLists[i]->series->name, seriesName) == 0) {
                        // Series already exists
                        return NULL;
                    }
                    seriesListPointer = seriesListPointer->next;
                }
            }
            // Return user if series doesn't exist
            return userPointer;
        }
        userPointer = userPointer->next;
    }
    //return NULL if user does not exist
    return NULL;
}


// Function to create a new series
Series *createSeries(char *seriesName, int index, User *curUser) {
    if (curUser == NULL || seriesName == NULL || index < 0)
        return NULL;
    //creating the series
    Series *newSeries = NULL;
    newSeries = (Series *) malloc(sizeof(Series));
    if (newSeries == NULL) return NULL;
    newSeries->name = (char *) malloc((strlen(seriesName) + 1) * sizeof(char));
    if (newSeries->name == NULL) return NULL;
    strcpy(newSeries->name, seriesName);
    free(seriesName);
    seriesName = NULL;
    newSeries->episodes = NULL;
    newSeries->numEpisode = 0;
    return newSeries;
}

// Function to add a series to a user's series list
void addSeries(UserDB *userDb) {
    printf("Enter user name: ");
    char *name = getString();
    int checkUser = isUserExist(name, userDb);

    if (checkUser == -1) {
        printf("User not found\n");
        free(name);
        name = NULL;
        return;
    }

    // Check if series already exists for the user
    printf("Enter series name: ");
    char *seriesName = getString();

    User *curUser = isSeriesExist(name, seriesName, userDb);
    if (curUser == NULL) {
        printf("Series already exists\n");
        free(seriesName);
        seriesName = NULL;
        free(name);
        name = NULL;
        return;
    }

    // We do not need to check the username anymore, so we can free it
    free(name);
    name = NULL;

    Series *newSeries = NULL;
    // Add new series to user's series list, when there are no series lists yet
    if (curUser->seriesLists == NULL) {
        newSeries = createSeries(seriesName, ZERO, curUser);
        if (newSeries == NULL) return;
        curUser->seriesLists = (SeriesList **) calloc(1, sizeof(SeriesList *));
        if (curUser->seriesLists == NULL) return;
        curUser->seriesLists[0] = (SeriesList *) malloc(sizeof(SeriesList));
        if (curUser->seriesLists[0] == NULL) return;
        curUser->seriesLists[0]->series = newSeries;
        curUser->seriesLists[0]->next = NULL;
        curUser->numLists++;
        return;
    }

    // Handle case when user has existing series lists
    printf("Create a new list or add to an existing one? (n/e): ");
    char newListResult;
    scanf("%c", &newListResult);
    while (getchar() != '\n');

    //Creating new series list
    if (newListResult == 'n') {
        newSeries = createSeries(seriesName, curUser->numLists, curUser);

        if (newSeries == NULL) return;
        // Allocate memory in the array for the new series list
        curUser->seriesLists = realloc(curUser->seriesLists,
                                       (curUser->numLists + 1) * sizeof(SeriesList *));
        if (curUser->seriesLists == NULL) return;

        // Insert the new series in the new list
        curUser->seriesLists[curUser->numLists] = (SeriesList *) malloc(sizeof(SeriesList));
        if (curUser->seriesLists[curUser->numLists] == NULL) return;
        curUser->seriesLists[curUser->numLists]->series = newSeries;
        curUser->seriesLists[curUser->numLists]->next = NULL;
        curUser->numLists++;

    } else if (newListResult == 'e') {
        int indexResult = 0;
        int maxArraySize = curUser->numLists - 1;

        //Insert the new series in the desired index by the user
        printf("Enter list index (0-%d):", maxArraySize);
        scanf("%d", &indexResult);
        while (getchar() != '\n');

        // Checks the index validity
        if (indexResult > maxArraySize) {
            printf("Invalid index\n");
            free(seriesName);
            seriesName = NULL;
            return;
        }
        newSeries = createSeries(seriesName, indexResult, curUser);
        if (newSeries == NULL) return;

        // When the series in the list are exist, the new series will be added at the end of the list
        SeriesList *curList = curUser->seriesLists[indexResult];
        while (curList != NULL) {
            if (curList->next == NULL) {
                curList->next = (SeriesList *) malloc(sizeof(SeriesList));
                if (curList->next == NULL) return;
                curList->next->series = newSeries;
                curList->next->next = NULL;
                return;
            }
            curList = curList->next;
        }

    } else {
        printf("Invalid choice\n");
        free(seriesName);
        seriesName = NULL;
        return;
    }
}

// Function to return the desired user
User *returnUser(char *userName, UserDB *userDB) {
    if (userName == NULL)
        return NULL;
    User *returnUser = userDB->users;

    // If the new user was found, return it
    while (returnUser != NULL) {
        if (strcmp(returnUser->name, userName) == 0) {
            return returnUser;
        }
        returnUser = returnUser->next;
    }
    return NULL;
}

// Function to check if specific series exists, ant return it if it does
Series *checkSeries(User *curUser, char *seriesName) {
    if (curUser == NULL || seriesName == NULL) {
        return NULL;
    }
    User *tempUser = curUser;
    // Iterate through the user's series
    for (int i = 0; i < tempUser->numLists; i++) {
        SeriesList *tempSeries = tempUser->seriesLists[i];
        while (tempSeries != NULL) {
            if (strcmp(tempSeries->series->name, seriesName) == 0) {
                // The desired series was found
                return tempSeries->series;
            }
            if (tempSeries->next == NULL) break;

            tempSeries = tempSeries->next;
        }
    }
    return NULL;
}


// Function to add new episode to the episodes list
void addEpisode(UserDB *userDB) {
    if (userDB == NULL)
        return;

    printf("Enter user name: ");
    char *userName = getString();
    // Retrieve the user from the database
    User *newUser = returnUser(userName, userDB);

    // Check if the user was returned successfully, if not he is not existing
    if (newUser == NULL || userName == NULL) {
        printf("User not found\n");
        free(userName);
        return;
    }

    printf("Enter series name: ");
    char *seriesName = getString();
    // Retrieve the user's series
    Series *curSeries = checkSeries(newUser, seriesName);

    if (curSeries == NULL || seriesName == NULL) {
        printf("Series not found\n");
        free(seriesName);
        free(userName);
        return;
    }

    printf("Enter episode name: ");
    char *newEpisodeName = getString();
    if (newEpisodeName == NULL) {
        free(userName);
        free(seriesName);
        free(newEpisodeName);
        return;
    }

    //There is not more use in the user and series names so we release them
    free(userName);
    userName = NULL;
    free(seriesName);
    seriesName = NULL;

    printf("Enter season and episode number: ");

    int seasonNumber, episodeNumber;
    scanf("%d %d", &seasonNumber, &episodeNumber);
    //clearing the buffer from the scan-f
    while (getchar() != '\n');

    //creating the new episode
    Episode *newEpisode = (Episode *) malloc(sizeof(Episode));
    if (newEpisode == NULL) return;
    newEpisode->name = (char *) malloc((strlen(newEpisodeName) + 1) * sizeof(char));
    if (newEpisode->name == NULL) return;
    strcpy(newEpisode->name, newEpisodeName);
    free(newEpisodeName);
    newEpisodeName = NULL;
    newEpisode->season = seasonNumber;
    newEpisode->episode = episodeNumber;
    newEpisode->next = NULL;

    // If the series has no episodes, insert the new episode first in the list
    if (curSeries->episodes == NULL) {
        curSeries->episodes = newEpisode;
        curSeries->episodes->next = NULL;
        curSeries->numEpisode++;
        return;
    }

    //When there are only one episode in the series
    if (curSeries->episodes->next == NULL) {
        if (newEpisode->season < curSeries->episodes->season) {
            newEpisode->next = curSeries->episodes;
            curSeries->episodes = newEpisode;
            curSeries->episodes->next->next = NULL;
            curSeries->numEpisode++;
            return;
        }
        if (newEpisode->season == curSeries->episodes->season) {
            if (newEpisode->episode <= curSeries->episodes->episode) {
                newEpisode->next = curSeries->episodes;
                curSeries->episodes = newEpisode;
                curSeries->episodes->next->next = NULL;
                curSeries->numEpisode++;
                return;
            } else {
                curSeries->episodes->next = newEpisode;
                newEpisode->next = NULL;
                curSeries->numEpisode++;
                return;
            }
        } else {
            curSeries->episodes->next = newEpisode;
            newEpisode->next = NULL;
            curSeries->numEpisode++;
            return;
        }
    }

    // If the new episode should be the first in the list
    if (newEpisode->season <= curSeries->episodes->season) {
        if (newEpisode->season < curSeries->episodes->season) {
            newEpisode->next = curSeries->episodes;
            curSeries->episodes = newEpisode;
            curSeries->numEpisode++;
            return;
        }
        if (newEpisode->episode <= curSeries->episodes->episode) {
            newEpisode->next = curSeries->episodes;
            curSeries->episodes = newEpisode;
            curSeries->numEpisode++;
            return;
        }
    }

    //when there are more than one episode in the series
    Episode *curEpisode = curSeries->episodes->next;
    Episode *tempEpisode = curSeries->episodes;
    // Loop through the episodes to find the appropriate position to insert the new episode
    while (curEpisode != NULL) {
        if (newEpisode->season < curEpisode->season) {
            newEpisode->next = curEpisode;
            tempEpisode->next = newEpisode;
            curSeries->numEpisode++;
            return;
        } else if (newEpisode->season == curEpisode->season) {
            if (newEpisode->episode <= curEpisode->episode) {
                newEpisode->next = curEpisode;
                tempEpisode->next = newEpisode;
                curSeries->numEpisode++;
                return;
            }
        } else {
            newEpisode->next = curEpisode->next;
            curEpisode->next = newEpisode;
            curSeries->numEpisode++;
            return;
        }
        //The new episode should be the last in the list
        if (curEpisode->next == NULL) {
            curEpisode->next = newEpisode;
            newEpisode->next = NULL;
            curSeries->numEpisode++;
            return;
        }
        tempEpisode = curEpisode;
        curEpisode = curEpisode->next;
    }
}


// Function to print the database information
void printUserDB(UserDB *userDb) {

    if (userDb == NULL) return;

    User *userPointer = NULL;
    SeriesList *seriesListPointer = NULL;
    Episode *episodePointer = NULL;
    int listIndex = ZERO;

    userPointer = userDb->users;
    // Loop through each user
    while (userPointer != NULL) {
        printf("User: %s", userPointer->name);

        // Loop through each series list of the user
        for (listIndex = 0; listIndex < userPointer->numLists; listIndex++) {
            if (listIndex > 0) printf("\n");
            printf("\nList %d:\n", listIndex);
            seriesListPointer = userPointer->seriesLists[listIndex];

            // Loop through each series in the series list
            while (seriesListPointer != NULL) {
                printf("       Series: %s", seriesListPointer->series->name);

                episodePointer = seriesListPointer->series->episodes;

                // Loop through each episode of the series
                while (episodePointer != NULL) {
                    printf("\n               Season: %d, Episode: %d, \"%s\"", episodePointer->season,
                           episodePointer->episode, episodePointer->name);

                    episodePointer = episodePointer->next;
                }

                if (seriesListPointer->next != NULL) printf("\n");
                seriesListPointer = seriesListPointer->next;
            }
        }
        printf("\n");
        userPointer = userPointer->next;
    }
}


// Function to clear all allocated memory, and initialize the database
void clearUserDB(UserDB *userDb) {
    // The list is empty
    if (userDb == NULL || userDb->numUsers == 0) return;

    //Only the userDb exists
    if (userDb->users == NULL) return;

    User *userPointer = userDb->users;
    // Iterate through the users, series lists and episodes
    while (userPointer != NULL) {

        for (int i = 0; i < userPointer->numLists; i++) {
            SeriesList *seriesListFromArrayPointer = userPointer->seriesLists[i];

            while (seriesListFromArrayPointer != NULL) {
                Series *seriesPointer = seriesListFromArrayPointer->series;

                if (seriesPointer == NULL) break;

                Episode *episodePointer = seriesPointer->episodes;
                Episode *episodeTemp = NULL;
                while (episodePointer != NULL) {
                    episodeTemp = episodePointer;
                    episodePointer = episodePointer->next;
                    free(episodeTemp->name);
                    episodeTemp->name = NULL;
                    episodeTemp->next = NULL;
                    free(episodeTemp);
                    episodeTemp = NULL;
                }
                //now the episode were released
                seriesPointer->episodes = NULL;

                //freeing the current series
                free(seriesPointer->name);
                seriesPointer->name = NULL;
                seriesPointer->numEpisode = 0;
                free(seriesPointer);
                seriesPointer = NULL;
                seriesListFromArrayPointer->series = NULL;

                SeriesList *seriesListFromArrayTemp = seriesListFromArrayPointer;
                seriesListFromArrayPointer = seriesListFromArrayPointer->next;
                free(seriesListFromArrayTemp);
                seriesListFromArrayTemp = NULL;
            }
            userPointer->seriesLists[i] = NULL;
        }

        //All the current user series list were released
        free(userPointer->seriesLists);
        userPointer->seriesLists = NULL;

        //releasing the user
        User *userPointerTemp = userPointer;
        userPointer = userPointer->next;
        free(userPointerTemp->name);
        userPointerTemp->name = NULL;
        userPointerTemp->next = NULL;
        free(userPointerTemp);
        userPointerTemp = NULL;
    }

    //only the userDB remain
    userDb->users = NULL;
    userDb->numUsers = 0;
}

/// dynamic menu:
// Define function pointer type for menu options with and without UserDB parameter
typedef void (*menu_option_function_t)(void);

typedef void (*menu_option_function_tUserDB)(UserDB *);

// Define a structure to represent menu options with and without UserDB parameter
typedef struct {
    char name[MAX_MENU_OPTION_NAME_LENGTH];
    menu_option_function_t function;
    menu_option_function_tUserDB functionUserDb;
} menu_option_t;

typedef struct {
    char name[MAX_MENU_OPTION_NAME_LENGTH];
    menu_option_function_tUserDB function;
} menu_option_tUserDB;


// Function to display and execute a menu for menu options
int printMenu(menu_option_t menuOptions[], int arrayLength) {
    int chosenMenuOptionNumber = -1;

    printf("Choose an option:\n");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d. %s\n", i + 1, menuOptions[i].name);
    }
    printf("%d. exit\n", arrayLength + 1);

    scanf("\n%d", &chosenMenuOptionNumber);

    // Exit option chosen
    if (chosenMenuOptionNumber == arrayLength + 1) return 1;
    // Invalid option chosen
    if (chosenMenuOptionNumber < 0 || chosenMenuOptionNumber > arrayLength) return -1;

    // Execute chosen menu option
    menuOptions[chosenMenuOptionNumber - 1].function();
    return -1;
}


int printMenuUserDB(menu_option_tUserDB menuOptionsUserDB[], int arrayLength, UserDB *userDb) {
    int chosenMenuOptionNumberDB = -1;

    printf("Choose an option:\n");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d. %s\n", i + 1, menuOptionsUserDB[i].name);
    }
    printf("%d. exit\n", arrayLength + 1);

    scanf("\n%d", &chosenMenuOptionNumberDB);

    // Exit option chosen
    if (chosenMenuOptionNumberDB == arrayLength + 1) return 1;
    // Invalid option chosen
    if (chosenMenuOptionNumberDB < 0 || chosenMenuOptionNumberDB > arrayLength) return -1;

    // Execute chosen menu option
    menuOptionsUserDB[chosenMenuOptionNumberDB - 1].function(userDb);
    return -1;
}

// Main menu option functions for various categories
void printOperationsMenu(void) {
    int printMenuReturnValue;

    menu_option_t menuOptions[] = {
            {"base2dec",            baseToDec},
            {"dec2base",            decToBase},
            {"plus",                plus},
            {"prime factorization", primeFactorization},
            {"print diamond",       printDiamond}
    };

    do {
        printMenuReturnValue = printMenu(menuOptions, sizeof(menuOptions) / sizeof(menuOptions[0]));
    } while (printMenuReturnValue == -1);
}

void printRecursionMenu(void) {
    int printMenuReturnValue;
    menu_option_t menuOptions[] = {
            {"reverse string",              reverseString},
            {"abs diff nums",               absDiffNums},
            {"subset sum",                  subsetSum},
            {"longest increasing subarray", longestIncreasingSubarray}
    };

    do {
        printMenuReturnValue = printMenu(menuOptions, sizeof(menuOptions) / sizeof(menuOptions[0]));
    } while (printMenuReturnValue == -1);
}

void printDataStructuresMenu(void) {
    int printMenuReturnValue;
    UserDB userDB = {};
    menu_option_tUserDB menuOptions[] = {
            {"Initalize UserDB", initUserDb},
            {"Add User",         addUser},
            {"Add Series",       addSeries},
            {"Add Episode",      addEpisode},
            {"Print UserDB",     printUserDB},
            {"Clear UserDB",     clearUserDB}
    };
    do {
        printMenuReturnValue = printMenuUserDB(menuOptions, sizeof(menuOptions) / sizeof(menuOptions[0]), &userDB);
    } while (printMenuReturnValue == -1);
}

void printMainMenu() {
    int printMenuReturnValue;

    // Main menu options
    menu_option_t menuOptions[] = {
            {"basic operations and flow", printOperationsMenu},
            {"recursion",                 printRecursionMenu},
            {"data structures",           printDataStructuresMenu}
    };

    do {
        printMenuReturnValue = printMenu(menuOptions, sizeof(menuOptions) / sizeof(menuOptions[0]));
    } while (printMenuReturnValue == -1);
}


int main() {

    printMainMenu();

    return 0;
}