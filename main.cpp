#include <iostream>
#include <string>

using std::cout;
using std::string;

#define SMALL_LETTERS 26
struct Node
{
    char c;
    bool is_word= false;
    Node * neighbors[SMALL_LETTERS];
    Node(char mch):  c(mch)
    {
        for (int i= 0; i<SMALL_LETTERS; ++i)  neighbors[i] = nullptr;

    }
};

class Trie
{
    private:
        Node *root = nullptr;

    public:
        Trie(){
            root = new Node('\0');
        }
        bool search(string mstr){
            Node *curr = search_helper(mstr);
            return curr !=nullptr && curr->is_word ? true: false;}

        Node* search_helper(string mstr)
        {
            Node *curr = root;
            char mch;
            for (int i=0; i< mstr.length(); ++i)
                {
                    mch = mstr[i];
                    if(curr->neighbors[mch - 'a'] == nullptr)
                        return nullptr;
                    curr = curr->neighbors[mch - 'a'];
                }
            return curr;
        }
        bool startswith(string mstr)
        {
            return search_helper(mstr) !=nullptr ? true: false;
        }
        void insert(string mstr)
        {
            Node *curr = root;
            char tch;
            for (int i=0; i<mstr.length(); ++i)
            {
                tch = mstr[i];
                if (curr->neighbors[tch - 'a'] == nullptr)
                    curr->neighbors[tch -'a'] = new Node(tch);
                curr = curr->neighbors[tch-'a'];
            }
            curr->is_word = true;


        }



};

int main()
{
    
    Trie mtre;
    mtre.insert("test");
    if (mtre.search("test"))
        cout<<"found ----"<<'\n';
    
    if (mtre.startswith("tes"))
        cout<<"starts with ...."<<'\n';
    return 0;
}
