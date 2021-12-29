#include <stdio.h>
#include <string.h>

int main() {
    char preamble[] = "We hold these truths to be self-evident, that all men are created equal that they are "
                      "endowed, their Creator, with certain unalienable Rights, that among these are Life, "
                      "Liberty, and the pursuit of Happiness. That to secure these rights, Governments are "
                      "instituted among Men, deriving their just powers from the consent of the governed, That "
                      "whenever any Form of Government becomes destructive of these ends, it is the Right of "
                      "the People to alter or abolish it, and to institute new Government, laying its foundation "
                      "on such principles, and organizing its powers in such form, as to them shall seem most "
                      "likely to effect their Safety and Happiness. Prudence, indeed, will dictate that "
                      "Governments long established should not be changed for light and transient causes; and "
                      "evils are sufferable, than to right themselves by abolishing the forms to which they are "
                      "accustomed. But when a long train of abuses and usurpations, pursuing invariably the "
                      "same Object, evinces a design to reduce them under absolute Despotism, it is their right, "
                      "it is their duty, to throw off such Government, and to provide new Guards for their "
                      "future security.";

    // #1/#2/#3 - Using strtok to tokenize a string containing multiple sentences in to individual sentences.
    // Using strtok to tokenize a string containing a sentence into individual words and determining the number
    // of words in that sentence and correctly calculaltes the average number of words per sentence.

    char* token = strtok(preamble, ".");
    char* arr[4]; // create an array of size 4 to hold the sentences
    char** ptr = arr; // pointer for the array
    int count = 0;

    // loop to add sentences to the array
    for (int i = 0; i <= 3; ++i) {
        if(token != NULL){
            printf("%s\n", token);
            ptr[i] = token;
            token = strtok(NULL, ".");
        }
    }

    int sum = 0;
    // loop through each sentence and count each word in the sentence
    for (int i = 0; i <= 3; ++i) {
        char* sentence = ptr[i];
        char* token2_1 = strtok(sentence, " ");
        while (token2_1 != NULL){
            token2_1 = strtok(NULL, " ");
            ++count;
        }
        printf("%d words in sentence ", count);
        printf("%d\n", i+1);

        sum += count;
        count = 0;
    }

    int average = sum/4;
    printf("Average number of words per sentence is %d", average);


    return 0;
}
