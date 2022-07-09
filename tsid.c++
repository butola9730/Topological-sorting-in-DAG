#include<iostream> 
#include<stack>
#include<list>  
using namespace std; 
  
class graph
{ 
    int no_of_vertices;
    list<int>* l1;  
  
  public:
    graph(int n) 
  { 
      no_of_vertices=n; 
      l1=new list<int>[n]; 
  } 
  

    void add_edge(int x, int y)
  {
     l1[x].push_back(y);
  } 
  void topological(int, int [], stack<int>& );
    void topological_sort(); 
}; 
  
void graph::topological(int vertex_no, int visited[], stack<int>& s) 
{ 
    visited[vertex_no]=1; 
  
 
    list<int>::iterator i; 
    for (i = l1[vertex_no].begin(); i != l1[vertex_no].end(); i++)
  { 
        if (visited[*i]==0)
    { 
            topological(*i,visited,s);
    }
  }
  

    s.push(vertex_no); 
} 
  
void graph::topological_sort() 
{ 
    stack<int> s; 
    int i,visited[no_of_vertices];
    
    for (i=0; i<no_of_vertices;i++)
  {
    visited[i]=0; 
  } 

    for (i=0; i<no_of_vertices;i++)
  {
    if (visited[i]==0)
    {
      topological(i,visited,s); 
    } 
  } 
  
    while(!s.empty()) 
  {
    int k=s.top(); 
        cout<<k<<" "; 
        s.pop(); 
    } 
} 
  
int main() 
{ 
    graph p(4);  // 4: no of vertices
    p.add_edge(0, 1); 
    p.add_edge(0, 2); 
    p.add_edge(1, 2); 
    p.add_edge(1, 3); 
    p.add_edge(2, 3); 
    
  
    cout <<"\nTopological order of the vertices of the graph: "; 
    p.topological_sort(); 
  
    return 0; 
}
