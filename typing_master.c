#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SENTENCES 25
#define MAX_LENGTH 200

int main()
{
    char sentences[MAX_SENTENCES][MAX_LENGTH] = {
        "Practice makes a man perfect.",
        "Typing fast improves productivity.",
        "C language is powerful and fast.",
        "Never stop learning new things.",
        "Consistency is the key to success.",
        "Discipline beats motivation every single day.",
        "Success comes to those who work hard silently.",
        "A journey of a thousand miles begins with one step.",
        "Dream big, stay focused, and make it happen.",
        "Time waits for none, use it wisely.",
        "Great things take time, keep going.",
        "Patience and practice bring perfection.",
        "Do something today that your future self will thank you for.",
        "Believe in yourself and all that you are.",
        "Small steps lead to big achievements.",
        "Hard work always beats talent when talent doesn’t work hard.",
        "Push yourself because no one else will do it for you.",
        "The secret of getting ahead is getting started.",
        "Mistakes are proof that you are trying.",
        "Don’t watch the clock, do what it does and keep going.",
        "Failure is not opposite of success, it’s part of success.",
        "Knowledge is power, but only if applied well.",
        "Typing fast comes from accuracy and confidence.",
        "Success is not final, failure is not fatal.",
        "Every expert was once a beginner."};

    srand(time(NULL));
    int index = rand() % MAX_SENTENCES;

    char input[MAX_LENGTH];
    clock_t start, end;
    int correct = 0;

    printf("\n\t********** WELCOME TO TYPING MASTER **********\n");
    printf("\nType the sentence shown below as quickly and accurately as possible.\n\n");
    printf("Sentence:\n%s\n", sentences[index]);
    printf("\nPress any key to start typing...\n");

    printf("\nStart typing:\n");
    start = clock(); // start timer

    fflush(stdin);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline

    end = clock();                                                // end timer
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // seconds

    int len_original = strlen(sentences[index]);
    int len_input = strlen(input);

    int min_len = len_original < len_input ? len_original : len_input;

    for (int i = 0; i < min_len; i++)
    {
        if (sentences[index][i] == input[i])
        {
            correct++;
        }
    }

    double accuracy = ((double)correct / len_original) * 100;
    double words = len_input / 5.0; // average 5 letters per word
    double wpm = (words / time_taken) * 60;

    printf("\n\n********** RESULTS **********\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f words per minute (WPM)\n", wpm);

    printf("\nThank you for playing Typing Master!\n");
    printf("************************************\n");

    return 0;
}
