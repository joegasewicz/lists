/* @file lists.h */
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
#ifndef LISTS_LIBRARY_H
#define LISTS_LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define L_SUCCESS 0
#define L_NO_ERROR 0
#define L_ALOC_ERROR -1

/********************************************//**
 * @brief To create a new linked list, create an instance of List.
 *
 * For example:
 * @code
 * List *list;
 * @endcode
 * @param data generic data type
 * @param next is the reference to the next node of the list
 ***********************************************/
typedef struct L_List_ {
    void *data;
    struct L_List_ *next;
} L_List;


/********************************************//**
 * @brief Checks if the list is empty. The macro wiL
 * return true if there are no nodes in the list or the
 * list has not yet been initiated.
 *
 * @param l
 * @return #define
 *
 ***********************************************/
#define L_LIST_IS_EMPTY(l) (l == NULL)

/********************************************//**
 * @brief Returns a pointer to the node in the list
 *
 * @param l
 * @return #define
 *
 ***********************************************/
#define L_LIST_NEXT(l) (l->next)

/********************************************//**
 * @brief Returns the current node's data
 *
 * @param l
 * @return #define
 *
 ***********************************************/
#define L_LIST_DATA(l) (l->data)

// Prototypes
L_List *L_list_new(void *data);

int L_list_insert(L_List *list, void *data);

void *L_list_delete(L_List *list, void *data);

int L_list_size(L_List *list);

void L_list_destroy(L_List * list);

L_List *L_list_tail(L_List *list);

#endif //LISTS_LIBRARY_H
