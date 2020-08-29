#include <stdio.h>
#include <stdlib.h>

struct Node{
	int vertex;
	struct Node* next;
};

struct Graph{
	int num_vertices;
	struct Node** adj_list;
};

int count=0;// count var to specify each vertex its label(no) 

//create a node 
struct Node* create_node(int v){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->vertex=v;
	new_node->next=NULL;
	return new_node;
}

//create a graph 
struct Graph* create_graph(int vertices){
	struct Graph* graph=malloc(sizeof(struct Graph));
	graph->num_vertices=vertices;
	graph->adj_list=malloc(vertices*sizeof(struct Node*));
	
	int i;
	for(i=0;i<vertices;i++){
		graph->adj_list[i]=NULL;
	}
	return graph;
}

//add edge 
void add_edge(struct Graph* graph,int s,int d){
	//adds edge from s to d 
	struct Node* new_node=create_node(d);
	new_node->next=graph->adj_list[s];
	graph->adj_list[s]=new_node;
	
	//adds edge from d to s 
	new_node=create_node(s);
	new_node->next=graph->adj_list[d];
	graph->adj_list[d]=new_node;
}

//print the graph 
void print_graph(struct Graph* graph){
	int v;
	for(v=0;v<graph->num_vertices;v++){
		struct Node* temp=graph->adj_list[v];
		printf("Vertex %d:\n",v);
		while(temp){
			printf("%d -> ",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}


//depth first algorithm 
void dfs(struct Graph* graph,int vertex_index,int* visited,int* components){
	if (visited[vertex_index]==1){
		return;
	}
	printf("Visited vertex %d\n",vertex_index);
	visited[vertex_index]=1;
	components[vertex_index]=count;
	
	
	//now search over its neigbours
	struct Node* temp=graph->adj_list[vertex_index];
	while(temp!=NULL){
		dfs(graph,temp->vertex,visited,components);
		temp=temp->next;
	}
	
}
	
//find the connected components
void find_components(struct Graph* graph,int *visited,int* components){
	int i;
	int n=graph->num_vertices;
	for(i=0;i<n;i++){
		if(visited[i]!=1){
			count++;
			dfs(graph,i,visited,components);
		}
	}
}

int main(){
	int i;
	struct Graph* graph=create_graph(4);//4 being the no of vertices
	int* visited=(int *)malloc(sizeof(int)*4); //visited array (dfs)
	int* components=(int *)malloc(sizeof(int)*4); //gives label to each vertex to which connected component they belong to 
	
	add_edge(graph,0,1);
// 	add_edge(graph,1,2);
	add_edge(graph,0,3);
	add_edge(graph,1,3);
	
//running the dfs 
//initialize the visited array as all false :0
	for(i=0;i<4;i++){
		visited[i]=0;
	}
		
	print_graph(graph);
	//start dfs at node 0
// 	dfs(graph,0,visited,components);
	find_components(graph,visited,components);
	
	
	for(i=0;i<4;i++){
		printf("Vertex %d in component %d\n",i,components[i]);
	}
	return 0;
}

	
	





