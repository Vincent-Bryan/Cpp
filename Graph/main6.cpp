#include<bits/stdc++.h>
using namespace std;
//建立十字链表 
/*
0 1
0 2
0 3
1 4
4 5
*/

//dfs

//bfs

//non_recursive_dfs

//capsulation
struct EdgeNode{
	int id;
	int StartVec;
	int EndVec;
	EdgeNode* path1;
	EdgeNode* path2;
};
struct VecNode{
	int VecID;
	EdgeNode* edge;
};

class Graph{
	private:
		int vecnum;
		VecNode vecnode[100];
	public:
		bool edgevisit[100] = {0};
		Graph(int n);
		void dfs(EdgeNode* e);
		void subscript_dfs(int n){
			memset(edgevisit, 0, sizeof(edgevisit));
			dfs(vecnode[n].edge);
		}
		void bfs(EdgeNode* e);
		void subsrcipt_bfs(int n){
			memset(edgevisit, 0, sizeof(edgevisit));
			bfs(vecnode[n].edge);
		}
		void non_recursive_dfs(int n);
		EdgeNode* get_edge(int n){
			return vecnode[n].edge;
		}
		void set_edge(int n, EdgeNode* e){
			vecnode[n].edge = e;
		}
		
		
};

Graph::Graph(int n){
	vecnum = n;
	for(int i = 0; i < n; i++){
		vecnode[i].edge = NULL;
		vecnode[i].VecID = i;
	}
}
void Graph::dfs(EdgeNode* e){
	cout << e->id << ' ' << e->StartVec << ' ' << e->EndVec << endl;
	edgevisit[e->id] = 1;
	while(e->path2 != NULL){
		if(!edgevisit[e->path2->id])
			dfs(e->path2);
		else break;
	}
	while(e->path1 != NULL){
		if(!edgevisit[e->path1->id])
			dfs(e->path1);
		else break;
	}
	return ;
}

void Graph::bfs(EdgeNode* e){
	cout << e->id << ' ' << e->StartVec << ' ' << e->EndVec  << endl;
	edgevisit[e->id] = 1;

	while(e->path1 != NULL){
		if(!edgevisit[e->path1->id])
			bfs(e->path1);
		else break;
	}	
	while(e->path2 != NULL){
		if(!edgevisit[e->path2->id])
			bfs(e->path2);
		else break;
	}
	
}

void Graph::non_recursive_dfs(int n){
	EdgeNode* e = vecnode[n].edge;
	stack<EdgeNode*> st;
	while(e != NULL){
		st.push(e);
		edgevisit[e->id] = 1;
		e = e->path1;
	}
	EdgeNode* tmp;
	while(!st.empty()){
		tmp = st.top();
		st.pop();
		
		if(tmp->path2 == NULL || edgevisit[tmp->path2->id]){
			cout << tmp->id << ' ' << tmp->StartVec << ' ' << tmp->EndVec << endl;
		}
		else{
			cout << tmp->id << ' ' << tmp->StartVec << ' ' << tmp->EndVec << endl;
			EdgeNode* t = tmp->path2;
			while(t != NULL){
				if(!edgevisit[t->id]){
					st.push(t);
					edgevisit[t->id] = 1;
				}
				t = t->path1;
				
			}
		}
	}
}
int main(){
	Graph graph(6);
	int a, b;
	for(int i = 0; i < 5; i++){
		cin >> a >> b;
	    EdgeNode* edgenode = new EdgeNode;
	    edgenode->id = i;
	    edgenode->StartVec = a;
	    edgenode->EndVec = b;
	    edgenode->path1 = edgenode->path2 = NULL;
	    
	    
	    if(graph.get_edge(a) != NULL){
	    	EdgeNode* tmp1;
	    	tmp1 = graph.get_edge(a);
	    	while(true){
	    		if(tmp1->StartVec == a){
	    			if(tmp1->path1 == NULL){
	    				tmp1->path1 = edgenode;
	    				break;
	    			}
	    			else tmp1 = tmp1->path1;
	    		}
	    		if(tmp1->EndVec == a){
	    			if(tmp1->path2 == NULL){
	    				tmp1->path2 = edgenode;
	    				break;
	    			}
	    			else tmp1 = tmp1->path2;
	    		}	
	    	}
	    }
	    else{
	    	graph.set_edge(a, edgenode);
	    }
	    
		if(graph.get_edge(b) != NULL){
			EdgeNode* tmp2;
	    	tmp2 = graph.get_edge(b);
			while(true){
				if(tmp2->StartVec == b){
					if(tmp2->path1 == NULL){
						tmp2->path1 = edgenode;
						break;
					}
					else tmp2 = tmp2->path1;
				}
				if(tmp2->EndVec == b){
					if(tmp2->path2 == NULL){
						tmp2->path2 = edgenode;
						break;
					}
					else tmp2 = tmp2->path2;
				}
			}
		}
		else{
			graph.set_edge(b, edgenode);
		}
		//cout << graph.get_edge(a) << ' ' << graph.get_edge(b) << endl;
	}
//	memset(edgevisit, 0, sizeof(edgevisit));
//	graph.non_recursive_dfs(0);
	graph.subscript_dfs(0);
	
}
