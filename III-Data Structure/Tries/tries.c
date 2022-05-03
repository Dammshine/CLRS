#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
// Define the character size
#define CHAR_SIZE 26
 
// Data structure to store a Trie node
struct Trie {
    char currChar;
    bool finish;
    struct Trie* character[CHAR_SIZE];
    // And if the tries is finish, you might want to store an additional attribute
    // Such as if the string is a name, this can be an ID
    // If tries want to count the word, this can be used to store an int count
};
 
// Function that returns a new Trie node
struct Trie* getNewTrieNode() {
    struct Trie* newT = malloc(sizeof(*newT));
    newT->currChar = '\0';
    newT->finish = false;
    for (int i = 0; i < CHAR_SIZE;i++) {
        newT->character[i] = NULL;
    }
    return newT;
}

// Using recursive approach
struct Trie* insertHelper(struct Trie *head, char* str, int index, int size) {
    // Create node if head id empty
    if (head == NULL) {
        head = getNewTrieNode();
    }

    // Insert character
    head->currChar = str[index];
    index++;

    // Check if str ended
    if (index == size) {
        head->finish = true;
    } // Going to next loop
    else {
        head->character[str[index] - 'a'] = insertHelper(head->character[str[index] - 'a'], str, index, size);
    }
    return head;
} 

struct Trie *insert(struct Trie *head, char* str) {
    head->character[str[0] - 'a'] = insertHelper(head->character[str[0] - 'a'], str, 0, strlen(str));
    return head;
}
 
// Similar recursive approach
bool searchHelper(struct Trie *head, char* str, int index, int size) {
    // If current head do not exist
    if (head == NULL) {
        return false;
    }

    // Compare the word
    if (head->currChar != str[index]) {
        return false;
    } 
    index++;
    // Check if letter finish
    if (index == size) {
        if (head->finish == true) return true;
        return false;
    } // Recursively search for the next character
    else {
        return searchHelper(head->character[str[index] - 'a'], str, index, size);
    }
} 

bool search(struct Trie* head, char* str) {
    return searchHelper(head->character[str[0] - 'a'], str, 0, strlen(str));
}
 
// Returns 1 if a given Trie node has any children
bool hasChildren(struct Trie* curr) {
    for (int i = 0; i < CHAR_SIZE; i++) {
        if (curr->character[i] != NULL) return true;
    }
    return false;
}

// str need to have enough space
void printTriesHelper(struct Trie *root, char *str) {
    // Base case
    if (root == NULL) return;

    // recursive case
    // add current char to the root
    int size = strlen(str);
    str[size] = root->currChar;
    str[size + 1] = '\0';

    // If string finish here
    if (root->finish == true) {
        printf("%s \n", str);
    }
    // Then recursive visit children from this position
    for (int i = 0; i < CHAR_SIZE; i++) {
        printTriesHelper(root->character[i], str);
    }
    // After visit each node, one is responsible for erase the char last accessed
    str[size] = '\0';
}

void printTries(struct Trie *root, char *str) {
    for (int i = 0; i < CHAR_SIZE; i++) {
        printTriesHelper(root->character[i], str);
    }
}
 
// Recursive function to delete a string from a Trie
void deletionHelper(struct Trie *head, char* str, int index, int size) {
    // Create node if head id empty
    if (head == NULL) return;
    // if the character if not matching
    if (head->currChar != str[index]) return;
    index++;

    if (index == size) {
        head->finish = false;
        return;
    }

    deletionHelper(head->character[str[index] - 'a'], str, index, size);
} 

void deletion(struct Trie *curr, char* str) {
    deletionHelper(curr->character[str[0] - 'a'], str, 0, strlen(str));
}


 
// Trie implementation in C – Insertion, Searching, and Deletion
int main()
{
    struct Trie* head = getNewTrieNode();
 
    insert(head, "hello");
    if (search(head, "hello") == true) {
        printf("hello\n");
    }
    insert(head, "hey");
    insert(head, "no");
    insert(head, "bro");
    insert(head, "hey");
    deletion(head, "hello");

    char *inspect = malloc(1024);
    inspect[0] = '\0';
    printTries(head, inspect);
}