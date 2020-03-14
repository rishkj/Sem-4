typedef struct node
{
    int data;
    struct node *link;
}node;



//This is the hashfunction to decide the index where we insert the element in the hash table
int hashfunc(int x,int n);


//If an element exists at that index, we have to use the following methods to find new index.
//They are seperate chaining, linear probing, quadratic probing and double hashing.


//This method involves creating a linked list at each position in the hash table so we can insert multiple elements into table at one index.
//This also lets us take more elements into hash table than hash table size.
int seperatechaining(int n, node *a[n],int index,int x);


//We keep increasing index by 1 until we get a position in array which is empty.
int linearprobing(int index,int *a,int n);


//We keep adding squares of consecutive numbers to index to get a position in array which is empty.
int quadprobing(int index,int *a, int n);


//This method involves using a second hash function in case of collisions. 
//Hashfunc returns a value which cant be zero to doublehash
//Doublehash uses that value to find an index where there is no element.
int hashfunc2(int x);
int doublehash(int *dh,int n,int index,int x);







//Below are the functions to find the position of element in hash table.



//This method is used to find index of element in hash table formed by seperate chaining.
//We get index from hash function and check linked list at that index for element.
//If found, we return index. Otherwise we return -1.
int findsp(int n,node *a[n],int key);


//This method is used to find index of element in hash table formed by linear probing.
//We get index where element should be and if we reach a position in hash table which is emoty orwe cover the complete hash table, the element isnt in hash table.
int findlp(int *a,int n,int x);


//This method is used to find index of element in hash table formed by double hashing.
//We check if element is at index given by original hash function.
//If it isnt, we use index given by second hash function to check if element is there or not.
int finddh(int *a,int n,int key);