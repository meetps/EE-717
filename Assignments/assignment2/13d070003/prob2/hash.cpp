/*Start of prefix code. DO NOT EDIT PREFIX CODE*/
#include<iostream>
#include<fstream>
#include<cstdint>
#include<string.h>
#include<string>

using namespace std;

int M=0, N=0;
#define EMPTY -2
#define FREE -1


struct Tuple{
    char value[20];
};

struct Tuple *valTable = NULL; //used to store the actual strings
uint32_t *hashTable = NULL; //used to store the keys alone


uint32_t jenkins_one_at_a_time_hash(char *key)
{
    uint32_t hash, i;

    int len = strlen(key);
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void init()
{
    int i;
    valTable = new Tuple[M];
    hashTable = new uint32_t[M];

    for(i=0; i<M; i++){
        hashTable[i] = EMPTY;
    }
    N = 0;
}

void cleanup()
{
    delete(valTable); valTable = NULL;
    delete(hashTable); hashTable = NULL;
}

/*
0 -Search
1 -Insert
2 -Delete
3 -Print
*/

int search(char *a)
{
    uint32_t hash = jenkins_one_at_a_time_hash(a);
    uint32_t pos = hash%M;
    int count = 0;
    while((count < M) /*&& (hashTable[pos] != hash)*/)
    {

        if(hashTable[pos] == hash)
             {
                 return pos;
             }
        if(pos != M-1)
                {
                    pos += 1;    
                }
        else 
                {
                    pos = 0;
                }
        count++;
    }

    if(count == M)
    {
        return -1;
    }    
}

/*End of prefix code. Do not edit code above this line*/
	
	//Complete rest of the code for search()


int insert(char *a)
{
	//Write code for insert()
    uint32_t hash = jenkins_one_at_a_time_hash(a);
    uint32_t pos = hash%M;
    int count = 0;
    
        while( (count<= M) /*&& (hashTable[pos]!= FREE || hashTable[pos] != EMPTY)*/)
        {
            
            if( (hashTable[pos] == FREE) || (hashTable[pos] == EMPTY))
                {
                        hashTable[pos] = hash;
                        strcpy(valTable[pos].value,a);
                        N++;
                        return pos; 
                }

            /*else if(count == M)
                {
                        return -1;
                }
            */        

            else
                {    
                    if(pos != M-1)
                        {
                            pos += 1;    
                        }
           
                    else
                        {
                            pos = 0;
                        }
                    count++;
                }        
        }       
    return -1;                  
}

int deleteHash(char *a)
{
	//Write code for deleteHash()
    uint32_t hash = jenkins_one_at_a_time_hash(a);
    uint32_t pos = hash%M;
    int count = 0;
    while((count <= M) /*(hashTable[pos] != hash)*/)
    {
        // cout << pos<<endl;
        if( (hashTable[pos] == hash) && (string(valTable[pos].value) == string(a)) )
             {
                 hashTable[pos] = FREE ;
                 N--;
                 // cout << "delete"<<endl;
                 // cin >> count;
                 return pos;
             }

        else if( (hashTable[pos] == hash) && (string(valTable[pos].value) != string(a) ) )     
        {
               // cout << "delete"<<endl;
               return -2;
        }
             
        else if( count == M )
        {
                // cout << "delete"<<endl;
                return -1;
        }

        else 
        {
                    // cout << "delete"<<endl;
                    if(pos != M-1)
                        {
                        pos += 1;
                        // cout << pos<<endl;    
                        }      
                    else 
                        {
                            // cout << pos<<endl;
                        pos = 0;
                        }
                    count++;
        }     
    }

}


/*Start of suffix code. DO NOT EDIT CODE BELOW THIS LINE TILL THE END OF FILE*/

void printTable(ofstream &fp)
{
    int i;
    for(i=0; i<M; i++){
        fp << "Pos " << i << " : Key "<< (unsigned long)hashTable[i] << " ";
        if(hashTable[i] != EMPTY && hashTable[i] != FREE){
            fp << "Value " <<  valTable[i].value;
        }
        fp << endl;
    }
}

int main(int argc, char **argv)
{
    char str[20];
    int i;

    char line[80];
    int op;

    int status;

    std::ifstream fp;
    std::ofstream fp1;

    if(argc != 3){
        cout << "Pass <input file> <outputfile> as arguments when you run the executable" << endl;
        printf("Example: ./hash input.txt ouptut.txt\n");
        exit(-1);
    }

    fp.open(argv[1]);
    fp1.open(argv[2]);

    if(!fp){
        cout << "Input file " << argv[1] << " not present" << endl;
        exit(1);
    }

    fp >> M;
    
    init();
    
    while(fp >> op >> str){
        switch(op){
            case 0: status=search(str); fp1 << status << endl;break;
            case 1: status=insert(str); fp1 << status << endl;break;
            case 2: status=deleteHash(str); fp1 << status << endl;break;
            case 3: printTable(fp1); break;
        }
    }    
    fp.close();
    fp1.close();
    
    cleanup();
    return 0;
}
/*End of suffix code. DO NOT EDIT THE SUFFIX CODE*/

