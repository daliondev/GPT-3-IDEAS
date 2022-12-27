#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101

struct hash_entry
{
    char *key;
    int value;
    struct hash_entry *next;
};

struct hash_table
{
    int size;
    struct hash_entry **table;
};

struct hash_table *create_hash_table(int size)
{
    struct hash_table *ht = malloc(sizeof(struct hash_table));
    ht->size = size;
    ht->table = calloc(size, sizeof(struct hash_entry *));
    return ht;
}

void free_hash_table(struct hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        struct hash_entry *entry = ht->table[i];
        while (entry)
        {
            struct hash_entry *prev = entry;
            entry = entry->next;
            free(prev->key);
            free(prev);
        }
    }
    free(ht->table);
    free(ht);
}

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

void hash_table_set(struct hash_table *ht, char *key, int value)
{
    unsigned long index = hash(key) % ht->size;
    struct hash_entry *entry = ht->table[index];
    while (entry)
    {
        if (strcmp(entry->key, key) == 0)
        {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    entry = malloc(sizeof(struct hash_entry));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = ht->table[index];
    ht->table[index] = entry;
}

int hash_table_get(struct hash_table *ht, char *key)
{
    unsigned long index = hash(key) % ht->size;
    struct hash_entry *entry = ht->table[index];
    while (entry)
    {
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

struct hash_table *word_lengths(char *string)
{
    struct hash_table *ht = create_hash_table(HASH_SIZE);
    char *token = strtok(string, " \t\n");
    while (token)
    {
        hash_table_set(ht, token, strlen(token));
        token = strtok(NULL, " \t\n");
    }
    return ht;
}

int main(int argc, char **argv)
{
    char string[] = "Hello everyone";
    struct hash_table *ht = word_lengths(string);

    // Print the lengths of each word in the string
    char *token = strtok(string, " \t\n");
    while (token)
    {
        printf("%s: %d\n", token, hash_table_get(ht, token));
        token = strtok(NULL, " \t\n");
    }

    // Free the hash table
    free_hash_table(ht);
    return 0;
}
