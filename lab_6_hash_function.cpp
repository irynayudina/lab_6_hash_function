
#include "D:\source\repos\algorithms_and_data_structures\laboratory2\List.h"
#include <iostream>
using namespace std;
// hash functions//////////////////////////////////////////////////////////////////////////////////////////////////
int HashFunctionMultiplication(int k)
{
    int N = 33; double A = 0.618033;
    int h = floor(N * fmod(k * A, 1));
    return h;
}
int HashFunctionDivision(int k)
{
    return (k % 33);
}
int HashFunctionRowKeys(const char* ch)
{
    int a = 29; int M = 33;
    int result = 0;
    int size = sizeof(ch);
    for (int i = 0; i < size; i++) {
        result += (static_cast<int>(ch[i]) * pow(a, i));
    }
    result = result % M;
    return result;
}
int HashFunctionRowKeys(string ch)
{
    int a = 26; int M = 13;
    int result = 0;
    int size = ch.length();
    for (int i = 0; i < size; i++) {
        result += (static_cast<int>(ch[i]) * pow(a, i));
    }
    result = result % M;
    return result;
}
template< class K, class D>
struct hashTableEntry {
    K e_key;
    D e_data;
    hashTableEntry() {
        
    }
    hashTableEntry(K key, D data) {
        this->key = key;
        this->data = data;
    }
    hashTableEntry<K, D>& operator=(const hashTableEntry<K, D>& other) {
        this->e_data = other.e_data;
        this->e_key = other.e_key;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const hashTableEntry<K, D>& dt);
};
template< class K, class D>
ostream& operator<<(ostream& os, const hashTableEntry<K, D>& dt)
{
    os << "key: " << dt.key << " " << "value: " << dt.data;
    return os;
}
template< class K, class D>
class HashTable_open_hashing {
private:
    int T_S;
    List<hashTableEntry<K,D>>* lists;
public:
    HashTable_open_hashing(int size = 33) {
        T_S = size;
        lists = new List<hashTableEntry<K, D>>[T_S];
    }
    void insert_table(int k, hashTableEntry<K, D> d) {
        lists[k].createnode(d);
    }
    void delete_table(K k) {

    }
    List<hashTableEntry<K, D>> find(K k) {
        return lists[0];
    }
    void print_table() {

    }
    // hash functions//////////////////////////////////////////////////////////////////////////////////////////////////
    friend int HashFunctionMultiplication(int k);
    friend int HashFunctionDivision(int k);
    friend int HashFunctionRowKeys(string ch);
};
template< class K, class D>
class HashTable_closed_hashing {
private:
    int T_S = 33;
    hashTableEntry<K, D>* table;
public:
     HashTable_closed_hashing(int size = 33) {
     T_S = size;
     table = new  hashTableEntry<K, D>[T_S];
     }
    void insert_table(int k, hashTableEntry<K, D> d) {
        table[k] = d;
    }
    void delete_table(K k) {

    }
    hashTableEntry<K, D> find(K k) {
        return table[0];
    }
    void print_table() {

    }
    // hash functions//////////////////////////////////////////////////////////////////////////////////////////////////
    friend int HashFunctionMultiplication(int k);
    friend int HashFunctionDivision(int k);
    friend int HashFunctionRowKeys(string ch);
};

void inserter_i_i(int& key, int& value, hashTableEntry<int, int>& hte_i_i, int& choise, int& ind, HashTable_open_hashing<int, int>& hash_table_i_i);

