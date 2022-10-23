#include <stdlib.h>
#include <ctime>
#include<string>
#include <sstream>
using namespace std;
#include "SinglyLinkedList.h"

template <class S>

class ChainedHashTable {
    class KeyValuePair {
        public:
            string key;
            S* value;
            
            string toString() {
                stringstream ss;
                ss << "(" << this->key << "," << value->toString() << ")";
                return ss.str();
            }
    };

    private:
        SinglyLinkedList<KeyValuePair> *hashTable;
        int size;
        int keyLength;

    public:
        ChainedHashTable(int initSize, int initKeyLength) {
            keyLength = initKeyLength;
            hashTable = new SinglyLinkedList<KeyValuePair>[initSize];
            this->size = initSize;
            srand((unsigned) time(0));
        }

        int hashCode(string key) {
            int charsSum = 0;
            for (auto it = key.cbegin(); it != key.cend(); ++it) {
                int num = (int)(*it);
                charsSum += num;
            }
            return charsSum % size;
        }

        string generateKey() {
            string key {""};
            for (int i = 0; i < this->keyLength; i++) {
                int randomNum = (rand() % 36);
                char randomChar;
                if (randomNum < 10) {
                    randomChar = (char)(randomNum + 48);
                }
                else {
                    randomChar = (char)(randomNum + 55);
                }
                key += randomChar;
            }
            return key;
        }

        S* get(string key) {
            int index = this->hashCode(key);
            SinglyLinkedList<KeyValuePair> *list = &(hashTable[index]);

            // NOW SEARCH THE LIST
            Iterator<KeyValuePair> *it = list->getIterator();
            while (it->hasNext()) {
                KeyValuePair *keyValuePair = it->next();
                string testKey = keyValuePair->key;
                if (testKey.compare(key) == 0) {
                    return keyValuePair->value;
                }
            }

            return nullptr;
        }

        void put(string key, S* item) {
            int index = this->hashCode(key);
            SinglyLinkedList<KeyValuePair> *list = &(hashTable[index]);
            
            // FIRST SEE IF IT'S ALREADY IN THE LIST, IF IT IS
            // THEN REPLACE IT
            Iterator<KeyValuePair> *it = list->getIterator();
            while (it->hasNext()) {
                KeyValuePair *keyValuePair = it->next();
                string testKey = keyValuePair->key;
                if (testKey.compare(key) == 0) {
                    keyValuePair->value = item;
                    return;
                }
            }

            // MAKE A KeyValuePair
            KeyValuePair *keyValuePair = new KeyValuePair();
            keyValuePair->key = key;
            keyValuePair->value = item;
            
            // GET AND ADD IT TO THE LIST
            list->append(keyValuePair);
        }

        string toString() {
            stringstream ss;
            int counter = 0;
            ss << "[" << endl;
            for (int i = 0; i < size; i++) {
                SinglyLinkedList<KeyValuePair> *list = &(hashTable[i]);
                ss << " " << i << ": " << list->toString() << endl;
            }
            ss << "]" << endl;
            return ss.str();;
        }
};