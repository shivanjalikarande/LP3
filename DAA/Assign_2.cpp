#include <iostream>
#include <queue>
using namespace std;

//Write a program to implement Huffman Encoding using a greedy strategy.

class Node
{
    public:
        char ch;
        int freq;
        Node* left;
        Node* right;
        Node(char c,int f)
        {
            ch = c;
            freq = f;
            left = NULL;
            right = NULL;
        }
};

class Compare
{
    public:
    bool operator() (Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void findHuffmanCodes(Node* root, int* huffCodes, string code)
{
    if(!root) return;

    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->ch<<": "<<code<<endl;
        return;
    }

    findHuffmanCodes(root->left, huffCodes, code + "0");
    findHuffmanCodes(root->right, huffCodes, code + "1");
}



void huffmanEncoding(string str, int* freq)
{
    priority_queue<Node*, vector<Node*>, Compare>pq;
    
    //inserting nodes in priority queue - Min Heap
    for(int i=0;i<str.size();i++)
    {
        Node* temp = new Node(str[i],freq[i]);
        pq.push(temp);
    }

    //Huffman Tree
    while(pq.size() >= 2)
    {
        Node* l = pq.top();
        pq.pop();
        Node* r = pq.top();
        pq.pop();

        Node* newNode = new Node('-',l->freq + r->freq);

        newNode->left = l;
        newNode->right = r;

        pq.push(newNode);
    }

    Node* root = pq.top();
    int *huffCodes = new int[str.size()];

    findHuffmanCodes(root, huffCodes, "");

}


int main()
{
    int n;
    string str;
    cout<<"Enter string of characters: ";
    cin>>str;
    n = str.length();
    
    int *freq = new int[n];
    cout<<"\nEnter frequency of each charcter\n"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Freq of "<<str[i]<<": ";
        cin>>freq[i];
    }
    cout<<"\n"<<endl;

    huffmanEncoding(str,freq);


    return 0;
}
