#include <bits/stdc++.h>
using namespace std;
# define noofoperators 3
# define specialchar '$'
int nodenumber = 0;
typedef struct node{
    int id;
    vector<struct node *> to[noofoperators+1];
}node;

typedef struct graph{
    node *enter;
    node *exit;
}graph;

typedef struct operators{
    char x;
    graph *y;
}operators;
vector<node *> tt_table;
node *create_node(){
    node *x = new node;
    x->id = nodenumber;
    nodenumber++;
    tt_table.push_back(x);
    return x;
}
graph *removestar(vector<operators *> rgex){
    node *u = create_node();
    node *v = create_node();
    rgex[0]->y->exit->to[0].push_back(v);
    rgex[0]->y->exit->to[0].push_back(rgex[0]->y->enter);
    u->to[0].push_back(rgex[0]->y->enter);
    u->to[0].push_back(v);
    graph *temp = new graph;
    temp->enter = u;
    temp->exit = v;
    return temp;
}
graph *concatenate(vector<operators *>rgex){
    graph *temp = new graph;
    for(int i=0;i<rgex.size()-1;i++){
        rgex[i]->y->exit->to[0].push_back(rgex[i+1]->y->enter);
    }
    temp->enter = rgex.front()->y->enter;
    temp->exit = rgex.back()->y->exit;
    return temp;
}
graph *removebrackets(vector<operators *> rgex){
    vector<int> pos_of_ors;
    for(int i=0;i<rgex.size();i++){
        if(rgex[i]->x == '*'){
            vector <operators *> newrgex(rgex.begin()+i-1,rgex.begin()+i);
            rgex.erase(rgex.begin()+i-1, rgex.begin()+i+1);
            graph *temp = removestar(newrgex);
            operators *a = new operators;
            a->x = specialchar;
            a->y = temp;
            rgex.insert(rgex.begin()+i-1, a);
            i = i-1;
        }
        if(rgex[i]->x=='|')
            pos_of_ors.push_back(i);
    }
    vector <graph *> ready_to_or;
    while(pos_of_ors.empty()==0){
        vector <operators *> newrgex(rgex.begin()+pos_of_ors.back()+1,rgex.end());
        rgex.erase(rgex.begin()+pos_of_ors.back(),rgex.end());
        pos_of_ors.pop_back();
        ready_to_or.push_back(concatenate(newrgex));
    }
    ready_to_or.push_back(concatenate(rgex));
   if(ready_to_or.size()>1){
        node *u = create_node();
        node *v = create_node();
        graph *temp = new graph;
        temp->enter = u;
        temp->exit = v;
        for(int i=0; i<ready_to_or.size();i++){
            ready_to_or[i]->exit->to[0].push_back(v);
            u->to[0].push_back(ready_to_or[i]->enter);
        }
        return temp;
    }
    else
    {
        return ready_to_or[0];
    }
    
}
int main(){
    string s;
    cin >> s;
    //s = "(a((ab|c)*a)bc)|c";
    vector <operators *> rgex;
    operators *a = new operators;
    a->x = '(';
    a->y = NULL;
    rgex.push_back(a);
    for(int i=0; i<s.length();i++){
        a = new operators;
        a->x = s[i];
        if(!(s[i]=='('||s[i]==')'||s[i]=='|'||s[i]=='*')){
            node *u = create_node();
            node *v = create_node();
            u->to[s[i]-'a'+1].push_back(v);
            graph *g = new graph;
            g->enter = u;
            g->exit = v;
            a->y = g;
        }
        else
            a->y = NULL;
        rgex.push_back(a);
    }
    a = new operators;
    a->x = ')';
    a->y = NULL;
    rgex.push_back(a);
    vector<int> bucket;
    int start, stop;
    for(int i=0;i<rgex.size();i++){
        if(rgex[i]->x == '('){
            bucket.push_back(i);
        }
        else if (rgex[i]->x == ')' && bucket.empty() == 0){
            start = bucket.back();
            bucket.pop_back();
            stop = i;
            vector <operators *> newrgex(rgex.begin()+start+1,rgex.begin()+stop);
            rgex.erase(rgex.begin()+start, rgex.begin()+stop+1);
            graph *temp = removebrackets(newrgex);
            operators *a = new operators;
            a->x = specialchar;
            a->y = temp;
            rgex.insert(rgex.begin()+start, a);
            i = start+1;
        }
        else if (rgex[i]->x == ')'){
            cout << "Brackets not matched" << endl;
            return 0;
        }
    }
    if (bucket.empty() == 0){
        cout << "Brackets not matched" << endl;
        return 0;
    }
     cout << "Start traversal from node " << rgex[0]->y->enter->id << " and need to reach node " << rgex[0]->y->exit->id <<" to complete the traversal "<<endl;
    for(int i=0;i<tt_table.size(); i++){
        cout << "From " << tt_table[i]->id << endl;
        for(int j = 0; j<=noofoperators;j++){
            if (j==0)
                cout << "\t"<< "epsilon" << " = ";
            else
                cout << "\t" << char('a'+j-1) << " =";
            for(int k = 0; k<tt_table[i]->to[j].size();k++)
                cout << tt_table[i]->to[j][k]->id << " ";
            cout << endl;
        }
    }
    return 0;
}