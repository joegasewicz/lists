# Lists
A linked list static library written in C

#### L_List *L_list_new(data)
Create a new list
```c
// Create some data
typedef struct data_t {
   char *name;
} Data;

Data *data = malloc(sizeof(Data));
data->name = calloc(4, sizeof(char));
strcpy(data->name, "Joe");

// Pass the data to L_list_new to return the new head of the
// linked list
L_List *head = L_list_new(data);
```

#### void L_list_insert(L_List *list, void *data)
Insert a new item at the tail of the list

```c
// Create the data and then create a new list
L_List *head = L_list_new(data);

// Pass the head list head reference to L_list_insert function
L_list_insert(list, data2);
```

#### void *L_list_delete(L_List *list, void *data)
Remove a node from the list at nth position (matched via the data reference)
```c
// Create your `void* data` & insert the data ref into the list with `L_list_insert`
L_list_insert(list, data);

// Pass the dasta reference to the L_list_delete function as a 2nd argument
void *result = L_list_delete(list, data);
if (result < 0)
      // handle error
```

#### int L_list_size(L_List *list)
```c
int *d1 = 1;
int *d2 = 1;
L_List *l = L_list_new(d1);
L_list_insert(l, d2);

// Get the sum total of nodes in the list
int result = L_list_size(l); // returns 2
```

#### L_IS_EMPTY(l) (macro)
Checks if the list is empty. The macro will return true if there are
no nodes in the list or the list has not yet been initiated.
```c
int *d = 1;
L_List *l = L_list_new(d);
int result = L_IS_EMPTY(l); // returns false
```

#### L_LIST_NEXT(l) (macro)
Get the next list node
```c
int *d1 = 1;
int *d2 = 2;
int result;
L_List *l = L_list_new(d1);
L_list_insert(l, d2);
L_List *l2 = L_LIST_NEXT(l);
L_List *l3 = L_LIST_NEXT(l2);
```

#### L_LIST_DATA(l) (macro)
Get the current node's data
```c
int *d1 = 1;
L_List *l = L_list_new(d1);
int result = L_LIST_DATA(l);
```

#### void L_list_destroy(L_List * list)
Detaches each node from the list.
This function does not destroy allocated memory
assigned to the node's data.
```c
int *d1 = 1;
int *d2 = 2;
int result;
L_List *l = L_list_new(d1);
L_list_insert(l, d2);
L_list_destroy(l);
```
#### L_List *L_list_tail(L_List *list)
Returns the last node in the list
```c
int *d1 = 1;
int *d2 = 2;
int result;
L_List *l = L_list_new(d1);
L_list_insert(l, d2);
L_List *l2 = L_LIST_NEXT(l);
L_List *tail = L_list_tail(l);
```
## Authors

* **joegasewicz** - *Initial work* - [@joegasewicz](https://twitter.com/joegasewicz)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

### Tests
Tests are written in [cmocka](https://cmocka.org/)

### Documentation
This library uses [doxygen](https://www.doxygen.nl/) to generate inline docs.

## License
[MIT](https://choosealicense.com/licenses/mit/)