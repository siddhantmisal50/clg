# PS = Implement all the functions of a dictionary (ADT) using hashing and handle
# collisions using chaining with / without replacement. Data: Set of (key, value) pairs, Keys are mapped to
# values, Keys must be comparable, Keys must be unique Standard Operations: Insert(key, value), Find(key),
#Delete(key) (python)

# Insert Operation : Whenever an element is to be inserted, compute the hash code of the key passed and
# locate the index using that hash code as an index in the array. Use linear probing for empty location, if an
# element is found at the computed hash code.
# Example void insert(int key,int data)
# {struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
# item->data = data;
# item->key = key;
# //get the hash int hashIndex = hashCode(key);
# //move in array until an empty or deleted cell
# while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
# { //go to next cell ++hashIndex; //wrap around the table hashIndex %= SIZE; }
# hashArray[hashIndex] = item; }

# Delete Operation: Whenever an element is to be deleted, compute the hash code of the key passed and
# locate the index using that hash code as an index in the array. Use linear probing to get the element ahead
# if an element is not found at the computed hash code. When found, store a dummy item there to keep the
# performance of the hash table intact.
# Example struct DataItem* delete(struct DataItem* item)
# { int key = item->key;
# //get the hash int hashIndex = hashCode(key);
#//move in array until an empty#
# while(hashArray[hashIndex] !=NULL)
# { if(hashArray[hashIndex]->key == key)
# { struct DataItem* temp = hashArray[hashIndex];
# //assign a dummy item at deleted position hashArray[hashIndex] = dummyItem;
# return temp; }
# //go to next cell ++hashIndex;
# //wrap around the table hashIndex %= SIZE; } return NULL; }

# Search Operation Whenever an element is to be searched, compute the hash code of the key passed and
# locate the element using that hash code as index in the array. Use linear probing to get the element ahead if
# the element is not found at the computed hash code.
# Example
# struct DataItem *search(int key)
# {
# //get the hash int hashIndex = hashCode(key); //move in array until an empty while(hashArray[hashIndex]
#!= NULL)
# {
# if(hashArray[hashIndex]->key == key)
# return hashArray[hashIndex];
# /go to next cell ++hashIndex;
# //wrap around the table hashIndex %= SIZE;
# }
# return NULL; }

class HashTable:
    def __init__(self, num) -> None:
        self.size = int(num)
        self.dictionary = [[None]]*num

    def isEmpty(self) -> str:
        for x in self.dictionary:
            if x[0] == None:
                pass
            else:
                return "List is not empty!"
        return "List is empty!"

    def hash(self, key) -> int:
        return key % self.size

    def search(self, key, value) -> str:
        if value in self.dictionary[key]:
            return True
        else:
            return False

    def insert(self, key, value) -> bool:
        key = self.hash(key)
        if(self.search(key, value)):
            return False
        else:
            if ((len(self.dictionary[key]) == 1) and (self.dictionary[key][0] == None)):
                self.dictionary[key] = [value]
            else:
                self.dictionary[key].append(value)
            return True

    def display(self) -> None:
        print(self.dictionary)


if __name__ == '__main__':
    while(1):
        try:
            num = int(input("Enter total number : "))
        except:
            print("Enter an integer!")
            continue
        if(num <= 0):
            print("Enter non-zero positive number!")
        elif(num > 0):
            break
    mydictionary = HashTable(num)
    while(1):
        try:
            choice = int(
                input("\nEnter :\n1. Insert\n2. Display\n3. Search\n4. Exit\n-->"))
        except:
            print("Enter an integer!")
            continue
        match choice:
            case 1:
                key = int(input("Enter key :"))
                value = input("Enter value :")
                state = mydictionary.insert(key=key, value=value)
                print("Inserted successfully!") if state else print(
                    "Element is already present")
            case 2:
                mydictionary.display()
            case 3:
                key = int(input("Enter key : "))
                value = input("Enter value :")
                if(mydictionary.search(hash(key), value)):
                    print("Element is present!")
                else:
                    print("Element is not present!")
            case 4:
                del mydictionary, key, value
                print("Object has been deleted!")
                print("Exiting Program...")
                exit()
            case _:
                print("Enter valid option!")
