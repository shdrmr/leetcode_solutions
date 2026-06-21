#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define HASH_BUCKET_SIZE 64

struct Node
{
    int key;
    int val;
    struct Node* next;
};

struct Map
{
    struct Node* buckets[HASH_BUCKET_SIZE];
};


void map_insert(struct Map* map, int key, int val)
{
    // very simple hash where hash = key itself
    unsigned bucket_id = (unsigned)key % (unsigned)HASH_BUCKET_SIZE;
    struct Node* node = map->buckets[bucket_id];

    while (node)
    {
        if (key == node->key)
        {
            node->val = val;
            return;
        }
        node = node->next;
    }

    node = calloc(1, sizeof(struct Node));
    node->key = key;
    node->val = val;
    map->buckets[bucket_id] = node;
}

struct Node* map_find(struct Map* map, int key)
{
    unsigned bucket_id = (unsigned)key % (unsigned)HASH_BUCKET_SIZE;
    struct Node* node = map->buckets[bucket_id];
    while(node)
    {
        if (node->key == key)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void map_free(struct Map* map)
{
    for(int i = 0; i < HASH_BUCKET_SIZE; i++)
    {
        struct Node* node = map->buckets[i];
        while(node)
        {
            struct Node* next = node->next;
            free(node);
            node = next;
        }
    }

    free(map);
}


void twoSum_C(const int* const nums, int num_elements, int* res, int target)
{
    struct Map* map = calloc(1, sizeof(struct Map));

    for (int i = 0; i < num_elements; i++)
    {
        int val = target - nums[i];
        struct Node* node = map_find(map, val);
        if (node)
        {
            res[0] = i;
            res[1] = node->val;
            map_free(map);
            return;
        }
        map_insert(map, nums[i], i);
    }

    map_free(map);
}