int main()
{
    cout << "Hello World!\n";
    int fpm = 0, spm = 0, thpm = 0, choise = 0;
    HashTable_open_hashing<int, int> hash_table_i_i;
    HashTable_open_hashing<int, string> hash_table_i_s;
    HashTable_open_hashing<string, int> hash_table_s_i;
    HashTable_open_hashing<string, string> hash_table_s_s;
    HashTable_closed_hashing<int, int> hash_table_i_i_c;
    HashTable_closed_hashing<int, string> hash_table_i_s_c;
    HashTable_closed_hashing<string, int> hash_table_s_i_c;
    HashTable_closed_hashing<string, string> hash_table_s_s_c;
    hashTableEntry<int, int> hte_i_i;
    hashTableEntry<int, string> hte_i_s;
    hashTableEntry<string, int> hte_s_i;
    hashTableEntry<string, string> hte_s_s;
    string str_key, str_value; int ind, key, value;
    while (fpm != 3) {
        cout << "choose the action" << endl;
        cout << "1 - HashTable_open_hashing" << endl;
        cout << "2 - HashTable_closed_hashing" << endl;
        cout << "3 - exit the menu" << endl;
        cin >> fpm;
        switch (fpm)
        {
        case 1:
            while (spm != 5) {
                cout << "choose the action" << endl;
                cout << "1 - int key int value" << endl;
                cout << "2 - int key string value" << endl;
                cout << "3 - string key int value" << endl;
                cout << "4 - string key string value" << endl;
                cout << "5 - exit the menu" << endl;
                cin >> spm;
                switch (spm)
                {
                case 1:
                    cout << "HashTable_open_hashing<int, int> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            cout << "enter value int: " << endl;
                            cin >> value;
                            hte_i_i.e_key = key; hte_i_i.e_data = value;
                            cout << "choose 1 - division or 2 - multiplication method" << endl;
                            cin >> choise;
                            if (choise == 1) {
                                ind = HashFunctionDivision(key);
                            }
                            else if (choise == 2) {
                                ind = HashFunctionMultiplication(key);
                            }
                            hash_table_i_i.insert_table(ind, hte_i_i);
                            break;
                        case 2:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_i.delete_table(key);
                            break;
                        case 3:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_i.find(key);
                            break;
                        case 4:
                            hash_table_i_i.print_table();
                            break;
                        }
                    }
                    break;
                case 2:
                    cout << "HashTable_open_hashing<int, string> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            cout << "enter value string: " << endl;
                            cin >> str_value;
                            hte_i_s.e_key = key; hte_i_s.e_data = str_value;
                            cout << "choose 1 - division or 2 - multiplication method" << endl;
                            cin >> choise;
                            if (choise == 1) {
                                ind = HashFunctionDivision(key);
                            }
                            else if (choise == 2) {
                                ind = HashFunctionMultiplication(key);
                            }
                            hash_table_i_s.insert_table(ind, hte_i_s);
                            break;
                        case 2:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_s.delete_table(key);
                            break;
                        case 3:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_s.find(key);
                            break;
                        case 4:
                            hash_table_i_s.print_table();
                            break;
                        }
                    }
                    break;
                case 3:
                    cout << "HashTable_open_hashing<string, int> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            cout << "enter value int: " << endl;
                            cin >> value;
                            hte_s_i.e_key = str_key; hte_s_i.e_data = value;
                            ind = HashFunctionRowKeys(str_key);
                            hash_table_s_i.insert_table(ind, hte_s_i);
                            break;
                        case 2:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_i.delete_table(str_key);
                            break;
                        case 3:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_i.find(str_key);
                            break;
                        case 4:
                            hash_table_s_i.print_table();
                            break;
                        }
                    }
                    break;
                case 4:
                    cout << "HashTable_open_hashing<string, string> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            cout << "enter value string: " << endl;
                            cin >> str_value;
                            hte_s_s.e_key = str_key; hte_s_s.e_data = str_value;
                            ind = HashFunctionRowKeys(str_key);
                            hash_table_s_s.insert_table(ind, hte_s_s);
                            break;
                        case 2:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_s.delete_table(str_key);
                            break;
                        case 3:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_s.find(str_key);
                            break;
                        case 4:
                            hash_table_s_s.print_table();
                            break;
                        }
                    }
                    break;
                }
            }
            spm = 0;
            break;
        case 2:
            while (spm != 5) {
                cout << "choose the action" << endl;
                cout << "1 - int key int value" << endl;
                cout << "2 - int key string value" << endl;
                cout << "3 - string key int value" << endl;
                cout << "4 - string key string value" << endl;
                cout << "5 - exit the menu" << endl;
                cin >> spm;
                switch (spm)
                {
                case 1:
                    cout << "HashTable_closed_hashing<int, int> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            cout << "enter value int: " << endl;
                            cin >> value;
                            hte_i_i.e_key = key; hte_i_i.e_data = value;
                            cout << "choose 1 - division or 2 - multiplication method" << endl;
                            cin >> choise;
                            if (choise == 1) {
                                ind = HashFunctionDivision(key);
                            }
                            else if (choise == 2) {
                                ind = HashFunctionMultiplication(key);
                            }
                            hash_table_i_i_c.insert_table(ind, hte_i_i);
                            break;
                        case 2:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_i_c.delete_table(key);
                            break;
                        case 3:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_i_c.find(key);
                            break;
                        case 4:
                            hash_table_i_i_c.print_table();
                            break;
                        }
                    }
                    break;
                case 2:
                    cout << "HashTable_closed_hashing<int, string> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            cout << "enter value string: " << endl;
                            cin >> str_value;
                            hte_i_s.e_key = key; hte_i_s.e_data = str_value;
                            cout << "choose 1 - division or 2 - multiplication method" << endl;
                            cin >> choise;
                            if (choise == 1) {
                                ind = HashFunctionDivision(key);
                            }
                            else if (choise == 2) {
                                ind = HashFunctionMultiplication(key);
                            }
                            hash_table_i_s_c.insert_table(ind, hte_i_s);
                            break;
                        case 2:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_s_c.delete_table(key);
                            break;
                        case 3:
                            cout << "enter key int: " << endl;
                            cin >> key;
                            hash_table_i_s_c.find(key);
                            break;
                        case 4:
                            hash_table_i_s_c.print_table();
                            break;
                        }
                    }
                    break;
                case 3:
                    cout << "HashTable_closed_hashing<string, int> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            cout << "enter value int: " << endl;
                            cin >> value;
                            hte_s_i.e_key = str_key; hte_s_i.e_data = value;
                            ind = HashFunctionRowKeys(str_key);
                            hash_table_s_i_c.insert_table(ind, hte_s_i);
                            break;
                        case 2:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_i_c.delete_table(str_key);
                            break;
                        case 3:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_i_c.find(str_key);
                            break;
                        case 4:
                            hash_table_s_i_c.print_table();
                            break;
                        }
                    }
                    spm = 0;
                    break;
                case 4:
                    cout << "HashTable_closed_hashing<string, string> hash_table" << endl;
                    while (thpm != 5) {
                        cout << "choose the action" << endl;
                        cout << "1 - insert key-value" << endl;
                        cout << "2 - delete by key" << endl;
                        cout << "3 - find by key" << endl;
                        cout << "4 - print table" << endl;
                        cout << "5 - exit the menu" << endl;
                        cin >> thpm;
                        switch (thpm)
                        {
                        case 1:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            cout << "enter value string: " << endl;
                            cin >> str_value;
                            hte_s_s.e_key = str_key; hte_s_s.e_data = str_value;
                            ind = HashFunctionRowKeys(str_key);
                            hash_table_s_s_c.insert_table(ind, hte_s_s);
                            break;
                        case 2:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_s_c.delete_table(str_key);
                            break;
                        case 3:
                            cout << "enter key string: " << endl;
                            cin >> str_key;
                            hash_table_s_s_c.find(str_key);
                            break;
                        case 4:
                            hash_table_s_s_c.print_table();
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}

void inserter_i_i(int& key, int& value, hashTableEntry<int, int>& hte_i_i, int& choise, int& ind, HashTable_open_hashing<int, int>& hash_table_i_i)
{
    cout << "enter key int: " << endl;
    cin >> key;
    cout << "enter value int: " << endl;
    cin >> value;
    hte_i_i.e_key = key; hte_i_i.e_data = value;
    cout << "choose 1 - division or 2 - multiplication method" << endl;
    cin >> choise;
    if (choise == 1) {
        ind = HashFunctionDivision(key);
    }
    else if (choise == 2) {
        ind = HashFunctionMultiplication(key);
    }
    hash_table_i_i.insert_table(ind, hte_i_i);
}

