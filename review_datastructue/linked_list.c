#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    size_t length;
    Node *header;
} Linklist;

/* 前置声明：insert_end 在 insert_at 之前定义，需要先声明 */
bool insert_at(Linklist *list, size_t index, int element);

void init_link(Linklist *list)
{
    list->length = 0;
    list->header = NULL;
}

void destroy_list(Linklist *list)
{
    Node *current_node = list->header;
    while (current_node != NULL)
    {
        Node *need_free = current_node;
        current_node = current_node->next;
        free(need_free);
    }
    list->header = NULL;
    list->length = 0;
}

size_t get_length(Linklist *list)
{
    return list->length;
}

/* 返回下标 index 的前驱结点；约定 index >= 1，index == 0 由调用方单独处理 */
static Node *find_pre_node(Linklist *list, size_t index)
{
    Node *pre = list->header;
    for (size_t i = 1; i < index; i++)
    {
        pre = pre->next;
    }
    return pre;
}

void insert_end(Linklist *list, int element)
{
    insert_at(list, list->length, element);
}

bool delete_at(Linklist *list, size_t index, int *element)
{
    if (index >= list->length)
    {
        return false;
    }
    Node *del_node = NULL;
    if (index == 0)
    {
        del_node = list->header;
        /* 删除头结点：让 header 指向下一个结点，而不是让 header->next 指向自己 */
        list->header = del_node->next;
    }
    else
    {
        Node *pre = find_pre_node(list, index);
        del_node = pre->next;
        pre->next = del_node->next;
    }
    *element = del_node->data;
    free(del_node);
    list->length--;
    return true;
}

bool delete_end(Linklist *list, int *element)
{
    if (list->length == 0)
    {
        return false;
    }
    /* 最后一个元素的下标是 length - 1 */
    return delete_at(list, list->length - 1, element);
}

bool get_value(Linklist *list, size_t index, int *element)
{
    if (index >= list->length)
    {
        return false;
    }
    if (index == 0)
    {
        /* 下标 0 就是头结点，没有前驱 */
        *element = list->header->data;
    }
    else
    {
        Node *pre = find_pre_node(list, index);
        *element = pre->next->data;
    }
    return true;
}

bool edit_value(Linklist *list, size_t index, int value)
{
    if (index >= list->length)
    {
        return false;
    }
    if (index == 0)
    {
        list->header->data = value;
    }
    else
    {
        Node *pre = find_pre_node(list, index);
        pre->next->data = value;
    }
    return true;
}

void print_list(Linklist *list)
{
    Node *current_node = list->header;
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

bool insert_at(Linklist *list, size_t index, int element)
{
    if (index > list->length)
    {
        return false;
    }
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        return false;
    }
    node->data = element;
    if (index == 0)
    {
        node->next = list->header;
        list->header = node;
    }
    else
    {
        Node *pre = find_pre_node(list, index);
        node->next = pre->next;
        pre->next = node;
    }
    list->length++;
    return true;
}

int main(void)
{
    Linklist list;
    init_link(&list);

    insert_at(&list, 0, 1);
    insert_at(&list, 0, 2);
    insert_at(&list, 0, 3);
    insert_at(&list, 0, 4);
    print_list(&list); /* 4 3 2 1 */

    int value;
    if (get_value(&list, 1, &value))
    {
        printf("list[1] = %d\n", value); /* 3 */
    }
    if (delete_at(&list, 0, &value))
    {
        printf("deleted %d\n", value); /* 4 */
    }
    if (edit_value(&list, 0, 99))
    {
        print_list(&list); /* 99 2 1 */
    }
    if (delete_end(&list, &value))
    {
        printf("deleted end %d\n", value); /* 1 */
    }
    print_list(&list); /* 99 2 */

    destroy_list(&list);
    return 0;
}
