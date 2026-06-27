#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_BUCKETS 32

struct Node
{
    char key;
    int val;
    struct Node* next;
};

struct Map
{
    struct Node* buckets[NUM_BUCKETS];
};

struct Node* map_find(struct Map* map, char key)
{
    int bucket_id = (unsigned)key % NUM_BUCKETS;
    struct Node* node = map->buckets[bucket_id];
    while (node)
    {
        if (node->key == key)
        {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

struct Node* map_insert(struct Map* map, char key, int val)
{
    int bucket_id = (unsigned)key % NUM_BUCKETS;
    struct Node* node = map->buckets[bucket_id];
    while (node)
    {
        if (node->key == key)
        {
            node->val = val;
            return node;
        }
        node = node->next;
    }

    node = calloc(1, sizeof(struct Node));
    node->key = key;
    node->val = val;
    map->buckets[bucket_id] = node;
    return node;
}

void map_free(struct Map* map)
{
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        struct Node* node = map->buckets[i];
        while(node)
        {
            struct Node* next = node->next;
            free(node);
            node = next;
        }
    }
}

int romanToInt_C(const char* s, size_t size)
{
    struct Map* map = calloc(1, sizeof(struct Map));
    map_insert(map, 'I', 1);
    map_insert(map, 'V', 5);
    map_insert(map, 'X', 10);
    map_insert(map, 'L', 50);
    map_insert(map, 'C', 100);
    map_insert(map, 'D', 500);
    map_insert(map, 'M', 1000);
    int total = 0;
    int prevVal = 0;
    for (int i = 0; i < sizeof(s); i++)
    {
        struct Node* node = map_find(map, s[i]);
        printf("YOO wtf %c\n", s[i]);
        if (node == NULL)
        {
            continue;
        }
        int currVal = node->val;
        total += currVal;
        if (currVal > prevVal)
        {
            total = total - (prevVal * 2);
        }
        prevVal = currVal;
    }
    map_free(map);
    return total;
}
