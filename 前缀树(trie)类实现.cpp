#include<bits/stdc++.h>
using namespace std;

class trie{
     class trienode{
     public:
          int pass;
          int end;
          trienode* next[26];
          trienode(){
               pass=0;
               end=0;
               for(int i=0;i<26;++i) next[i]=nullptr;
          }
     };
private:
     trienode* root;
public:

     trie(){
          root=new trienode();
     }
     void insert(string s){
          trienode node=*root;
          node.pass++;
          for(int i=0;i<s.size();++i){
               int path=s[i]-'a';
               if(node.next[path]==nullptr) node.next[path]=new trienode;
               node=*node.next[path];
               node.pass++;
          }
          node.end++;
     }

     int prefixnumber(string s){
          trienode node=*root;
          for(int i=0;i<s.size();++i){
               int path=s[i]-'a';
               if(node.next[path]==nullptr) return 0;
               node=*node.next[path];
          }
          return node.pass;
     }

     int search(string s){
          trienode node=*root;
          for(int i=0;i<s.size();++i){
               int path=s[i]-'a';
               if(node.next[path]==nullptr) return 0;
               node=*node.next[path];
          }
          return node.end;
     }

     void del(string s){
          if(search(s)>0){
               trienode node=*root;
               node.end--;
               for(int i=0;i<s.size();++i){
                    int path=s[i]-'a';
                    if(node.next[path]->end==1){
                         node.next[path]=nullptr;
                         return;
                    }
                    else {
                         node=*node.next[path];
                         node.pass--;
                    }
               }
               node.end--;
          }
     }
};

int main(){
     trie t1;
     for(int i=0;i<4;++i){
          string s;
          cin>>s;
          t1.insert(s);
          cout<<t1.search(s)<<' ';
     }
}