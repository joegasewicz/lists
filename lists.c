/** @file lists.c */
/**
* MIT License
*
* Copyright (c) 2023 Joe Gasewicz
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "lists.h"

/********************************************//**
 * @brief Creates a new instance of the L_List object
 * & return the the list head.
 * @param data void* generic data type
 * @return L_List*
 *
 ***********************************************/
L_List *L_list_new(void *data)
{
    L_List *l = malloc(sizeof(L_List));
    l->data = data;
    l->next = NULL;
    return l;
}

/********************************************//**
 * @brief Inserts an L_List at the tail position of
 * the list. The list will remain in the head position
 * after this routine has been run.
 *
 * @param list the head of the list
 * @param data a pointer to pre allocated memory holding
 * the void *data ref.
 * @return
 *
 ***********************************************/
int L_list_insert(L_List *const list, void *data)
{
    L_List *tempList = list;
    while(tempList->next != NULL)
    {
        tempList = tempList->next;
    }
    tempList->next = malloc(sizeof(L_List));
    if (tempList->next == NULL)
    {
        printf("Error: unable to allocate memory");
        return L_ALOC_ERROR;
    }
    tempList->next->data = data;
    tempList->next->next = NULL;
    return L_NO_ERROR;
}

/********************************************//**
 * @brief Delete a single L_List node from the list.
 * The list lookup requires a valid void *data reference.
 * This function also cleans up the memory the void *data
 * points to. If there is an error allocating memory then
 * this function will return a the value of L_ALOC_ERROR.
 * @param list L_List*
 * @param data void* There must be a valid data reference
 * @return void*
 *
 ***********************************************/
void *L_list_delete(L_List *list, void *data)
{
    L_List *tempPtr = list;
    L_List *prevPtr;
    // check if the current head of the list contains the same ref to data
    // & compare the address from void *data
    if (list->data == data)
    {
        tempPtr = list; // temporarily store node being deleted
        list = list->next;
        free(tempPtr->data);
        free(tempPtr);
    }
    else
    {
        while(tempPtr->data != data)
        {
            prevPtr = tempPtr;
            tempPtr = list->next;
        }
        prevPtr->next = tempPtr->next;
        free(tempPtr->data);
        free(tempPtr);
    }
    return data;
}


/********************************************//**
 * @brief Returns the size of the list based on
 * total count of nodes.
 *
 * @param list L_List*
 * @return int
 *
 ***********************************************/
int L_list_size(L_List *list)
{
    int i = 0;
    L_List *currPtr = list;
    while (currPtr->next != NULL)
    {
        currPtr = currPtr->next;
        i++;
    }
    return i;
}

/********************************************//**
 * @brief Detaches each node from the list.
 * This function does not destroy allocated memory
 * assigned to the node's data.
 *
 * @param list L_List*
 * @return void
 *
 ***********************************************/
void L_list_destroy(L_List * list)
{
    L_List *tempPtr;
    if (list == NULL)
        return;
    while(tempPtr->next != NULL)
    {
        if (list->next == NULL)
        {
            free(list);
            break;
        }
        tempPtr = list;
        list = list->next;
        if (tempPtr)
            free(tempPtr);
    }
}

/********************************************//**
 * @brief Returns the last node in the list
 *
 * @param list L_List*
 * @return void
 *
 ***********************************************/
L_List *L_list_tail(L_List *list)
{
    L_List *tempPtr = list;
    if (tempPtr->next == NULL)
        return tempPtr;
    while (tempPtr->next != NULL)
        tempPtr = tempPtr->next;
    return tempPtr;
}